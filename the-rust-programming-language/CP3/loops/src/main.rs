fn fibonacci(n: i32) -> i32 {
    let mut first = 0;
    let mut second = 1;

    if n == 1 {
        return first;
    }

    if n == 2 {
        return second;
    }

    for _ in 2..n {
        let sum = first + second;
        first = second;
        second = sum;
    }

    second
}

fn for_loop_with_range() {
    // No need to call iter.
    for number in (1..8).rev() {
        println!("{}!", number);
    }
}

fn for_loop() {
    let arr = [10, 20, 30, 40, 50];

    for item in arr.iter() {
        println!("The value is {}", item);
    }
}

fn main() {
    for_loop();

    for_loop_with_range();

    println!("The fibonacci number is {}", fibonacci(4));

    let mut counter = 0;

    let result = loop {
        counter = counter + 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {}", result);
}
