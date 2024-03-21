use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

pub fn main_exec() {
    let path = Path::new("Cargo.toml");

    let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", path.display(), why),
        Ok(file) => file,
    };

    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(why) => panic!("couldn't read {}: {}", path.display(), why),
        Ok(_) => print!("{} contains:\n{}\n", path.display(), s),
    }
}