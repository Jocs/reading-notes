use std::cmp::PartialOrd;

fn main() {
    println!("Hello, world!");

    let list = vec![1, 2, 3, 5, 3, 8];

    let num = largest(&list);

    println!("The largest number is {}", num);

    let char_list = vec!['y','m', 'a', 'q'];

    let char = largest_v2(&char_list);

    println!("The largest char is {}", char);
}

fn largest(list: &[i32]) -> i32 {
    let mut largest_num = list[0];

    for &item in list.iter() {
        if item > largest_num {
            largest_num = item;
        }
    }

    largest_num
}

fn largest_v2<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest_item = list[0];

    for &item in list.iter() {
        if item > largest_item {
            largest_item = item;
        }
    }

    largest_item
}

#[test]
fn test_largest() {
    let list = vec![1, 2, 3, 5, 3, 8];
    assert!(largest(&list) == 8);
}


