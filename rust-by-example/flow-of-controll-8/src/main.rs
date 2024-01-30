fn main() {
    println!("Hello, world!");

    let mut counter = 0;

    let result = loop {
        counter += 1;
        println!("counter: {}", counter);

        if counter == 10 {
            break counter * 2;
        }
    };

    assert_eq!(result, 20);

    let mut names = vec!["Jocs", "ransixi", "javascript"];

    for name in names.iter_mut() {
        *name = match name {
            &mut "ransixi" => "This is my name",
            _ => "hello",
        }
    }

    println!("{:#?}", names);
}
