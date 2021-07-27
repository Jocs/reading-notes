package main

import (
	"fmt"
	"log"
	"os"

	"gopl.io/ch5/outline"
)

func crawl(url string) []string {
	fmt.Println(url)
	list, err := outline.Extract(url)
	if err != nil {
		log.Print(err)
	}

	return list
}

func main() {
	worklist := make(chan []string)
	unseenLiks := make(chan string)

	go func() { worklist <- os.Args[1:] }()
	for i := 0; i < 20; i++ {
		go func() {
			for link := range unseenLiks {
				foundLinks := crawl(link)
				go func() { worklist <- foundLinks }()
			}
		}()
	}

	seen := make(map[string]bool)

	for list := range worklist {
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				unseenLiks <- link
			}
		}
	}
}
