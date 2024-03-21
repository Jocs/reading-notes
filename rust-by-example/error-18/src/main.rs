mod panic_example;
mod question_mark;
mod map_example;
mod add_then_example;
mod result_map;
mod option_result;
mod custom_error;
mod iter_result;

// 18.4.3 ~ 18.4.5 还需要再看一遍

fn main() {
    panic_example::main_exec();
    question_mark::main_exec();
    map_example::main_exec();
    add_then_example::main_exec();
    result_map::main_exec();
    option_result::main_exec();
    custom_error::main_exec();
    iter_result::main_exec();
}
