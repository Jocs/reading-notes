use std::cmp;
use termion::color;
use unicode_segmentation::UnicodeSegmentation;

use crate::{highlighting, SearchDirection};

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

    pub fn highlight(&mut self, word: Option<&str>) {
        let mut highlighting = Vec::new();
        let chars: Vec<char> = self.string.chars().collect();
        let mut matches = Vec::new();
        let mut search_index = 0;

        if let Some(word) = word {
            while let Some(search_match) = self.find(word, search_index, SearchDirection::Forward) {
                matches.push(search_match);
                if let Some(next_index) = search_match.checked_add(word[..].graphemes(true).count())
                {
                    search_index = next_index;
                } else {
                    break;
                }
            }
        }

        let mut index = 0;

        while let Some(c) = chars.get(index) {
            if let Some(word) = word {
                if matches.contains(&index) {
                    for _ in word[..].graphemes(true) {
                        index += 1;
                        highlighting.push(highlighting::Type::Match);
                    }
                    continue;
                }
            }

            if c.is_ascii_digit() {
                highlighting.push(highlighting::Type::Number);
            } else {
                highlighting.push(highlighting::Type::None);
            }
            index += 1;
        }

        self.highlighting = highlighting;
    }
}
