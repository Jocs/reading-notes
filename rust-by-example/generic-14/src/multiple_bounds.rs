use std::fmt::{Debug, Display};

fn compare_prints<T: Display + Debug>(t: &T) {
    println!("Display: {}", t);
    println!("Debug: {:?}", t);
}

fn compare_types<T: Debug, U: Debug>(t: &T, u: &U) {
    println!("Display: {:?}", t);
    println!("Debug: {:?}", u);
}

pub fn main_exec() {
    let string = "Hello";
    let array = [1, 2, 3];
    let vec = vec![4, 5, 6];

    compare_prints(&string);

    compare_types(&array, &vec);
}