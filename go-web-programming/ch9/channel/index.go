package main

import (
	"fmt"
	"time"
)

func printNumber(c chan bool) {
	for i := 0; i < 10; i++ {
		time.Sleep(1 * time.Millisecond)
		fmt.Printf("%d", i)
	}
	c <- true
}

func printLetter(c chan bool) {
	for i := 'A'; i < 'A'+10; i++ {
		time.Sleep(1 * time.Microsecond)
		fmt.Printf("%c", i)
	}
	c <- true
}

// ABCDEFGHIJ0123456789% 为什么是这个结果？？？
func main() {
	c1, c2 := make(chan bool), make(chan bool)
	go printNumber(c1)
	go printLetter(c2)
	<-c1
	<-c2
}
