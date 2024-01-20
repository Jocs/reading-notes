use std::collections::HashMap;

fn main() {
    println!("Hello, world!");
    
    let teams = vec![String::from("foo"), String::from("bar")];
    let scores = vec![12, 21];
    
    let team_scores: HashMap<_, _> = teams.iter().zip(scores.iter()).collect();
    
    println!("The team scores is {:#?}", team_scores);
    
    get_vaule();
    
    for_loop_iter_value();
    
    word_count();
    
    let list = vec![1, 2, 3, 4, 5];
    
    let ave = average(&list);
    
    println!("The average number is {}", ave);
}

fn get_vaule() {
    let mut scores = HashMap::new();
    scores.insert(String::from("foo"), 12);
    scores.insert(String::from("bar"), 13);
    
    let team_name = String::from("foo");
    let score = scores.get(&team_name);
    
    match score {
        Some(value) => println!("The score of {} is {}", team_name, value),
        None => println!("The score is None"),
    }
}

fn for_loop_iter_value() {
    let mut scores = HashMap::new();
    scores.insert(String::from("foo"), 12);
    scores.insert(String::from("bar"), 13);
    
    for (key, value) in &scores {
        println!("The score of {} is {}", key, value);
    }
}

fn word_count() {
    let text = "hello world wonderful world";
    let mut map = HashMap::new();
    
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }
    
    println!("{:#?}", map);
}

fn average(list: &Vec<i32>) -> i32 {
    let mut sum = 0;
    
    for item in list.iter() {
        sum += item;
    }
    
    sum / list.len() as i32
}
