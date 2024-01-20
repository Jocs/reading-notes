use core::str;

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

pub fn greeting(name: &str) -> String {
    format!("Hello, {}!", name)
}

#[derive(Debug)]
pub struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    pub fn area(&self) -> u32 {
        self.width * self.height
    }

    pub fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

pub struct Guess {
    value: u32,
}

impl Guess {
    pub fn new(value: u32) -> Guess {
        if value < 10 || value > 100 {
            panic!("Guess value must be between 10 and 100, got {}.", value);
        }
        Guess { value }
    }

    pub fn value(&self) -> u32 {
        self.value
    }

    pub fn is_less_than(&self, val: u32) -> bool {
        self.value < val
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }

    #[test]
    fn test_area() {
        let rectangle_1 = Rectangle { width: 30, height: 50 };
        let rectangle_2 = Rectangle { width: 10, height: 40 };

        assert!(rectangle_1.can_hold(&rectangle_2));
        assert!(!rectangle_2.can_hold(&rectangle_1));

        assert!(rectangle_1.area() == 1500);
        assert!(rectangle_2.area() == 400);
    }

    #[test]

    fn test_greeting() {
        let name = "Jocs";

        let result = greeting(name);

        assert!(result.contains("Jocs"), "Something went wrong, and the value is \"{}\"", result);
    }

    #[test]
    #[should_panic]
    fn test_guess() {
        Guess::new(200);
    }
}
