// 允许没有使用的代码
#[allow(dead_code)]
fn un_used_function() {
    println!("This function is not used");
}

fn used_function() {
    println!("This function is used");
}

pub fn main_exec() {
    used_function();
}