#![warn(clippy::all, clippy::pedantic)]
use std::env;
use std::io::{self, Write};
use termion::event::Key;

use crate::Terminal;
use crate::Document;
use crate::Row;

const VERSION: &str = env!("CARGO_PKG_VERSION");

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
}

impl Editor {
    pub fn new() -> Self {
        let args: Vec<String> = env::args().collect();
        let document = if args.len() > 1 {
            Document::open(args[1].as_str())
        } else {
            Document::default()
        };

        Self {
            should_quit: false,
            terminal: Terminal::new().unwrap(),
            cursor_position: Position::default(),
            document,
            offsets: Position::default(),
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
            Key::Ctrl('q') => self.should_quit = true,
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

        Ok(())
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

        for terminal_row in 0..height - 1 {
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

    fn draw_welcome_message(&self) {
        let mut welcome_message = format!("Hecto editor -- version {}", VERSION);
        let padding = (self.terminal.size().width - welcome_message.len() as u16) / 2;
        let spaces = " ".repeat(padding.saturating_sub(1) as usize);
        welcome_message = format!("~{}{}", spaces, welcome_message);
        welcome_message.truncate(self.terminal.size().width as usize);

        println!("{}\r", welcome_message);
    }

    fn move_cursor(&mut self, key: Key) {
        let Position { mut x, mut y } = self.cursor_position;
        let mut width = if let Some(row) = self.document.row(y) {
            row.len()
        } else {
            0
        };
        let height = self.document.len();

        match key {
            Key::Left => x = x.saturating_sub(1),
            Key::Right => {
                if x < width - 1 {
                    x = x.saturating_add(1);
                }
            }
            Key::Up => y = y.saturating_sub(1),
            Key::Down => {
                if y < height - 1 {
                    y = y.saturating_add(1);
                }
            }
            Key::Home => x = 0,
            Key::End => x = width - 1,
            Key::PageUp => y = 0,
            Key::PageDown => y = height - 1,
            _ => (),
        }

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
