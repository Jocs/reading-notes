#[cfg(target_os = "linux")]
fn are_you_on_linux() {
    println!("You are on Linux");
}

#[cfg(not(target_os = "linux"))]
fn are_you_on_linux() {
    println!("You are not on Linux");
}

pub fn main_exec() {
    are_you_on_linux();
    println!("Are you sure?");

    if cfg!(target_os = "linux") { // 注意这儿是 等号（=）而非双等号（==）
        println!("Yes I am sure you are on linux.");
    } else {
        println!("No I am not sure you are on linux.");
    }
}