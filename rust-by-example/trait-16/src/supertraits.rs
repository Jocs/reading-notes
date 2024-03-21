trait Person {
    fn name(&self) -> &'static str;
}

trait Student: Person {
    fn university(&self) -> &'static str;
}

struct Me {
    name: &'static str,
}

impl Person for Me {
    fn name(&self) -> &'static str {
        self.name
    }
}

impl Student for Me {
    fn university(&self) -> &'static str {
        "USTC"
    }
}

pub fn main_exec() {
    let me = Me { name: "Kevin" };
    println!("{}, {}", me.name(), me.university());
}



