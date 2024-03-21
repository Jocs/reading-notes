mod dead_code;
mod cfg_example;
mod custom_cfg;

fn main() {
    println!("Hello, world!");

    dead_code::main_exec();
    cfg_example::main_exec();
    custom_cfg::main_exec();
}
