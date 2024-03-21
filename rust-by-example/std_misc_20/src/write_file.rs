use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

pub fn main_exec() {
    let path = Path::new("test.txt");

    let mut file = match File::create(&path) {
        Err(why) => panic!("couldn't create {}: {}", path.display(), why),
        Ok(file) => file,
    };

    let mut s = String::new();
    s.push_str("Hello, world!\nHello Rust!");
    match file.write_all(s.as_bytes()) {
        Err(why) => panic!("couldn't write {}: {}", path.display(), why),
        Ok(_) => println!("successfully wrote to {}", path.display()),
    }
}