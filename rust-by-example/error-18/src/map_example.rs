#![allow(dead_code)]

#[derive(Debug)]
enum Food {
    Apple,
    Orange,
    Potato,
}

#[derive(Debug)]
struct Peeled(Food);

#[derive(Debug)]
struct Chopped(Peeled);

#[derive(Debug)]
struct Cooked(Chopped);

fn peel_food(food: Option<Food>) -> Option<Peeled> {
    if let Some(f) = food {
        Some(Peeled(f))
    } else {
        None
    }
}

fn chop_food(food: Option<Peeled>) -> Option<Chopped> {
    if let Some(f) = food {
        Some(Chopped(f))
    } else {
        None
    }
}

fn cook_food(food: Option<Chopped>) -> Option<Cooked> {
    if let Some(f) = food {
        Some(Cooked(f))
    } else {
        None
    }
}

fn process(food: Option<Food>) -> Option<Cooked> {
    food.map(|f| Peeled(f)).map(|p| Chopped(p)).map(|c| Cooked(c))
}

fn eat(food: Option<Cooked>) {
    match food {
        Some(f) => println!("Yum! {:?}", f),
        None => println!("Ugh!"),
    }
}

pub fn main_exec() {
    let apple = Some(Food::Apple);
    let orange = Some(Food::Orange);
    let tomato = None;

    let cooked_apple = cook_food(chop_food(peel_food(apple)));
    let cooked_orange = cook_food(chop_food(peel_food(orange)));
    let cooked_tomato = process(tomato);

    eat(cooked_apple);
    eat(cooked_orange);
    eat(cooked_tomato);
}