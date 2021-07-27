package main

import (
	"fmt"
	"log"
	"os"

	"gopl.io/ch5/outline"
)

var tokens = make(chan struct{}, 20)

func crawl(url string) []string {
	fmt.Println(url)
	tokens <- struct{}{}
	links, err := outline.Extract(url)
	<-tokens
	if err != nil {
		log.Print(err)
	}
	return links
}

func main() {
	worklist := make(chan []string)
	var n int
	seen := make(map[string]bool)
	n++
	go func() { worklist <- os.Args[1:] }()

	for ; n > 0; n-- {
		list := <-worklist
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				n++
				go func(l string) {
					worklist <- crawl(l)
				}(link)
			}
		}
	}
}
