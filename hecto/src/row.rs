use std::cmp;
use unicode_segmentation::UnicodeSegmentation;

#[derive(Default)]
pub struct Row {
    pub string: String,
    len: usize,
}

impl From<&str> for Row {
    fn from(string: &str) -> Self {
        let mut row = Self {
            string: string.to_string(),
            len: 0,
        };

        row.update_len();
        row
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
                result.push_str(" ");
                continue;
            }

            result.push_str(grapheme);
        }

        result
    }

    pub fn insert(&mut self, at: usize, c: char) {
        if at >= self.len {
            self.string.push(c);
        } else {
            let mut result: String = self.string[..].graphemes(true).take(at).collect();
            let remain: String = self.string[..].graphemes(true).skip(at).collect();

            result.push(c);

            result.push_str(&remain);

            self.string = result;
        }

        self.update_len();
    }

    pub fn delete(&mut self, at: usize) {
        if at >= self.len {
            return;
        }

        let mut result: String = self.string[..].graphemes(true).take(at).collect();
        let remain: String = self.string[..].graphemes(true).skip(at + 1).collect();

        if remain.len() > 0 {
            result.push_str(&remain);
        }

        self.string = result;
        self.update_len();
    }

    pub fn append(&mut self, other: &Self) {
        self.string.push_str(&other.string);

        self.update_len();
    }

    pub fn split(&mut self, at: usize) -> Self {
        let result: String = self.string[..].graphemes(true).take(at).collect();
        let remain: String = self.string[..].graphemes(true).skip(at + 1).collect();

        self.string = result;
        self.update_len();

        Self::from(remain.as_str())
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn update_len(&mut self) {
        self.len = self.string[..].graphemes(true).count()
    }
}