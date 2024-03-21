use std::collections::HashSet;

pub fn main_exec() {
    let mut a: HashSet<i32> = vec![1, 2, 3, 4].into_iter().collect();
    let mut b: HashSet<i32> = vec![4, 5, 6, 7].into_iter().collect();

    println!("a insert 3: {}", a.insert(3));
    println!("b insert 3: {}", b.insert(3));

    println!("a: {:?}", a);
    println!("b: {:?}", b);

    println!("Union: {:?}", a.union(&b).collect::<Vec<_>>());
    println!("Intersection: {:?}", a.intersection(&b).collect::<Vec<_>>());
    println!("Difference: {:?}", a.difference(&b).collect::<Vec<_>>());
    println!("Symmetric Difference: {:?}", a.symmetric_difference(&b).collect::<Vec<_>>());
}