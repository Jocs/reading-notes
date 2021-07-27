package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	data := []byte("Hello world, ransixi!\n")
	err := ioutil.WriteFile("ch6/readwritefile/data", data, 0644)
	if err != nil {
		panic(err)
	}

	read1, _ := ioutil.ReadFile("ch6/readwritefile/data")
	fmt.Println(string(read1))

	file1, _ := os.Create("ch6/readwritefile/data2")
	defer file1.Close()
	bytes, _ := file1.Write(data)
	fmt.Printf("Wrote %d bytes to file\n", bytes)

	file2, _ := os.Open("ch6/readwritefile/data2")
	defer file2.Close()
	read2 := make([]byte, len(data))
	bytes, _ = file2.Read(read2)
	fmt.Printf("Read %d bytes to file\n", bytes)
	fmt.Printf(string(read2))
}
