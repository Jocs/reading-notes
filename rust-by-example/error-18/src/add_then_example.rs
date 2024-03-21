#![allow(dead_code)]

#[derive(Debug)]
enum Food {
    Apple,
    Orange,
    Potato,
}

fn food_to_number(food: Food) -> Option<u8> {
    match food {
        Food::Apple => Some(1),
        Food::Orange => Some(2),
        Food::Potato => None,
    }
}

fn number_to_string(number: u8) -> Option<&'static str> {
    match number {
        1 => Some("apple"),
        2 => Some("orange"),
        _ => None,
    }
}

fn process(food: Food) -> Option<&'static str> {
    food_to_number(food).and_then(number_to_string)
}

pub fn main_exec() {
    let food = Food::Apple;
    let result = process(food);

    println!("{:?}", result);
}