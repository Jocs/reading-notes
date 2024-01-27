#[derive(PartialEq, Debug)]
struct Shop {
    size: u32,
    style: String,
}

#[allow(dead_code)]
fn shops_in_my_size(shops: Vec<Shop>, size: u32) -> Vec<Shop> {
    shops.into_iter().filter(|shop| shop.size == size).collect()
}

struct Counter {
    count: u32,
}

impl Counter {
    #[allow(dead_code)]
    fn new() -> Counter {
        Counter {
            count: 1
        }
    }
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        let pre_value = self.count;
        self.count += 1;

        if pre_value < 6 {
            Some(pre_value)
        } else {
            None
        }
    }
}

#[cfg(test)]

mod test {
    use super::*;

    #[test]
    fn test_shops_in_my_size() {
        let shops = vec![
            Shop {
                size: 10,
                style: String::from("sneaker"),
            },
            Shop {
                size: 20,
                style: String::from("sandal"),
            },
            Shop {
                size: 10,
                style: String::from("boot"),
            },
        ];

        assert_eq!(
            shops_in_my_size(shops, 10),
            vec![
                Shop {
                    size: 10,
                    style: String::from("sneaker")
                },
                Shop {
                    size: 10,
                    style: String::from("boot")
                },
            ]
        );
    }

    #[test]
    fn test_struct_counter() {
        let counter = Counter::new();
        let counter_vec: Vec<u32> = counter.collect();
        assert_eq!(counter_vec, vec![1, 2, 3, 4, 5]);
    }

    #[test]
    fn test_counter() {
        let sum: u32 = Counter::new().zip(Counter::new().skip(1)).map(|(a, b)| a * b).filter(|i| i % 3 == 0).sum();


        assert_eq!(sum, 18);
    }
}
