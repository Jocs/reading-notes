use average_example::AverageCollection;

fn main() {
    let mut average_collection = AverageCollection::new();

    average_collection.add(1);
    average_collection.add(2);
    average_collection.add(3);
    average_collection.remove(&3);

    let average = average_collection.average();

    println!("The average is {}", average);
}


