mod editor;
mod terminal;
mod row;
mod document;
mod highlighting;

use editor::Editor;
pub use terminal::Terminal;
pub use editor::Position;
pub use editor::SearchDirection;
pub use row::Row;
pub use document::Document;


fn main() {
    Editor::new().run();
}
