pub trait Summary {
    fn summary(&self) -> String;

    fn print_date(&self) -> String {
        let date = String::from("2018-03-21");

        format!("Summary is: {} and date is: {}", self.summary(), date)
    }
}

struct Article {
    title: String,
    author: String,
    content: String,
}

impl Summary for Article {
    fn summary(&self) -> String {
        let mut s = self.title.clone();

        s.push_str(" by ");

        s.push_str(&self.author);

        s.push_str(" says: ");

        s.push_str(&self.content[..10]);

        s.push_str("...");

        s
    }
}

pub fn notify(item: impl Summary) {
    println!("Breaking news: {}", item.print_date());
}

fn main() {
    println!("Hello, world!");

    let article = Article {
        title: String::from("Rust"),
        author: String::from("jocs"),
        content: String::from("Rust is a language"),
    };

    println!("The summary is: {}", article.summary());
    println!("{}", article.print_date());

    notify(article);
}
