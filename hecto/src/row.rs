use std::cmp;
use unicode_segmentation::UnicodeSegmentation;

#[derive(Default)]
pub struct Row {
    pub string: String,
    len: usize,
}

impl From<&str> for Row {
    fn from(slice: &str) -> Self {
        Self {
            string: slice.to_string(),
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
        for grapheme in self.string[..]
            .graphemes(true)
            .skip(start)
            .take(end - start)
        {
            if grapheme == "\t" {
                result.push(' ');
                continue;
            }

            result.push_str(grapheme);
        }

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
}
