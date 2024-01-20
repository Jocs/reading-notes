use std::io::{self, ErrorKind};
use std::io::Read;
use std::fs::File;

fn main() {
    println!("Hello, world!");

    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Error: {}", e),
            },
            other_error => panic!("Error: {}", other_error),
        },
    };

    let mut s = String::new();

    f.read_to_string(&mut s).unwrap();

    println!("The file strings: {}", s);

    use_unwrap();

    use_expect();

    let name = read_username_from_file().unwrap();

    println!("The username is {}", name);

    let name = read_username_from_file_2().unwrap();

    println!("The second version username is {}", name);
}

fn use_unwrap() {
    let _f = File::open("hello.txt").unwrap();
}

fn use_expect() {
    let _f = File::open("hello.txt").expect("Failed to open not_exist.txt");
}

fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn read_username_from_file_2() -> Result<String, io::Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();

    f.read_to_string(&mut s)?;

    Ok(s)
}
