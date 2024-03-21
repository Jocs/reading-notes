macro_rules! calculate {
    (cal $x:expr) => {
        let value: usize = $x;
        println!("calculate value: {:?} => {:?}", stringify!($x), value);
    }
}

// 比如可以通过自定义 json_to_html! 宏来实现 json 转 html 的功能。

pub fn main_exec() {
    calculate!(cal 10 * 10);
}