mod editor;
mod terminal;
mod row;
mod document;

use editor::Editor;
pub use terminal::Terminal;
pub use editor::Position;
pub use row::Row;
pub use document::Document;


fn main() {
    Editor::new().run();
}
