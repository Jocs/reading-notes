#[derive(Debug)]
pub enum List {
    Cons(i32, Box<List>),
    Nil,
}

fn main() {
    // 该数据将会存储在堆上，并在栈中保留一个指向堆数据的指针，在离开作用域时会被释放，释放的内容
    // 1. 堆上的数据
    // 2. 栈上的指针
    let b = Box::new(3i32);

    println!("b is {}", b);

    let mut list = Box::new(List::Nil);
    for i in 0..3 {
        list = Box::new(List::Cons(i, list));
    }

    println!("{:#?}", list);
}
