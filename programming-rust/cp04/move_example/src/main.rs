struct Person {
    name: Option<String>,
    birth: i32,
}

fn main() {
    let v = vec!["hello".to_string(), "world".to_string()];

    for mut s in v {
        s.push('!');
        println!("{}", s);
    }

    // println!("v: {:?}", v);
    let mut composers = Vec::new();
    composers.push(Person { name: Some("jocs".to_string()), birth: 1988 });

    let name = composers[0].name.take();
    let birth = composers[0].birth;

    println!("The first item of composers: name {:?} and birth {}", name, birth);
}
