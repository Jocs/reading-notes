use std::thread;

pub fn main_exec() {
    let data = "86967897737416471853297327050364959
    11861322575564723963297542624962850
    70856234701860851907960690014725639
    38397966707106094172783238747669219
    52380795257888236525459303330302837
    58495327135744041048897885734297812
    69920216438980873548808413720956532
    16278424637452589860345374828574668";
    let mut children = vec![];

    let chunked_data: Vec<&str> = data.split_whitespace().collect();

    for chunk in chunked_data {
        children.push(thread::spawn(move || {
            let result = chunk.chars().map(|c| c.to_digit(10).unwrap()).sum::<u32>();

            println!("Sum of chunk {} is {}", chunk, result);

            result
        }));
    }

    let mut intermediate_sums = vec![];
    for child in children {
        let sum = child.join().unwrap();
        intermediate_sums.push(sum);
    }

    let final_sum: u32 = intermediate_sums.iter().sum();

    println!("Final sum is {}", final_sum);
}