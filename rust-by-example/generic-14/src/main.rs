mod multiple_bounds;
mod where_state;

struct Cardinal;
struct BlueJay;
struct Turkey;

trait Red {}

trait Blue {}

impl Red for Cardinal {}

impl Blue for BlueJay {}

fn red<T: Red>(_t: T) -> &'static str {
    "red"
}

fn blue<T: Blue>(_t: T) -> &'static str {
    "blue"
}


fn main() {
    let cardinal = Cardinal;
    let blue_jay = BlueJay;
    let _turkey = Turkey;

    println!("A cardinal is {}", red(cardinal));
    println!("A blue jay is {}", blue(blue_jay));
    // println!("A turkey is {}", red(turkey));

    multiple_bounds::main_exec();
    where_state::main_exec();
}
