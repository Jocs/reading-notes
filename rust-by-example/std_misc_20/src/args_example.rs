use std::env;

pub fn main_exec() {
    let args: Vec<String> = env::args().collect();

    match args.len() {
        1 => println!("No arguments provided"),
        2 => {
            match args[1].parse::<i32>() {
                Ok(num) => println!("The value of the first argument is {}", num),
                Err(_) => println!("The first argument is not an integer"),
            }
        },
        3 => {
            let cmd = args[1].as_str();
            let num = args[2].parse::<i32>().unwrap();

            match cmd {
                "increase" => println!("The value of the first argument increased by one is {}", num + 1),
                "decrease" => println!("The value of the first argument decreased by one is {}", num - 1),
                _ => println!("The first argument is not an increase or decrease"),
            }
        }
        _ => println!("{} arguments provided", args.len()),
    }
}