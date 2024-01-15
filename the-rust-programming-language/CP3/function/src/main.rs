fn five() -> i32 {
    return 5;
}

fn another_function(value: i32) {
    println!("The value is {}", value);
}

fn main() {
    println!("Hello, world!");

    another_function(67);

    let x = 5;

    let y = {
        let x = x * 3;
        x + 2
    };

    println!("The value of y is {}", y);

    let five_number = five();

    println!("The value of five_number is {}", five_number);
}
