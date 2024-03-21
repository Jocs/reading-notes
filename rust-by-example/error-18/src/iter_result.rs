use std::vec;

fn iter_strings() {
    let strings = vec!["tofu", "93", "18"];

    let numbers = strings.into_iter().map(|s| s.parse::<i32>()).collect::<Vec<_>>();

    println!("{:?}", numbers);
}

// use filter_map
fn filter_map_strings() {
    let strings = vec!["tofu", "93", "18"];

    let numbers: Vec<i32> = strings.into_iter()
        .filter_map(|i| i.parse::<i32>().ok()).collect();

    println!("filter map numbers: {:?}", numbers);
}

// 使用 collect 是的整个操作失败
fn iter_collect_strings() {
    let strings = vec!["tofu", "93", "18"];

    let numbers: Result<Vec<_>, _> = strings.into_iter().map(|s| s.parse::<i32>()).collect();

    println!("{:?}", numbers);
}

// 使用 partition
fn partition_strings() {
    let strings = vec!["tofu", "93", "18"];

    let (numbers, errors): (Vec<_>, Vec<_>) = strings.into_iter()
        .map(|x| x.parse::<i32>())
        .partition(|x| x.is_ok());

    let numbers: Vec<i32> = numbers.into_iter().map(Result::unwrap).collect();
    let errors: Vec<_> = errors.into_iter().map(Result::unwrap_err).collect();

    println!("numbers: {:?}, errors: {:?}", numbers, errors);
}

pub fn main_exec() {
    iter_strings();
    filter_map_strings();
    iter_collect_strings();
    partition_strings();
}