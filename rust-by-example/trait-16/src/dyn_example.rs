struct Sheep {}
struct Cow {}

trait Animal {
    fn noise(&self) -> &str;
}

impl Animal for Sheep {
    fn noise(&self) -> &str {
        "baaaaah"
    }
}

impl Animal for Cow {
    fn noise(&self) -> &str {
        "moo"
    }
}

fn random_animal(num: f64) -> Box<dyn Animal> {
    if num < 0.5 {
        Box::new(Sheep {})
    } else {
        Box::new(Cow {})
    }
}

pub fn main_exec() {
    let random = 0.4;
    let random_animal = random_animal(random);
    println!("{:?}", random_animal.noise());
}