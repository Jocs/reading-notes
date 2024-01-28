use std::mem;

// 此函数借用一个 slice
fn analyze_slice(slice: &[i32]) {
    println!("first element of the slice: {}", slice[0]);
    println!("the slice has {} elements", slice.len());
}

fn main() {
    let xs = [1, 2, 3, 4, 5];

    println!("array occupies {} bytes", mem::size_of_val(&xs)); // 20 个字节

    analyze_slice(&xs);
    analyze_slice(&xs[1..4]);
}
