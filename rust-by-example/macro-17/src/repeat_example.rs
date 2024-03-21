// 宏还可以递归。
macro_rules! find_min {
    // base case
    ($x:expr) => ($x); // 这儿为啥要用括号？
    ($x:expr, $($y:expr),+) => (
        std::cmp::min($x, find_min!($($y),+))
    )
}

pub fn main_exec() {
    println!("find_min!(1, 2, 3, 4) = {}", find_min!(1, 2, 3, 4));
    println!("find_min!(1, 2, 3, 4, 5) = {}", find_min!(1, 2, 3, 4, 5));
}