macro_rules! test {
    ($left:expr; and $right:expr) => (
        println!("{:?} and {:?} = {:?}", stringify!($left), stringify!($right), $left && $right);
    );
    ($left:expr; or $right:expr) => (
        println!("{:?} or {:?} = {:?}", stringify!($left), stringify!($right), $left || $right);
    );
}

pub fn main_exec() {
    test!(true; and true);
    test!(true; or false);
}