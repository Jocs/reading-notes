use std::thread;

static NTHREADS: i32 = 10;

pub fn main_exec() {
    let mut children = vec![];

    for i in 0..NTHREADS {
        children.push(thread::spawn(move || {
            println!("Hello from thread {}", i);
        }));
    }

    for child in children {
        child.join().unwrap();
    }
}