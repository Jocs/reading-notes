package main

import (
	"bytes"
	"fmt"
	"io"
	"os"

	"gopl.io/ch7/bytecounter"
	"gopl.io/ch7/tempconv"
)

// var period = flag.Duration("period", 1*time.Second, "sleep period")
var temp = tempconv.CelsiusFlag("temp", 20.0, "the temperature")

func main() {
	var c bytecounter.Bytecounter
	c.Write([]byte("hello"))
	fmt.Println(c)
	c = 0
	var name = "Dolly"
	fmt.Fprintf(&c, "hello, %s", name)
	fmt.Println(c)
	// flag.Parse()
	// fmt.Printf("Sleeping for %v...", *period)
	// time.Sleep(*period)
	// fmt.Println()
	// flag.Parse()
	// fmt.Println(*temp)
	var w io.Writer
	fmt.Printf("%T\n", w)
	w = os.Stdout
	fmt.Printf("%T\n", w)
	w = new(bytes.Buffer)
	fmt.Printf("%T\n", w)
}
