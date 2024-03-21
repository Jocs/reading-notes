fn create_box(num: i32) -> Box<i32> {
    let x = Box::new(num);
    // println!("x is {}", x);
    x
}

pub fn main_execute() {
    let _box2 = Box::new(5);

    {
        let _box3 = Box::new(5);
    }

    for i in 0..=1000000 {
        create_box(i);
    }
}