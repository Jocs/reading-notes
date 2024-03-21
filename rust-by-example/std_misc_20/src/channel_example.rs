use std::thread;
use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;

static NTHREADS: u32 = 10;

pub fn main_exec() {
    let (tx, rx): (Sender<u32>, Receiver<u32>) = mpsc::channel();

    for id in 0..NTHREADS {
        let thread_rx = tx.clone();

        thread::spawn(move || {
            thread_rx.send(id).unwrap();
        });
    }

    let mut ids = Vec::with_capacity(NTHREADS as usize);
    for _ in 0..NTHREADS {
        let id = rx.recv().unwrap();
        ids.push(id);
    }

    println!("{:?}", ids);
}