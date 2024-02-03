use std::mem;

fn main() {
    println!("Hello, world!");

    let color = String::from("green");

    let print = || println!("color: {}", color);

    print();

    let _reborrow = &color;

    print();

    let _color_move = color;

    let mut count = 0;

    let mut inc = || {
        count += 1;
        println!("count: {}", count);
    };

    inc();

    // let _count_reborrow = &count;
    inc();

    let _count_reborrowed = &mut count;

    let movable = Box::new(4);

    let consume = || {
        println!("the number is {:?}", movable);
        mem::drop(movable);
    };

    consume();
    // consume();
    // 在竖线 | 之前使用 move 会强制闭包获取被捕获变量的所有权
    let haystack = vec![1, 2, 3];
    let contains = move |needle| haystack.contains(needle);

    println!("{}", contains(&1));
    // 因为 haystack 的所有权已经移交到了 contains 里面，所以外部不能够再使用
    // println("haystack's length = {}", haystack.len());
    test_1();
    test_2();
    any_example();
    hoc_example();
}

// 当闭包作为函数参数时，必须指定类型
fn apply<F>(f: F)
where
    F: FnOnce(),
{
    f();
}

fn apply_to_3<F>(f: F) -> i32
where
    F: Fn(i32) -> i32,
{
    f(3)
}

fn test_1() {
    let green = "green";
    let mut red = "red".to_owned();

    let diary = || {
        println!("I saw color: {}", green);

        red.push('!');

        println!("I saw color: {}", red);

        mem::drop(red);
    };

    apply(diary);

    let double = |x| {
        x * 2
    };

    let result = apply_to_3(double);

    println!("The result of apply_to_3: {}", result);
}

fn create_fn() -> impl Fn() {
    let value = "fn".to_owned();

    move || println!("The value is {}", value)
}

fn create_fnmut() -> impl FnMut() {
    let value = "fnmut".to_owned();

    move || println!("The value is {}", value)
}

fn create_fnonce() -> impl FnOnce() {
    let value = "fnonce".to_owned();

    move || println!("The value is {}", value) 
}

fn test_2() {
    create_fn()();
    create_fnmut()();
    create_fnonce()();
}

fn any_example() {
    let vec_1 = vec![1, 2, 3, 4];
    let vec_2 = vec![2, 3, 4, 5];

    assert!(vec_1.iter().any(|&i| i == 2));
    // into_iter will table the ownership
    assert_eq!(vec_2.into_iter().any(|i| i == 5), true);

    println!("first find 1 is {:?}", vec_1.iter().find(|&&i| i == 1));
    println!("first find 5 is {:?}", vec_1.iter().find(|&&i| i == 5));

    // println!("first find is {:?}", vec_2.into_iter().find(|&i| i == 1));

    let arr_1 = [1, 2, 3, 4];
    println!("arr_1 has 4: {}", arr_1.iter().any(|&i| i == 4));
}

fn hoc_example() {
    let sum = (0..)
        .map(|n| n * n)
        .take_while(|&n| n < 1000)
        .filter(|&n| n % 2 == 1)
        .fold(0, |sum, n| sum + n);

    println!("The sum is: {}", sum);
}
