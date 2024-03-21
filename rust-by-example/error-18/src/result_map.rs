use std::num::ParseIntError;

fn multiple(num_left: &str, num_right: &str) -> Result<i32, ParseIntError> {
    num_left.parse::<i32>().and_then(|n1| {
        num_right.parse::<i32>().map(|n2| n1 * n2)
    })
}

fn print_result(result: Result<i32, ParseIntError>) {
    if let Ok(r) = result {
        println!("The result is {}", r);
    } else {
        println!("The result is an error");
    }
}

pub fn main_exec() {
    let result = multiple("23", "23");
    print_result(result);
    print_result(multiple("tt", "num_right"));
}