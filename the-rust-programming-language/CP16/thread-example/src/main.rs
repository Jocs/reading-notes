use std::thread;
use std::time::Duration;
use std::sync::mpsc;

fn main() {
    println!("Hello, world!");
    let handle = thread::spawn(|| {
        for i in 0..10 {
            println!("hi number {} from the spawned thread!", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    handle.join().unwrap();

    for i in 0..5 {
        println!("hi number {} from the main thread!", i);
        thread::sleep(Duration::from_millis(1));
    }

    let v = vec![1, 2, 3];

    let handle = thread::spawn(move || {
        println!("Here's a vector: {:?}", v);
    });

    handle.join().unwrap();

    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let v = "hello world".to_string();
        tx.send(v).unwrap();

        let another_v = vec!["rust", "is", "fun!"];

        for word in another_v {
            tx.send(word.to_string()).unwrap();
            thread::sleep(Duration::from_secs(1));
        }

        // println!("sent {:?}", another_v);
    });

    for receive in rx {
        println!("Got: {}", receive);
    } 
}
