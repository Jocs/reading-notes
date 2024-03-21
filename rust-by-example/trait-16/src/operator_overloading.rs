use std::ops;

// 运算符是方法调用的语法糖，之前在 Haskell 也有类似概念
#[derive(Debug)]
struct Second(i32);

#[derive(Debug)]
struct Minute(i32);

impl ops::Add<Minute> for Second {
    type Output = Self;

    fn add(self, other: Minute) -> Self {
        Second(self.0 + other.0 * 60)
    }
}

pub fn main_exec() {
    let one_second = Second(1);
    let one_minute = Minute(1);

    println!("one_second + one_minute: {:?}", one_second + one_minute);
}

