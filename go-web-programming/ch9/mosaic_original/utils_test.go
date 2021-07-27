package main

import (
	"fmt"
	"image/png"
	"os"
	"testing"
)

func TestAverageColor(t *testing.T) {
	file, err := os.Open("./test_pictures/test.png")
	defer file.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
	img, err := png.Decode(file)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(averageColor(img))
}

func TestResize(t *testing.T) {
	file, err := os.Open("./test_pictures/test.png")
	defer file.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
	img, err := png.Decode(file)
	if err != nil {
		fmt.Println(err)
		return
	}
	resize(img, 500)
}
