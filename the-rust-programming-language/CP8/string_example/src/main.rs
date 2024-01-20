
// Rust 字符串不支持索引
fn main() {
    println!("Hello, world!");

    let s = "hello world".to_string();

    let s2 = String::from("foo bar");

    let s3 = String::from("👌");

    let s4 = String::from("中");

    println!("The length of '{}' is {}.", s, s.len());

    println!("The length of '{}' is {}.", s2, s2.len());

    println!("The length of '{}' is {}.", s3, s3.len());

    println!("The length of '{}' is {}.", s4, s4.len());

    push_string();

    format_string();

    loop_char();
}

fn push_string() {
    let mut s = String::from("hello");

    s.push_str(", world");

    println!("{}", s);
}

fn format_string() {
    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");

    let s = format!("{}-{}-{}", s1, s2, s3);

    println!("{}", s);
}

fn loop_char() {
    let s = String::from("hello中文👌");

    for c in s.chars() {
        println!("{}", c);
    }
}
