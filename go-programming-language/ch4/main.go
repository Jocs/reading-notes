package main

import (
	"fmt"
	"log"
	"os"

	"gopl.io/ch4/append"
	"gopl.io/ch4/github"
	"gopl.io/ch4/mymap"
	"gopl.io/ch4/myslice"
	"gopl.io/ch4/mystruct"
)

func main() {
	var x, y []int
	for i := 0; i < 10; i++ {
		y = append.AppendInt(x, i)
		fmt.Printf("%d cap=%d\t%v\n", i, cap(y), y)
		x = y
	}

	stringList := []string{"slice", "map", "array", ""}

	fmt.Println(myslice.Noempty(stringList))
	fmt.Println(myslice.NoEmpty2(stringList))
	fmt.Println(myslice.Remove(stringList, 0))
	fmt.Println(stringList)

	map1 := map[string]int{"age": 12}
	map2 := map[string]int{"age": 12}
	fmt.Println(mymap.Equal(map1, map2))
	// mymap.CharCount()
	fmt.Println(mystruct.Sort([]int{5, 4, 7, 1, 9, 0, 12, 34, 56}))

	result, err := github.SearchIssues(os.Args[1:])
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%d issue:\n", result.TotalCount)
	for _, item := range result.Items {
		fmt.Printf("#%-5d %9.9s %.55s\n", item.Number, item.User.Login, item.Title)
	}
}
