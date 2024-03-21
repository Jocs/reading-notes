fn give_princess(gift: &str) {
    if gift == "snack" {
        panic!("Aaaaaaa!!!");
    }

    println!("Princess love {}", gift);
}

pub fn main_exec() {
    give_princess("bear");
    // give_princess("snack");
}