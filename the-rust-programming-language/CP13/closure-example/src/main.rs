use std::{thread, time::Duration};

fn main() {
    let result_num = simulated_expensive_calculation(5);

    println!("The answer is {}", result_num);

    generate_workout(5, 5);
}

fn simulated_expensive_calculation(x: i32) -> i32 {
    println!("calculating slowly...");
    thread::sleep(Duration::from_secs(2));

    x * 2
}

fn generate_workout(intensity: u32, random_num: u32) {
    let expensive_closure = |x: u32| -> u32 {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));

        x * 2
    };

    let mut cached_closure = Cacher::new(expensive_closure);

    if intensity < 25 {
        println!("Today to {} pushups!", cached_closure.value(intensity));
    } else {
        if random_num == 3 {
            println!("Take a break today! Remember to stay hydrated!");
        } else {
            println!(
                "Today to {} situps!",
                cached_closure.value(intensity)
            );
        }
    }
}

#[allow(dead_code)]
fn compile_error() {
    let example_closure = |x| x;

    let s = example_closure(String::from("hello"));

    println!("{}", s);

    // let n = example_closure(5);

    // println!("{}", n);
}

struct Cacher<T>
    where T: Fn(u32) -> u32
{
    calculation: T,
    value: Option<u32>,
}

impl <T> Cacher<T>
    where T: Fn(u32) -> u32
{
    fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            value: None,
        }
    }

    fn value(&mut self, arg: u32) -> u32 {
        match self.value {
            Some(v) => v,
            None => {
                let v = (self.calculation)(arg);
                self.value = Some(v);
                v
            }
        }
    }
}
