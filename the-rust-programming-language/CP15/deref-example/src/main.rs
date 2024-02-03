use std::ops::Deref;

#[allow(dead_code)]
struct MyBox<T> {
    value: T,
}

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox {
            value: x,
        }
    }
}

impl<T> Deref for MyBox<T> {
    // 定义关联类型
    type Target = T;

    fn deref(&self) -> &T {
        &self.value
    }
}

// &str 和 &String 区别？
fn hello(name: &str) {
    println!("name is {}", name);
}

fn main() {
    let x = 5;
    let y = MyBox::new(x);

    assert_eq!(x, 5);
    assert_eq!(*y, 5); // *y equal *(y.deref())

    let name = MyBox::new(String::from("jocs"));

    hello(&name);
}
