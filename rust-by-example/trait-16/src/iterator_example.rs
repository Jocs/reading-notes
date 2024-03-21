// for 结构会使用 .into_iter() 方法将一些集合类型转为迭代器
// into_iter() 和 iter() 方法的区别
// into_iter() -> 取得所有权
// iter() -> 引用
// iter_mut() -> 可变引用

struct Fibonacci {
    cur: u32,
    next: u32,
}

impl Iterator for Fibonacci {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        let new_next = self.cur + self.next;

        self.cur = self.next;
        self.next = new_next;

        Some(self.cur)
    }
}

fn fibonacci() -> Fibonacci {
    Fibonacci { cur: 0, next: 1 }
}

pub fn main_exec() {
    let f = fibonacci();
    for num in f.skip(10).take(10) {
        println!("{}", num);
    }
}