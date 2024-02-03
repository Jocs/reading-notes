use std::ops::Add;

extern "C" {
    fn abs(input: i32) -> i32;
}

static mut COUNTER: u32 = 0;

fn add_to_count(inc: u32) {
    unsafe {
        COUNTER += inc;
    }
}

#[derive(Debug, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

impl Add for Point {
    type Output = Point;

    fn add(self, other: Point) -> Point {
        Point {
            x: self.x + other.x,
            y: self.y + other.y,
        }
    }
}

fn main() {
    println!("Hello, world!");
    let mut num = 5;
    let r1 = &num as *const i32;
    let r2 = &mut num as *mut i32;

    unsafe {
        println!("r1 = {}", *r1);
        println!("r2 = {}", *r2);
    }

    unsafe {
        println!("abs(-5) = {}", abs(-5));
    }

    unsafe {
        add_to_count(5);
        println!("COUNTER = {}", COUNTER);
    }

    let point_a = Point { x: 4, y: 0 };
    let point_b = Point { x: 3, y: 4 };
    println!("point_a + point_b = {:?}", point_a + point_b);
}
