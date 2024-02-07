use std::fs;
use std::io::{Error, Write};

use crate::Row;
use crate::Position;

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

    pub fn insert(&mut self, at: &Position, c: char) {
        let len = self.len();
        let &Position { x, y } = at;

        if c == '\n' {
            self.break_line(at);
            return;
        }

        if y >= len {
            // handle add new row.
            let content = c.to_string();
            let new_row = Row::from(content.as_str());
            self.rows.push(new_row);
        } else {
            // 通过 get_mut 获取可变修改
            if let Some(row) = self.rows.get_mut(y) {
                row.insert(x, c);
            };
        }
    }

    pub fn break_line(&mut self, at: &Position) {
        let len = self.len();
        let &Position { x, y } = at;
        if y > len {
            return;
        }

        if y == len {
            self.rows.push(Row::default());
            return;
        }

        if let Some(row) = self.rows.get_mut(y) {
            let new_row = row.split(x);
            self.rows.insert(y + 1, new_row);
        }
    }

    // delete 光标位置不变，
    pub fn delete(&mut self, at: &Position) {
        let len = self.len();
        let &Position { x, y } = at;

        if y >= len {
            return;
        }

        if x == self.rows.get_mut(y).unwrap().len() && y < self.len() - 1 {
            let next_row = self.rows.remove(y + 1);
            if let Some(row) = self.rows.get_mut(y) {
                row.append(&next_row);
            }
        } else {
            if let Some(row) = self.rows.get_mut(y) {
                row.delete(x);
            }
        }
    }

    // 保存文件 save to disk.
    pub fn save(&self) -> Result<(), Error> {
        if let Some(file_name) = &self.file_name {
            let mut file = fs::File::create(file_name)?;

            for row in &self.rows {
                file.write_all(row.as_bytes())?;
                file.write_all(b"\n")?;
            }
        }

        Ok(())
    }
}