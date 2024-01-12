use std::io;
use std::cmp::Ordering;
use rand::prelude::*;

fn main() {
    println!("Guessing the number!!");

    let secret_number = thread_rng().gen_range(1..101);
    println!("The secret number is: {}", secret_number);

    loop {
        println!("Please input a number?");
        // mut 关键词便是变量可变
        let mut guess = String::new();
        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");
    
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            },
        }

        println!("You guessed: {}", guess);
    }
}
