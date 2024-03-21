use std::path::Path;

pub fn main_exec() {
    let path = Path::new(".");

    let new_path = path.join("new_path").join("new_file.txt");

    match new_path.to_str() {
        Some(s) => println!("{}", s),
        None => println!("Invalid path"),
    }
}