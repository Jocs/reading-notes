// 资源只能拥有一个所有者，资源被移动后，原来的所有者不能再访问该资源

pub fn destroy_box(c: Box<i32>) {
    println!("Destroying a box that contains {}", c);
}

// 当所有权转移时候，数据的可变性可能发生改变
pub fn mutable_box() {
    let immutable_box = Box::new(5);

    // *immutable_box = 10;

    let mut immutable_box_1 = immutable_box;

    println!("Box contains {}", immutable_box_1);

    *immutable_box_1 = 10;

    println!("Box contains {}", immutable_box_1);
}

#[derive(Debug)]
struct Person {
    name: String,
    age: u8,
}

// 部分移动
pub fn part_move() {
    let person = Person {
        name: "Jocs".to_string(),
        age: 27,
    };

    let Person { name, ref age } = person;

    println!("person name is {}, age is {}", name, age);

    // println!("person {:?}", person);

    println!("age of person is {}", person.age);
}

