package main

import (
	"fmt"
	"sync"
	"time"
)

func printNumber2(wg *sync.WaitGroup) {
	for i := 0; i < 10; i++ {
		time.Sleep(1 * time.Millisecond)
		fmt.Printf("%d", i)
	}
	wg.Done()
}

func printLetter2(wg *sync.WaitGroup) {
	for i := 'A'; i < 'A'+10; i++ {
		time.Sleep(1 * time.Millisecond)
		fmt.Printf("%c", i)
	}
	wg.Done()
}

func main() {
	var wg sync.WaitGroup
	wg.Add(2)
	go printNumber2(&wg)
	go printLetter2(&wg)
	wg.Wait()
}
