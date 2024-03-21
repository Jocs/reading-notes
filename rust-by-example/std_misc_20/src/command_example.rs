use std::process::Command;

pub fn main_exec() {
    let output = Command::new("ls")
        .arg("-l")
        .arg("-a")
        .output()
        .expect("failed to execute process");

    println!("status: {}", output.status);

    if output.status.success() {
        println!("command executed successfully");
        println!("stdout: {}", String::from_utf8_lossy(&output.stdout));
    } else {
        println!("command failed");
        println!("stderr: {}", String::from_utf8_lossy(&output.stderr));
    }
}