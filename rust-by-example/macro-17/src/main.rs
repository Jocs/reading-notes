/// 宏不产生函数调用，而是展开成源码。宏展开为 AST 树
/// 宏的作用：
/// 1. 减少重复代码 DRY
/// 2. 领域专用语言 DSL
/// 3. 可变接口 variadic interface（接受不定参数的接口，类似 JavaScript 的 rest 参数）

mod designator_example;
mod overload_example;
mod repeat_example;
mod dsl_example;
mod params_example;

macro_rules! say_hello {
    () => {
        println!("hello macro");
    };
}
fn main() {
    say_hello!();

    designator_example::main_exec();
    overload_example::main_exec();
    repeat_example::main_exec();
    dsl_example::main_exec();
    params_example::main_exec();
}
