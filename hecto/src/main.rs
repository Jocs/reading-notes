mod editor;
mod terminal;
mod row;
mod document;
mod highlighting;
mod filetype;

use editor::Editor;
pub use terminal::Terminal;
pub use editor::Position;
pub use editor::SearchDirection;
pub use row::Row;
pub use document::Document;
pub use filetype::FileType;
pub use filetype::HighlightingOptions;


fn main() {
    Editor::new().run();
}
