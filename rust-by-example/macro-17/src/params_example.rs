macro_rules! calculate {
    (eval $e:expr) => {{
        {
            let value: usize = $e;
            println!("calculate value: {:?} => {:?}", stringify!($e), value);
        }
    }};
    (eval $e:expr, $(eval $es:expr),+) => {{
        calculate! { eval $e }
        calculate! { $(eval $es),+ }
    }};
}

pub fn main_exec() {
    calculate! { eval 10 * 10 };
    calculate! { eval 10 + 10, eval 10 - 10 };
}