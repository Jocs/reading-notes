package main

import (
	"fmt"
	"log"
	"os"
	"time"

	"gopl.io/ch5/outline"
	// "gopl.io/ch5/findlinks"
	// "gopl.io/ch5/wait"
	// "gopl.io/ch5/toposort"
)

var prereqs = map[string][]string{
	"algorithms":            {"data structures"},
	"calculus":              {"linear algebra"},
	"compilers":             {"data structures", "formal languages", "computer organization"},
	"data structures":       {"discrete math"},
	"database":              {"data structures"},
	"discrete math":         {"intro to programming"},
	"formal languages":      {"discrete math"},
	"networks":              {"operating systems"},
	"operating systems":     {"data structures", "computer organization"},
	"programming languages": {"data structures", "computer organization"},
}

func breadthFirst(f func(item string) []string, worklist []string) {
	seen := make(map[string]bool)
	for len(worklist) > 0 {
		items := worklist
		worklist = nil
		for _, item := range items {
			if !seen[item] {
				seen[item] = true
				worklist = append(worklist, f(item)...)
			}
		}
	}
}

func crawl(url string) []string {
	fmt.Println(url)
	list, err := outline.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}

func trace(msg string) func() {
	start := time.Now()
	log.Printf("enter %s", msg)

	return func() {
		log.Printf("exist %s (%s)", msg, time.Since(start))
	}
}

func bigSlowOperation() {
	defer trace("bigSlowOperation")()
	time.Sleep(10 * time.Second)
}

func main() {
	// findlinks.FindLinks1()
	// outline.ShowOutLine()
	// for _, url := range os.Args[1:] {
	// 	links, err := findlinks.FindLinks2(url)
	// 	if err != nil {
	// 		fmt.Fprintf(os.Stderr, "findlinks2: %v\n", err)
	// 	}
	// 	for _, link := range links {
	// 		fmt.Println(link)
	// 	}
	// }
	// wait.WaitForServer("http://www.xeowowowowxx.com")
	// for i, course := range toposort.TopoSort(prereqs) {
	// 	fmt.Printf("%d:\t%s\n", i+1, course)
	// }
	breadthFirst(crawl, os.Args[1:])
	outline.Title("http://www.baidu.com")
	bigSlowOperation()
}
