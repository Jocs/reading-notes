use colored::*;

fn main() {
    println!("Hello, world!");

    println!("{} days", 31);

    println!("{0}, {1}, {1}, {0}", "hello", "world");

    // 可以使用命名参数，中间也可以使用换行符
    println!(
        "title: {title}\nauthor: {author}",
        title = "飞驰人生2",
        author = "韩寒"
    );

    // 可以在 ':' 后面定制特殊格式
    println!(
        "{} of {:b} peoples know binary, the other half doesn't",
        1, 2
    );

    // 指定宽度
    println!("{number:>width$}", number = 1, width = 6);
    println!("{number:>0width$}", number = 1, width = 6);

    #[allow(dead_code)]
    #[derive(Debug)]
    struct Structure(i32);

    println!("Structure: {:?}", Structure(3));

    let pi = 3.141592;

    println!("Pi is roughly {:.3}", pi);

    println!(
        "The color is {}, and this is {}",
        "red".on_bright_blue().bright_red(),
        "green and bold".green().bold().underline().italic().blink()
    );
}
