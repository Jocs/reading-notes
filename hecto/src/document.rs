use std::fs;

use crate::Row;

#[derive(Default)]
pub struct Document {
    rows: Vec<Row>,
    pub file_name: Option<String>,
}

impl Document {
    pub fn open(filename: &str) -> Result<Self, std::io::Error> {
        let mut rows = Vec::new();
        let content = fs::read_to_string(filename)?;

        for line in content.lines() {
            rows.push(Row::from(line));
        }

        Ok(Self {
            rows,
            file_name: Some(filename.to_string()),
        })
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