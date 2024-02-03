struct Foo {
    bar: u32,
}

impl Drop for Foo {
    fn drop(&mut self) {
        println!("Dropping Foo {}", &self.bar);
    }
}

fn main() {
    println!("Hello, world!");
    let foo_1 = Foo { bar: 1 };
    let foo_2 = Foo { bar: 2 };

    print!("Foo 1: {:p}\n", &foo_1); // 指针地址？
    print!("Foo 2: {:p}\n", &foo_2);

    // 提前 drop 一个值
    drop(foo_1);
    println!("Some codes after drop foo_1");
}
