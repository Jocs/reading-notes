struct Point {
    x: u32,
    y: u32,
}

#[allow(dead_code)]
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn main() {
    // 匹配字面量
    let x = 5;
    match x {
        1 => println!("One"),
        5 => println!("Five"),
        _ => println!("Other"),
    }

    // 匹配命名变量
    let x = Some(5);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(y) => println!("Matched {}, not 50", y),
        _ => println!("Default case, x is {:?}", x),
    }

    println!("at the end: x = {:?}, y = {}", x, y);

    // 多重模式
    let x = 1;
    
    match x {
        1 | 2 => println!("x is {}", x),
        _ => println!("anything"),
    }

    // 匹配值区间
    let x = 5;

    match x {
        1..=5 => println!("one through five"),
        _ => println!("something else"),
    }

    // 匹配 char

    let x = 'c';

    match x {
        'a'..='f' => println!("a through f"),
        'g'..='z' => println!("g through z"),
        _ => println!("something else"),
    }

    // 解构结构体
    let p = Point { x: 0, y: 7 };
    let Point { x: a, y: b } = p;

    println!("a = {}, b = {}", a, b);

    match p {
        Point { x, y: 0 } => println!("On the x axis at {}", x),
        Point { x: 0, y } => println!("On the y axis at {}", y),
        Point { x, y } => println!("On both axes at {}, {}", x, y), // 匹配所有字段
    }

    let msg = Message::ChangeColor(1, 2, 3);

    match msg {
        Message::Quit => {
            println!("The Quit variant has no data")
        },
        Message::Move { x, y } => {
            println!("Move in the x direction {} and in the y direction {}", x, y)
        },
        Message::Write(text) => println!("Text message: {}", text),
        Message::ChangeColor(r, g, b) => {
            println!("Change the color to red {}, green {}, and blue {}", r, g, b)
        },
    }

    let s = Some(String::from("hello world"));

    if let Some(_) = s {
        println!("s has string");
    }

    println!("s: {:?}", s);

    let origin = Point { x: 0, y: 0 };

    match origin {
        Point { x, .. } => println!("x is {}", x),
    }

    let numbers = (1, 2, 3, 4, 5, 6, 8);

    match numbers {
        (first, .., last) => println!("first: {}, last: {}", first, last),
    }

    // match guard
    let num: Option<i32> = None;

    match num {
        Some(x) if x > 8 => println!("x is greater than 8"),
        _ => println!("x is not greater than 8 or None"),
    }
}
