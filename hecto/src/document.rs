use std::fs;

use crate::Row;

#[derive(Default)]
pub struct Document {
    rows: Vec<Row>,
}

impl Document {
    pub fn open(filename: &str) -> Self {
        let mut rows = Vec::new();
        let content = fs::read_to_string(filename).unwrap();

        for line in content.lines() {
            rows.push(Row::from(line));
        }

        Self { rows }
    }

    pub fn row(&self, row_index: usize) -> Option<&Row> {
        self.rows.get(row_index)
    }

    pub fn len(&self) -> usize {
        self.rows.len()
    }

    pub fn is_empty(&self) -> bool {
        self.rows.is_empty()
    }
}