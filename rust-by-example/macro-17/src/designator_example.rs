macro_rules! create_function {
    ($func_name:ident) => {
        fn $func_name() {
            println!("hello function, you called {:?}()", stringify!($func_name));
        }
    }
}

macro_rules! print_result {
    ($expression:expr) => {
        println!("{:?} -> {:?}", stringify!($expression), $expression);
    }
}

create_function!(hello);
create_function!(world);

pub fn main_exec() {
    hello();
    world();
    print_result!({
        let x = 1;
        x + 2
    });
}
