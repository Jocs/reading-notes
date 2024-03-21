// Drop trait 只有一个方法：drop，当对象离开作用域的时候会自动调用这个方法。

struct Droppable {
    name: &'static str,
}

impl Drop for Droppable {
    fn drop(&mut self) {
        println!("Dropping {}", self.name);
    }
}

pub fn main_exec() {
    let outer = Droppable { name: "outer" };

    {
        // block scope a
        let _a = Droppable { name: "a" };
        {
            // block scope b
            let _b = Droppable { name: "b" };
            println!("existing b");
        }
        println!("existed b");
        println!("existing a");
    }
    println!("existed a");
    
    drop(outer);

    println!("main function end");
}