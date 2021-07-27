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

	go func() { worklist <- os.Args[1:] }()

	seen := make(map[string]bool)

	for list := range worklist {
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				go func(l string) {
					worklist <- crawl(l)
				}(link)
			}
		}
	}
}
