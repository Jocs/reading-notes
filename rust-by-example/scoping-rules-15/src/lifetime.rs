#[derive(Debug)]
struct Borrowed<'a> {
    x: &'a i32,
}

impl<'a> Default for Borrowed<'a> {
    fn default() -> Self {
        Self { x: &5 }
    }
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

pub fn main_execute() {
    let borrowed = Borrowed::default();

    println!("borrowed: {:?}", borrowed.x);

    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(&string1, string2);

    println!("The longest string is {}", result);
}
