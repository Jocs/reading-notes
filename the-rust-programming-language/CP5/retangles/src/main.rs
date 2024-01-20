#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    fn square(size: u32) -> Rectangle {
        Rectangle { width: size, height: size }
    }
}

fn main() {
    println!("Calculate the area of rectangle!");

    let rectangle = Rectangle { width: 30, height: 50 };

    let other = Rectangle { width: 10, height: 40 };

    let square = Rectangle::square(10);

    println!("Square: {:#?}", square);

    println!("Rectangle: {:#?}", rectangle);
    
    println!("The area of rectangle is {} square pixels.", rectangle.area());

    println!("Can rectangle hold other rectangle? {}", rectangle.can_hold(&other));
}

// fn area(rectangle: &Rectangle) -> u32 {
//     rectangle.width * rectangle.height
// }