#![warn(clippy::all, clippy::pedantic, clippy::restriction)]
#![allow(
    clippy::missing_docs_in_private_items,
    clippy::implicit_return,
    clippy::shadow_reuse,
    clippy::print_stdout,
    clippy::wildcard_enum_match_arm,
    clippy::else_if_without_else
)]
use std::env;
use std::time::Duration;
use std::time::Instant;
use std::io::{self, Write};
use termion::event::Key;
use termion::color;

use crate::Terminal;
use crate::Document;
use crate::Row;

const VERSION: &str = env!("CARGO_PKG_VERSION");
const STATUS_BG_COLOR: color::Rgb = color::Rgb(239, 239, 239);
const STATUS_FG_COLOR: color::Rgb = color::Rgb(30, 30, 30);
const QUIT_TIMES: u8 = 3;

struct StatusMessage {
    text: String,
    time: Instant,
}

impl StatusMessage {
    fn from(message: String) -> Self {
        Self {
            text: message,
            time: Instant::now(),
        }
    }
}

#[derive(Default)]
pub struct Position {
    pub x: usize,
    pub y: usize,
}

pub struct Editor {
    should_quit: bool,
    terminal: Terminal,
    cursor_position: Position,
    document: Document,
    offsets: Position,
    status_message: StatusMessage,
    quit_times: u8,
}

impl Editor {
    pub fn new() -> Self {
        let args: Vec<String> = env::args().collect();
        let mut initial_status = "HELP: Ctrl-F = find | Ctrl-S = save | Ctrl-Q = quit".to_string();
        let document = if let Some(file_name) = args.get(1) {
            let doc = Document::open(&file_name);
            if let Ok(doc) = doc {
                doc
            } else {
                initial_status = format!("Error: Could not open file {file_name}");
                Document::default()
            }
        } else {
            Document::default()
        };

        Self {
            should_quit: false,
            terminal: Terminal::new().unwrap(),
            cursor_position: Position::default(),
            document,
            offsets: Position::default(),
            status_message: StatusMessage::from(initial_status),
            quit_times: QUIT_TIMES,
        }
    }

    pub fn run(&mut self) {
        loop {
            if let Err(error) = self.refresh_screen() {
                die(&error);
            }

            if self.should_quit {
                break;
            }

            if let Err(error) = self.process_keypress() {
                die(&error);
            }
        }
    }

    fn process_keypress(&mut self) -> Result<(), std::io::Error> {
        let pressed_key = Terminal::read_key()?;

        match pressed_key {
            Key::Ctrl('q') => {
                if self.quit_times > 0 && self.document.is_dirty() {
                    self.status_message = StatusMessage::from(format!("WARNING: file has unsaved changes. Please Ctrl-Q {} more times qu quit.", self.quit_times));
                    self.quit_times -= 1;
                    return Ok(());
                }
                self.should_quit = true;
            },
            Key::Ctrl('s') => self.save(),
            Key::Char(c) => {
                self.document.insert(&self.cursor_position, c);
                self.move_cursor(Key::Right);
            },
            Key::Delete => {
                // Delete no need to move cursor.
                self.document.delete(&self.cursor_position);
            },
            Key::Backspace => {
                if self.cursor_position.x > 0 || self.cursor_position.y > 0 {
                    self.move_cursor(Key::Left);
                    self.document.delete(&self.cursor_position);
                }
            },
            Key::Up
            | Key::Down
            | Key::Left
            | Key::Right
            | Key::PageUp
            | Key::PageDown
            | Key::Home
            | Key::End => self.move_cursor(pressed_key),
            _ => (),
        }

        self.scroll();

        if self.quit_times < QUIT_TIMES {
            self.quit_times = QUIT_TIMES;
            self.status_message = StatusMessage::from(String::new());
        }

        Ok(())
    }

    // save and save as.
    fn save(&mut self) {
        // 如果文件名不存在，提示用户输入文件名，然后保存
        if self.document.file_name.is_none() {
            let new_name = self.prompt("Save as: ").unwrap_or(None);
            if new_name.is_none() {
                self.status_message = StatusMessage::from("Save abort".to_string());
                return;
            }

            self.document.file_name = new_name;
        }

        if self.document.save().is_ok() {
            self.status_message = StatusMessage::from(format!("File saved successfully"));
        } else {
            self.status_message = StatusMessage::from("File save failed".to_string());
        }
    }

    fn prompt(&mut self, prompt: &str) -> Result<Option<String>, std::io::Error> {
        let mut result = String::new();

        loop {
            self.status_message = StatusMessage::from(format!("{prompt}{result}"));
            self.refresh_screen()?;

            match Terminal::read_key()? {
                Key::Backspace => result.truncate(result.len().saturating_sub(1)),
                Key::Char('\n') => break,
                Key::Char(c) => {
                    if !c.is_control() {
                        result.push(c);
                    }
                },
                Key::Esc => {
                    result.truncate(0);
                    break;
                },
                _ => (),
            }  
        }

        self.status_message = StatusMessage::from(String::new());

        if result.is_empty() {
            return Ok(None);
        }

        Ok(Some(result))
    }

    fn scroll(&mut self) {
        let Position { x, y } = self.cursor_position;
        let offset = &mut self.offsets;
        let width = self.terminal.size().width as usize;
        let height = self.terminal.size().height as usize;

        if y < offset.y {
            offset.y = y;
        } else if y >= offset.y.saturating_add(height) {
            offset.y = y.saturating_sub(height).saturating_add(1);
        }

        if x < offset.x {
            offset.x = x;
        } else if x >= offset.x.saturating_add(width) {
            offset.x = x.saturating_sub(width).saturating_add(1);
        }
    }

    fn refresh_screen(&self) -> Result<(), std::io::Error> {
        Terminal::cursor_hide();
        Terminal::go_to(&Position::default());
        if self.should_quit {
            Terminal::clear_screen();
            println!("Goodbye.\r");
        } else {
            self.draw_rows();
            self.draw_status_bar();
            self.draw_message_bar();
            Terminal::go_to(&Position {
                x: self.cursor_position.x - self.offsets.x,
                y: self.cursor_position.y - self.offsets.y,
            });
        }
        Terminal::cursor_show();
        io::stdout().flush()
    }

    fn draw_row(&self, row: &Row) {
        let start: usize = self.offsets.x;
        let width = self.terminal.size().width as usize;
        let row_content = row.render(start, start + width);

        println!("{}\r", row_content);
    }

    fn draw_rows(&self) {
        let size = self.terminal.size();
        let height = size.height as usize;

        for terminal_row in 0..height {
            Terminal::clear_current_line();

            if let Some(row) = self.document.row(terminal_row + self.offsets.y) {
                self.draw_row(&row);
            } else if self.document.is_empty() && terminal_row == height / 3 {
                self.draw_welcome_message();
            } else {
                println!("~\r");
            }
        }
    }

    fn draw_status_bar(&self) {
        let mut status: String;
        let width = self.terminal.size().width as usize;
        let mut file_name = "[No Name]".to_string();
        let modified_indicator = if self.document.is_dirty() {
            " (modified)"
        } else {
            ""
        };

        if let Some(name) = &self.document.file_name {
            file_name = name.clone();
            file_name.truncate(20);
        }

        status = format!("{} - {} lines{}", file_name, self.document.len(), modified_indicator);

        let line_indicator = format!("{}/{}", self.cursor_position.y + 1, self.document.len());

        let len = status.len() + line_indicator.len();

        if width > len {
            status = format!("{}{}", status, " ".repeat(width - len));
        }

        status = format!("{status}{line_indicator}");

        Terminal::set_bg_color(STATUS_BG_COLOR);
        Terminal::set_fg_color(STATUS_FG_COLOR);
        println!("{}\r", status);
        Terminal::reset_bg_color();
        Terminal::reset_fg_color();
    }

    fn draw_message_bar(&self) {
        Terminal::clear_current_line();
        let message = &self.status_message;
        if Instant::now() - message.time < Duration::from_secs(5) {
            let mut text = message.text.clone();
            text.truncate(self.terminal.size().width as usize);
            print!("{}", text);
        }
    }

    fn draw_welcome_message(&self) {
        let mut welcome_message = format!("Hecto editor -- version {VERSION}");
        let padding = (self.terminal.size().width - welcome_message.len() as u16) / 2;
        let spaces = " ".repeat(padding.saturating_sub(1) as usize);

        welcome_message = format!("~{spaces}{welcome_message}");
        welcome_message.truncate(self.terminal.size().width as usize);

        println!("{welcome_message}\r");
    }

    // 根据 key 值来移动光标位置，包括 Key::Left, Key::Right, Key::Up, Key::Down, Key::Home, Key::End 等
    fn move_cursor(&mut self, key: Key) {
        let Position { mut x, mut y } = self.cursor_position;
        let terminal_height = self.terminal.size().height as usize;
        // 获取光标所在行的长度，如果没有文本则为 0
        let mut width = if let Some(row) = self.document.row(y) {
            row.len()
        } else {
            0
        };
        // 光标只能在文本内移动或者超出一个光标位置，所以 y 最大值为 document.len()，x 最大值为 width
        let height = self.document.len();

        match key {
            Key::Left => {
                if x > 0 {
                    x -= 1;
                } else if y > 0 {
                    y = y - 1;
                    width = if let Some(row) = self.document.row(y) {
                        // row.len 是私有属性，不能直接访问
                        row.len()
                    } else {
                        0
                    };
                    // 将光标移动到上一行行尾，并且等于 row.len()
                    x = width;
                }
            },

            Key::Right => {
                if x < width {
                    x += 1;
                } else if y < height {
                    y += 1;
                    x = 0;
                }
            }

            Key::Up => y = y.saturating_sub(1),

            Key::Down => {
                if y < height {
                    y = y.saturating_add(1);
                }
            }

            Key::Home => x = 0,

            Key::End => x = width,

            Key::PageUp => {
                y = if y > terminal_height {
                    y.saturating_sub(terminal_height)
                } else {
                    0
                };
            },

            Key::PageDown => {
                y = if y.saturating_add(terminal_height) < height {
                    y + terminal_height
                } else {
                    height
                }
            },
            _ => (),
        }

        // 光标移动后，需要检查是否超出行的长度，超出则将光标移动到行的末尾
        width = if let Some(row) = self.document.row(y) {
            row.len()
        } else {
            0
        };

        if x > width {
            x = width;
        }

        self.cursor_position = Position { x, y };
    }
}

fn die(e: &std::io::Error) {
    Terminal::clear_screen();
    panic!("Error: {e}");
}
