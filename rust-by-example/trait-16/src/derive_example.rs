// Clone 和 Copy trait 的区别，Clone 用来从 &T 创建副本 T，Copy 使类型具有“复制语义”而非“移动语义”。
// 下面是可以自动派生的 trait
// Eq, PartialEq, Ord, PartialOrd, Clone, Copy, Hash, Default, Debug 等
// Debug: 可以使用 {:?} 来格式化一个值
// Eq, PartialEq, Ord, PartialOrd 分别有什么作用？

#[derive(PartialEq, PartialOrd, Debug)]
struct Centimeters(f64);

#[derive(Debug)]
struct Inches(i32);

#[derive(Debug)]
struct Second(i32);

impl Inches {
    fn to_centimeters(&self) -> Centimeters {
        let value = self.0 as f64;

        return Centimeters(value * 2.54);
    }
}

pub fn main_exec() {
    let one_second = Second(1);
    println!("one_second: {:?}", one_second);

    let one_inch = Inches(1);
    let centimeter_100 = Centimeters(100.0);

    if one_inch.to_centimeters() < centimeter_100 {
        println!("smaller");
    } else {
        println!("bigger");
    }

    println!("One inch {:?} is {:?}.", one_inch, one_inch.to_centimeters());
}