use adder;

#[test]
fn test_guess() {
    let guess = adder::Guess::new(50);

    assert!(guess.value() == 50);
}