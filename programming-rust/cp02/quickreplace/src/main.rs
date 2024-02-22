use text_colorizer::*;
use std::fs;
use regex::Regex;

#[derive(Debug)]
struct Arguments {
    target: String,
    replacement: String,
    filename: String,
    output: String,
}

fn main() {
    let args = parse_args();

    let data = match fs::read_to_string(&args.filename) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("quickreplace: error: could not read file '{}': {}", args.filename, e);
            std::process::exit(1);
        }
    };

    let content = match replace(&args.target, &args.replacement, &data) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("quickreplace: error: could not replace text: {}", e);
            std::process::exit(1);
        }
    };

    match fs::write(&args.output, &content) {
        Ok(_) => {
            println!("quickreplace: successfully wrote to file '{}'", args.output);
        },
        Err(e) => {
            eprintln!("quickreplace: error: could not write to file '{}': {}", args.output, e);
            std::process::exit(1);
        }
    }
}

fn parse_args() -> Arguments {
    let args: Vec<String> = std::env::args().skip(1).collect();

    if args.len() != 4 {
        print_usage();
        eprintln!("quickreplace: error: incorrect number of arguments, expected 4 but got {}", args.len());
        std::process::exit(1);
    }

    Arguments {
        target: args[0].clone(),
        replacement: args[1].clone(),
        filename: args[2].clone(),
        output: args[3].clone(),
    }
}

fn replace(target: &str, replacement: &str, text: &str) -> Result<String, regex::Error> {
    let regex = Regex::new(target)?;
    let content = regex.replace_all(text, replacement);

    Ok(content.to_string())
}

fn print_usage() {
    eprintln!("{} - change occurrences of one string into another", "quickreplace".green());
    eprintln!("Usage: quickreplace <target> <replacement> <filename> <output>");
}
