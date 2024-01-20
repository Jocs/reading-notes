fn main() {
    println!("Hello, world!");

    let mut s1 = String::from("hello");

    change_value(&mut s1);

    let len = calculate_length(&s1);

    println!("The length of '{}' is {}.", s1, len);
}

fn calculate_length(s: &String) -> usize {
    // len 方法返回 usize 类型
    s.len()
}

fn change_value(s: &mut String) {
    s.push_str(" world");
}
