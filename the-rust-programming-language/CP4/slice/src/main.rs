fn main() {
    println!("Hello, world!");

    let s1 = String::from("hello world");

    let word = first_word(&s1[..]);

    println!("first word = {}", word);

    let s1 = "foo bar";

    let word = first_word(s1);

    println!("first word = {}", word);
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
