package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	consts := make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		consts[input.Text()]++
	}

	for line, n := range consts {
		if n > 1 {
			fmt.Println("%d\t%s\n", n, line)
		}
	}
}
