fn eat_box_i32(c: Box<i32>) {
    println!("eat_box_i32: {}", c);
}

fn borrow_i32(c: &i32) {
    println!("borrow_i32: {}", c);
}

// 可变性

#[allow(dead_code)]
#[derive(Debug, Clone, Copy)]
struct Book {
    author: &'static str,
    title: &'static str,
    year: u32,
}

fn borrow_book(book: &Book) {
    println!("borrow_book: author {}, title: {}", book.author, book.title);
}

fn new_edition(book: &mut Book) {
    book.year = 2024;

    println!("new_edition: author {}, title: {}, year: {}", book.author, book.title, book.year);
}

#[derive(Debug)]
struct Point {
    x: f64,
    y: f64,
}

pub fn main_execute() {
    let boxed_i32 = Box::new(5);
    let stacked_i32 = 6;

    borrow_i32(&boxed_i32);
    borrow_i32(&stacked_i32);

    {
        let _ref_to_i32 = &boxed_i32;

        // eat_box_i32(boxed_i32);

        borrow_i32(_ref_to_i32);
    }

    eat_box_i32(boxed_i32);

    let book = Book {
        author: "Jocs",
        title: "The Rust Programming Language",
        year: 2018,
    };

    let mut mutable_book = book;

    borrow_book(&book);
    borrow_book(&mutable_book);

    new_edition(&mut mutable_book);
    // new_edition(&mut book);

    let mut point = Point { x: 1.0, y: 2.0 };
    let borrowed_point = &point;

    println!("The point is {:?}, x: {}, y: {}", point, point.x, borrowed_point.y);

    let mutable_borrowed_point = &mut point;

    mutable_borrowed_point.x = 10.0;
    mutable_borrowed_point.y = 20.0;

    println!("The mutable point is {:?}, x: {}, y: {}", mutable_borrowed_point, mutable_borrowed_point.x, mutable_borrowed_point.y);

    let new_borrowed_point = &point;

    println!("The new borrowed point is {:?}, x: {}, y: {}", new_borrowed_point, new_borrowed_point.x, new_borrowed_point.y);
}


// ref mut 可以在结构的时候，创建一个值的可变引用
#[derive(Debug, Clone, Copy)]
struct Point2D {
    x: f64,
    y: f64,
}

pub fn ref_main() {
    let c = 'Q';
    let ref ref_c_1 = c;
    let ref_c_2 = &c;

    assert_eq!(*ref_c_1, *ref_c_2);

    let point = Point2D { x: 1.0, y: 2.0 };

    let _copy_of_x = {
        let Point2D { x: ref ref_x, y: _ } = point;

        *ref_x
    };

    println!("x is {} in point", _copy_of_x);

    let mut mutable_point = point;

    {
        let Point2D { x: _, y: ref mut mut_y } = mutable_point;
        *mut_y = 100.0;
    }

    println!("point is existed: {:?}", point);

    println!("point is mutated: {:?}", mutable_point);

    let mut mutable_tuple = (Box::new(5), 6);

    {
        let (_, ref mut last) = mutable_tuple;

        *last = 100;
    }

    println!("mutable_tuple is {:?}", mutable_tuple);
}

// 元组具有 Clone 特性，因此可以被复制
pub fn test_ref() {
    let tuple = (1, 2, 3);
    let tuple_2 = tuple;

    println!("tuple is {:?}, and {:?}", tuple, tuple_2);

    let point = Point { x: 1.0, y: 2.0 };
    let point_2 = point;

    // println!("point is {:?}, and point_2 is: {:?}", point, point_2);
}
