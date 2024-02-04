use std::cmp;
use unicode_segmentation::UnicodeSegmentation;

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
