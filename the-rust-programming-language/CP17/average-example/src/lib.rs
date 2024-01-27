use std::collections::HashSet;

pub struct AverageCollection {
    set: HashSet<i32>,
    average: f64,
}

impl AverageCollection {
    pub fn new() -> AverageCollection {
        AverageCollection {
            set: HashSet::new(),
            average: 0.0,
        }
    }

    pub fn add(&mut self, num: i32) {
        self.set.insert(num);
        self.update_average();
    }

    pub fn remove(&mut self, value: &i32) {
        self.set.remove(value);

        self.update_average();
    }

    pub fn average(&self) -> f64 {
        self.average
    }

    fn update_average(&mut self) {
        // iter 和 to_iter 的区别？
        let sum: i32 = self.set.iter().sum();

        self.average = sum as f64 / self.set.len() as f64
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_average_collection() {
        let mut collection = AverageCollection::new();

        collection.add(1);
        collection.add(2);
        collection.add(3);

        assert_eq!(collection.average(), 2.0);

        collection.remove(&3);

        assert_eq!(collection.average(), 1.5);
    }
}