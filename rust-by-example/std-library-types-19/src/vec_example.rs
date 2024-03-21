pub fn main_exec() {
    let mut numbers = (0..10).collect::<Vec<i32>>();
    println!("the vector is {:?}", numbers);
    numbers.push(10i32);
    println!("the vector is {:?} after push 10", numbers);
    numbers.pop();
    println!("the vector is {:?} after pop", numbers);

    for n in numbers.iter() {
        println!("the number is {}", n);
    }

    for (i, n) in numbers.iter().enumerate() {
        println!("the {}th number is {}", i, n);
    }

    for n in numbers.iter_mut() {
        *n += 10;
    }

    println!("the vector is {:?} after mut", numbers);
}