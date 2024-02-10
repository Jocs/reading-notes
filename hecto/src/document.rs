use std::fs;
use std::io::{Error, Write};

use crate::{Row, SearchDirection};
use crate::Position;

#[derive(Default)]
pub struct Document {
    pub file_name: Option<String>,
    rows: Vec<Row>,
    dirty: bool,
}

impl Document {
    pub fn open(filename: &str) -> Result<Self, std::io::Error> {
        let mut rows = Vec::new();
        let content = fs::read_to_string(filename)?;

        for line in content.lines() {
            let mut row = Row::from(line);
            row.highlight();
            rows.push(row);
        }

        Ok(Self {
            rows,
            file_name: Some(filename.to_string()),
            dirty: false,
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
        let len = self.rows.len();
        let &Position { x, y } = at;

        if y > len {
            return;
        }

                // TODO: 有没有必要分别放到上面大括号呢？
                self.dirty = true;

        if c == '\n' {
            self.insert_newline(at);
            return;
        }

        if y == len {
            // handle add new row.
            let mut row = Row::default();
            row.insert(0, c);
            row.highlight();
            self.rows.push(row);
        } else {
            // 通过 get_mut 获取可变修改
            let row = &mut self.rows[at.y];
            row.insert(x, c);
            row.highlight();
        }
    }

    pub fn insert_newline(&mut self, at: &Position) {
        let len = self.len();
        let &Position { x, y } = at;
        if y > len {
            return;
        }

        self.dirty = true;

        if y == len {
            self.rows.push(Row::default());
            return;
        }

        let current_row = &mut self.rows[y];
        let mut new_row = current_row.split(x);
        current_row.highlight();
        new_row.highlight();

        self.rows.insert(y + 1, new_row);
    }

    // delete 光标位置不变
    pub fn delete(&mut self, at: &Position) {
        let len = self.len();
        let &Position { x, y } = at;

        if y >= len {
            return;
        }

        if x == self.rows.get_mut(y).unwrap().len() && y + 1 < len {
            let next_row = self.rows.remove(y + 1);
            if let Some(row) = self.rows.get_mut(y) {
                row.append(&next_row);
                row.highlight();
            }
        } else {
            if let Some(row) = self.rows.get_mut(y) {
                row.delete(x);
                row.highlight();
            }
        }

        self.dirty = true;
    }

    // 保存文件 save to disk.
    pub fn save(&mut self) -> Result<(), Error> {
        if let Some(file_name) = &self.file_name {
            let mut file = fs::File::create(file_name)?;

            for row in &self.rows {
                file.write_all(row.as_bytes())?;
                file.write_all(b"\n")?;
            }

            self.dirty = true;
        }

        Ok(())
    }

    pub fn is_dirty(&self) -> bool {
        self.dirty
    }

    pub fn find(&self, query: &str, at: &Position, direction: SearchDirection) -> Option<Position> {
        if at.y > self.rows.len() {
            return None;
        }

        let mut position = Position { x: at.x, y: at.y };

        let start = if direction == SearchDirection::Forward {
            at.y
        } else {
            0
        };

        let end = if direction == SearchDirection::Forward {
            self.rows.len()
        } else {
            at.y.saturating_add(1)
        };

        for _ in start..end {
            if let Some(row) = self.rows.get(position.y) {
                if let Some(x) = row.find(&query, position.x, direction) {
                    position.x = x;
                    return Some(position);
                }

                if direction == SearchDirection::Forward {
                    position.y = position.y.saturating_add(1);
                    position.x = 0;
                } else {
                    position.y = position.y.saturating_sub(1);
                    position.x = self.rows[position.y].len();
                }
            } else {
                return None;
            }
        }

        None
    }
}