use std::cmp;
use termion::color;
use unicode_segmentation::UnicodeSegmentation;

use crate::{highlighting, HighlightingOptions, SearchDirection};

#[derive(Default)]
pub struct Row {
    pub string: String,
    highlighting: Vec<highlighting::Type>,
    len: usize,
}

impl From<&str> for Row {
    fn from(slice: &str) -> Self {
        Self {
            string: slice.to_string(),
            highlighting: Vec::new(),
            len: slice.graphemes(true).count(),
        }
    }
}

impl Row {
    pub fn render(&self, start: usize, end: usize) -> String {
        let len = self.string.len();
        let end = cmp::min(end, len);
        let start = cmp::min(start, end);
        let mut result = String::new();

        let mut current_highlighting = &highlighting::Type::None;

        for (index, grapheme) in self.string[..]
            .graphemes(true)
            .enumerate()
            .skip(start)
            .take(end - start)
        {
            if let Some(c) = grapheme.chars().next() {
                let highlighting_type = self
                    .highlighting
                    .get(index)
                    .unwrap_or(&highlighting::Type::None);

                if highlighting_type != current_highlighting {
                    current_highlighting = highlighting_type;
                    let start_highlight = format!("{}", color::Fg(highlighting_type.to_color()));
                    result.push_str(&start_highlight[..]);
                }

                if c == '\t' {
                    result.push(' ');
                } else {
                    result.push(c);
                }
            }
        }

        let end_highlight = format!("{}", color::Fg(color::Reset));
        result.push_str(&end_highlight[..]);

        result
    }

    pub fn insert(&mut self, at: usize, c: char) {
        // 如果光标已经在行尾，直接在行尾插入字符
        if at >= self.len {
            self.string.push(c);
            self.len += 1;

            return;
        }

        let mut result = String::new();
        let mut length = 0;

        for (index, grapheme) in self.string[..].graphemes(true).enumerate() {
            length += 1;
            if index == at {
                length += 1;
                result.push(c);
            }
            result.push_str(grapheme);
        }

        self.len = length;
        self.string = result;
    }

    // 删除指定位置上的字符
    pub fn delete(&mut self, at: usize) {
        if at >= self.len {
            return;
        }

        let mut result = String::new();
        let mut length = 0;

        for (index, grapheme) in self.string[..].graphemes(true).enumerate() {
            if index != at {
                result.push_str(grapheme);
                length += 1;
            }
        }

        self.string = result;
        self.len = length;
    }

    pub fn append(&mut self, other: &Self) {
        self.string.push_str(&other.string);

        self.update_len();
    }

    pub fn split(&mut self, at: usize) -> Self {
        let mut row = String::new();
        let mut length = 0;
        let mut new_row = String::new();
        let mut new_length = 0;

        for (index, grapheme) in self.string[..].graphemes(true).enumerate() {
            if index < at {
                row.push_str(grapheme);
                length += 1;
            } else {
                new_row.push_str(grapheme);
                new_length += 1;
            }
        }

        self.string = row;
        self.len = length;

        Self {
            string: new_row,
            highlighting: Vec::new(),
            len: new_length,
        }
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn is_empty(&self) -> bool {
        self.len == 0
    }

    pub fn as_bytes(&self) -> &[u8] {
        self.string.as_bytes()
    }

    fn update_len(&mut self) {
        self.len = self.string[..].graphemes(true).count()
    }

    pub fn find(&self, query: &str, at: usize, direction: SearchDirection) -> Option<usize> {
        if at > self.len || query.is_empty() {
            return None;
        }

        let start = if direction == SearchDirection::Forward {
            at
        } else {
            0
        };

        let end = if direction == SearchDirection::Forward {
            self.len
        } else {
            at
        };

        let substring: String = self.string[..]
            .graphemes(true)
            .skip(start)
            .take(end - start)
            .collect();

        let matching_byte_index = if direction == SearchDirection::Forward {
            substring.find(query)
        } else {
            substring.rfind(query)
        };
        if let Some(match_byte_index) = matching_byte_index {
            for (grapheme_index, (byte_index, _)) in
                substring[..].grapheme_indices(true).enumerate()
            {
                if match_byte_index == byte_index {
                    return Some(start + grapheme_index);
                }
            }
        }

        None
    }

    fn highlight_comment(
        &mut self,
        index: &mut usize,
        opts: HighlightingOptions,
        c: char,
        chars: &[char],
    ) -> bool {
        if opts.comments() && c == '/' && *index < chars.len() {
            if let Some(next_char) = chars.get(index.saturating_add(1)) {
                if *next_char == '/' {
                    for _ in *index..self.len() {
                        self.highlighting.push(highlighting::Type::Comment);
                        *index += 1;
                    }
                    return true;
                }
            }
        }

        false
    }

    fn highlight_char(
        &mut self,
        index: &mut usize,
        opts: HighlightingOptions,
        c: char,
        chars: &[char],
    ) -> bool {
        if opts.characters() && c == '\'' {
            if let Some(next_char) = chars.get(index.saturating_add(1)) {
                let closing_index = if *next_char == '\\' {
                    index.saturating_add(3)
                } else {
                    index.saturating_add(2)
                };

                if let Some(closing_char) = chars.get(closing_index) {
                    if *closing_char == '\'' {
                        for _ in 0..closing_index.saturating_sub(*index) {
                            self.highlighting.push(highlighting::Type::Character);
                            *index += 1;
                        }

                        return true;
                    }
                }
            }
        }

        false
    }

    fn highlight_string(
        &mut self,
        index: &mut usize,
        opts: HighlightingOptions,
        c: char,
        chars: &[char],
    ) -> bool {
        if opts.strings() && c == '"' {
            loop {
                self.highlighting.push(highlighting::Type::String);
                *index += 1;
                if let Some(next_char) = chars.get(*index) {
                    if *next_char == '"' {
                        break;
                    }
                } else {
                    break;
                }
            }

            self.highlighting.push(highlighting::Type::String);
            *index += 1;
            return true;
        }

        false
    }

    fn highlight_number(
        &mut self,
        index: &mut usize,
        opts: HighlightingOptions,
        c: char,
        chars: &[char],
    ) -> bool {
        if opts.numbers() && c.is_ascii_digit() {
            if *index > 0 {
                let prev_char = chars[*index - 1];
                if !prev_char.is_ascii_punctuation() && !prev_char.is_ascii_whitespace() {
                    return false;
                }
            }

            loop {
                self.highlighting.push(highlighting::Type::Number);
                *index += 1;
                if let Some(next_char) = chars.get(*index) {
                    if *next_char != '.' && !next_char.is_ascii_digit() {
                        break;
                    }
                } else {
                    break;
                }
            }

            return true;
        }

        false
    }

    fn highlight_match(&mut self, word: Option<&str>) {
        if let Some(word) = word {
            if word.is_empty() {
                return;
            }

            let mut index = 0;
            while let Some(search_match) = self.find(word, index, SearchDirection::Forward) {
                if let Some(next_index) = search_match.checked_add(word[..].graphemes(true).count())
                {
                    for i in index.saturating_add(search_match)..next_index {
                        self.highlighting[i] = highlighting::Type::Match;
                    }
                    index = next_index;
                } else {
                    break;
                }
            }
        }
    }

    pub fn highlight(&mut self, opts: HighlightingOptions, word: Option<&str>) {
        self.highlighting = Vec::new();
        let chars: Vec<char> = self.string.chars().collect();
        let mut index = 0;

        while let Some(c) = chars.get(index) {
            if self.highlight_char(&mut index, opts, *c, &chars)
                || self.highlight_comment(&mut index, opts, *c, &chars)
                || self.highlight_string(&mut index, opts, *c, &chars)
                || self.highlight_number(&mut index, opts, *c, &chars)
            {
                continue;
            }
            self.highlighting.push(highlighting::Type::None);
            index += 1;
        }

        self.highlight_match(word);
    }
}
