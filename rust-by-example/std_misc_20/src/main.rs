mod thread_example;
mod sum_example;
mod channel_example;
mod path_example;
mod open_file;
mod write_file;
mod read_lines;
mod command_example;
mod extern_example;
mod args_example;
mod wait;

fn main() {
    println!("Hello, world!");
    thread_example::main_exec();
    sum_example::main_exec();
    channel_example::main_exec();
    path_example::main_exec();
    open_file::main_exec();
    write_file::main_exec();
    read_lines::main_exec();
    command_example::main_exec();
    extern_example::main_exec();
    args_example::main_exec();
    wait::main_exec();
}
