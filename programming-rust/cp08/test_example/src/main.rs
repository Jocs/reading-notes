#![doc = include_str!("../README.md")]

#[allow(unused_imports)]
use std::num::ParseIntError;

/// 这是程序入口函数
fn main() {
    println!("Hello, world!");
}

#[test]
fn explicit_radix() -> Result<(), ParseIntError> {
    i32::from_str_radix("1234", 10)?;
    Ok(())
}
