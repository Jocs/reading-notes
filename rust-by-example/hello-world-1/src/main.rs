use colored::*;
use std::fmt;

#[allow(dead_code)]
#[derive(Debug)]
struct Person<'a> {
    name: &'a str,
    age: i32,
}

#[allow(dead_code)]
#[derive(Debug)]
struct Pointer2D {
    x: i32,
    y: i32,
}

impl fmt::Display for Pointer2D {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Pointer2D: [x = {}, y = {}]", self.x, self.y)
    }
}

#[allow(dead_code)]
#[derive(Debug)]
struct List(Vec<i32>);

impl fmt::Display for List {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let list = &self.0;

        write!(f, "[")?;

        for (i, item) in list.iter().enumerate() {
            if i != 0 {
                write!(f, ", ")?;
            }

            write!(f, "{i}: {item}", i = i, item = item)?;
        }

        write!(f, "]")
    }
}
#[allow(dead_code)]
#[derive(Debug)]
struct Color {
    red: u8,
    green: u8,
    blue: u8,
}

/**
 * RGB (128, 255, 90) 0x80FF5A
 * RGB (0, 3, 254) 0x0003FE
 * RGB (0, 0, 0) 0x000000
 */
impl fmt::Display for Color {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "RGB ({}, {}, {}) Ox{:02X}{:02X}{:02X}", &self.red, &self.green, &self.blue, &self.red, &self.green, &self.blue)
    }
}

fn main() {
    println!("Hello, world!");

    println!("{} days", 31);

    println!("{0}, {1}, {1}, {0}", "hello", "world");

    // 可以使用命名参数，中间也可以使用换行符
    println!(
        "title: {title}\nauthor: {author}",
        title = "飞驰人生2",
        author = "韩寒"
    );

    // 可以在 ':' 后面定制特殊格式
    println!(
        "{} of {:b} peoples know binary, the other half doesn't",
        1, 2
    );

    // 指定宽度
    println!("{number:>width$}", number = 1, width = 6);
    println!("{number:>0width$}", number = 1, width = 6);

    #[allow(dead_code)]
    #[derive(Debug)]
    struct Structure(i32);

    println!("Structure: {:?}", Structure(3));

    let pi = 3.141592;

    println!("Pi is roughly {:.3}", pi);

    println!(
        "The color is {}, and this is {}",
        "red".on_bright_blue().bright_red(),
        "green and bold".green().bold().underline().italic().blink()
    );

    let name = String::from("Jocs");
    let age = 35;

    let me = Person { name: &name, age };

    println!("{:#?}", me);

    let pointer = Pointer2D { x: 12, y: 3 };

    println!("pointer by Format: {}", pointer);
    println!("pointer by Debug: {:#?}", pointer);

    // [0: 1, 1: 2, 2: 3]
    let list = List(vec![1, 2, 3, 4, 6, 7]);

    println!("{}", list);

    let color = Color {red: 0, green: 0, blue: 0};

    println!("The color is {}", color);
}
