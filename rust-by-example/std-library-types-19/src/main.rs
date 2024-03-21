mod box_example;
mod vec_example;
mod string_example;
mod hashmap_example;
mod hashset_example;
mod rc_example;

fn main() {
    println!("Hello, world!");
    box_example::main_exec();
    vec_example::main_exec();
    string_example::main_exec();
    hashmap_example::main_exec();
    hashset_example::main_exec();
    rc_example::main_exec();
}
