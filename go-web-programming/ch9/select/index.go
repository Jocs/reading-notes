package main

import "fmt"

func callerA(c chan string) {
	c <- "Hello world from caller A"
	close(c)
}

func callerB(c chan string) {
	c <- "Hello world from caller B"
	close(c)
}

func main() {
	a, b := make(chan string), make(chan string)
	go callerA(a)
	go callerB(b)
	var msg string
	ok1, ok2 := true, true
	for ok1 || ok2 {
		select {
		case msg, ok1 = <-a:
			if ok1 {
				fmt.Println(msg)
			}
		case msg, ok2 = <-b:
			if ok2 {
				fmt.Println(msg)
			}
		}
	}
}
