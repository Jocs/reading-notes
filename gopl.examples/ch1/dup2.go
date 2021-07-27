package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	consts := make(map[string]int)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, consts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, consts)
			f.Close()
		}
	}

	for line, n := range consts {
		if n > 1 {
			fmt.Printf("%d\t%s\n", n, line)
		}
	}
}

func countLines(f *os.File, consts map[string]int) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		consts[input.Text()]++
	}
}
