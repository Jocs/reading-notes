fn main() {
    let favorite_color: Option<&str> = Some("red");
    let is_tuesday: bool = false;
    let age: Result<u8, _> = "34".parse();

    if let Some(color) = favorite_color {
        println!("Using your favorite color, {}, as the background", color);
    } else if is_tuesday {
        println!("Tuesday is green day!");
    } else if let Ok(age) = age {
        if age > 30 {
            println!("Using purple as the background color");
        } else {
            println!("Using orange as the background color");
        }
    } else {
        println!("Using blue as the background color");
    }

    let mut nums: Vec<i32> = Vec::new();
    for i in 0..3 {
        nums.push(i);
    }

    while let Some(num) = nums.pop() {
        println!("Pop number is {}", num);
    }

    let (x, (y, z)) = (1, (2, 3));

    println!("x is {}, y is {}, z is {}", x, y, z);

    let point = (1, 4);

    print_coordinates(&point);
}

fn print_coordinates(&(x, y): &(i32, i32)) {
    println!("Current location ({}, {}).", x, y);
}
