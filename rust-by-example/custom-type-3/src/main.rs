#[derive(Debug)]
struct Point {
    x: f32,
    y: f32,
}

#[derive(Debug)]
struct Rectangle {
    top_left: Point,
    bottom_right: Point,
}

impl Rectangle {
    fn new_square(top_left: &Point, width: f32) -> Rectangle {
        Rectangle {
            top_left: Point {
                x: top_left.x,
                y: top_left.y,
            },
            bottom_right: Point {
                x: top_left.x + width,
                y: top_left.y - width,
            },
        }
    }

    fn area(&self) -> f32 {
        let width = self.bottom_right.x - self.top_left.x;
        let height = self.top_left.y - self.bottom_right.y;

        width * height
    }
}

fn main() {
    println!("Hello, world!");
    let top_left = Point { x: 0.0, y: 0.0 };
    let width = 5.0;
    let rect = Rectangle::new_square(&top_left, width);
    let area = rect.area();

    println!("The area of {:#?} is {}", rect, area);

    let mut list = List::new();
    list = list.append(1);
    list = list.append(2);
    list = list.append(3);
    println!("The length of {:#?} is {}", list, list.len());
    println!("The string of {:#?} is {}", list, list.stringify());
}

#[allow(dead_code)]
#[derive(Debug)]
enum List {
    Cons(i32, Box<List>),
    Nil,
}

impl List {
    fn new() -> List {
        List::Nil
    }

    fn append(self, value: i32) -> List {
        List::Cons(value, Box::new(self))
    }

    fn len(&self) -> i32 {
        match *self {
            // ref 是做啥的？
            List::Cons(_, ref tail) => 1 + tail.len(),
            List::Nil => 0,
        }
    }

    fn stringify(&self) -> String {
        match *self {
            // ref 是做啥的？
            List::Cons(value, ref tail) => format!("{} {}", value, tail.stringify()),
            List::Nil => format!("Nil"),
        }
    }
}
