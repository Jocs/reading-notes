package main

import (
	"bytes"
	"fmt"
	"unicode/utf8"

	"gopl.io/ch3/basename"
	"gopl.io/ch3/mystrings"
)

func intsToString(values []int) string {
	var buf bytes.Buffer
	buf.WriteByte('[')
	for i, v := range values {
		if i > 0 {
			buf.WriteString(", ")
		}
		fmt.Fprintf(&buf, "%d", v)
	}

	buf.WriteByte(']')
	return buf.String()
}

func printChar() {
	s := "Hello, 世界"
	fmt.Println(len(s))
	fmt.Println(utf8.RuneCountInString(s))

	for i := 0; i < len(s); {
		r, size := utf8.DecodeRuneInString(s[i:])
		fmt.Printf("%d\t%c\n", i, r)
		i += size
	}

	for i, r := range s {
		fmt.Printf("%d\t%q\t%d\n", i, r, r)
	}
}

func main() {
	s := "abc"
	p := "ab"

	fmt.Println(basename.Basename("a/b/c.d.go"))
	printChar()
	println(intsToString([]int{1, 2, 3}))
	fmt.Printf("%t\n", mystrings.HasPrefix(s, p))
	fmt.Printf("%t\n", mystrings.HasSuffix(s, p))
	fmt.Printf("%t\n", mystrings.Contains(s, p))
}
