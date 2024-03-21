fn combine_vecs(v1: Vec<i32>, v2: Vec<i32>) -> impl Iterator<Item = i32> {
    v1.into_iter().chain(v2.into_iter()).cycle()
}

fn make_adder_function(y: i32) -> impl Fn(i32) -> i32 {
    move |x| {x + y}
}

pub fn main_exec() {
    let v1 = vec![1, 2, 3];
    let v2 = vec![4, 5, 6];

    for item in combine_vecs(v1, v2).take(6) {
        println!("{}", item);
    }

    let adder_one = make_adder_function(1);

    println!("100 add 1: {}", adder_one(100));
}