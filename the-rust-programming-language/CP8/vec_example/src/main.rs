fn main() {
    println!("Hello, world!");

    let v = vec![1, 2, 3, 4, 5];

    let first: &i32 = &v[0];

    println!("The first element is {}", first);

    match v.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element."),
    }

    push_element();

    loop_vector();
}

fn push_element() {
    let mut v = vec![1, 2, 3, 4, 5];

    let first: &i32 = &v[0];

    // Can not put this line of code after println!().
    println!("The first element is {}", first);

    v.push(6);

    println!("The vector v is {:?}", v);
}

fn loop_vector() {
    let mut v = vec![100, 32, 57];

    for item in &mut v {
        *item += 50;
        println!("item {}", item);
    }
}
