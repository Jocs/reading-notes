use std::mem;

#[allow(dead_code)]
#[derive(Debug, Clone, Copy)]
struct Point {
    x: f64,
    y: f64,
}

#[allow(dead_code)]
#[derive(Debug, Clone, Copy)]
struct Rectangle {
    p1: Point,
    p2: Point,
}

fn origin() -> Point {
    Point { x: 0.0, y: 0.0 }
}

fn boxed_origin() -> Box<Point> {
    Box::new(origin())
}

pub fn main_exec() {
    let point = origin();
    let rectangle = Rectangle {
        p1: origin(),
        p2: Point { x: 3.0, y: 4.0 },
    };

    let boxed_rectangle = Box::new(Rectangle {
        p1: origin(),
        p2: Point { x: 3.0, y: 4.0 },
    });

    let boxed_point = Box::new(origin());

    let box_in_box = Box::new(boxed_origin());

    println!("point occupies {} bytes", mem::size_of_val(&point));
    println!("rectangle occupies {} bytes", mem::size_of_val(&rectangle));
    println!("boxed point occupies {} bytes", mem::size_of_val(&boxed_point));
    println!("boxed rectangle occupies {} bytes", mem::size_of_val(&boxed_rectangle));
    println!("box in a box occupies {} bytes", mem::size_of_val(&box_in_box));
}

