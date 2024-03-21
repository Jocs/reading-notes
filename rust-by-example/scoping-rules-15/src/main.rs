mod ownership;
mod raii;
mod borrowing;
mod lifetime;

#[derive(Debug)]
struct OneNumber(i32);

impl Drop for OneNumber {
    fn drop(&mut self) {
        println!("Dropping {}", self.0);
    }
}

fn main() {
    println!("Hello, world!");

    raii::main_execute();

    let x = OneNumber(10);

    println!("Made a drop of {:?}", x);

    let x = 5u32;
    let y = x;

    println!("x is {}, y is {}", x, y);

    let z = Box::new(5i32);

    let m = z;

    // println!("z is {}, m is {}", z, m);

    println!("m is {}", m);

    ownership::destroy_box(m);
    ownership::mutable_box();
    ownership::part_move();

    borrowing::main_execute();
    borrowing::ref_main();

    lifetime::main_execute();
}
