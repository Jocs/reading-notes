use std::convert::From;

#[allow(dead_code)]
#[derive(Debug)]
struct Number {
    value: i32,
}

impl From<i32> for Number {
    fn from(value: i32) -> Self {
        Number {
            value,
        }
    }
}

fn main() {
    println!("Hello, world!");
    let number = Number::from(32);

    println!("The number is {:?}", number);

    let int = 43;
    let number_2: Number = int.into();

    println!("Number 2 is {:?}", number_2);

    let number_3 = "123".parse::<i32>().unwrap();
    println!("Number 3 is {}", number_3);
}
