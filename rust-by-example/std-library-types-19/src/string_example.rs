// String 是堆分配的，可增长的，且不是零结尾的
// &str 是一个指向有效 UTF-8 序列的切片（&[u8]）,并可以用来查看 String 内容

pub fn main_exec() {
    let pangram: &'static str = "the quick brown fox jumps over the lazy dog";
    println!("pangram is {}", pangram);

    println!("words in reverse order: ");
    for word in pangram.split_whitespace().rev() {
        println!("> {}", word);
    }

    let mut chars: Vec<char> = pangram.chars().collect();
    chars.sort();
    chars.dedup();
    let mut new_str = String::new();
    for char in chars {
        new_str.push(char);
        new_str.push_str(", ");
    }

    let chars_to_trim = &[' ', ','];
    let trimmed_str = new_str.trim_end_matches(chars_to_trim);

    println!("new_str after trimmed is {}", trimmed_str);

    let alice = String::from("Alice");
    let bob = alice.replace("A", "B");

    println!("alice is {}", alice);
    println!("bob is {}", bob);
}