fn main() {
    println!("Hello, world!");
    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);

    println!("The six value is {:?}", six);
    println!("The none value is {:?}", none);

    print_num(2);

    print_two(2);
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn print_num(value: u8) {
    match value {
        1 => println!("one"),
        2 => println!("two"),
        _ => (),
    }
}

fn print_two(value: u8) {
    if let value = 2 {
        println!("two");
    }
}
