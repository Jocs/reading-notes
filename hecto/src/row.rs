use std::cmp;

pub struct Row {
    pub string: String,
}

impl From<&str> for Row {
    fn from(string: &str) -> Self {
        Self {
            string: string.to_string(),
        }
    }
}

impl Row {
    pub fn render(&self, start: usize, end: usize) -> String {
        let len = self.string.len();
        let end = cmp::min(end, len);
        let start = cmp::min(start, end);

        self.string[start..end].to_string()
    }

    pub fn len(&self) -> usize {
        self.string.len()
    }

    pub fn is_empty(&self) -> bool {
        self.string.is_empty()
    }
}
