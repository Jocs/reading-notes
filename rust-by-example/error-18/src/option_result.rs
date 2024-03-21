use std::num::ParseIntError;

// 从 Option 取出 Result 的例子
fn double_first(vec: Vec<&str>) -> Result<Option<i32>, ParseIntError> {
    let opt = vec.first().map(|first| {
        first.parse::<i32>().map(|i| i * 2)
    });

    opt.map_or(Ok(None), |r| r.map(Some))
}

pub fn main_exec() {
    let numbers = vec!["42", "1"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    println!("The first doubled is {:?}", double_first(numbers));
    println!("The first doubled is {:?}", double_first(empty));
    println!("The first doubled is {:?}", double_first(strings));
}