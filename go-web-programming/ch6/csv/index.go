package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"strconv"
)

// Post 帖子
type Post struct {
	Id      int
	Content string
	Author  string
}

func main() {
	csvfile, _ := os.Create("ch6/csv/posts.csv")
	defer csvfile.Close()
	allPosts := []Post{
		Post{Id: 1, Content: "Foo", Author: "Ransixi"},
		Post{Id: 2, Content: "Bar", Author: "Wujingwen"},
		Post{Id: 3, Content: "Zar", Author: "zhenzhians"},
	}
	csvWriter := csv.NewWriter(csvfile)
	for _, post := range allPosts {
		line := []string{strconv.Itoa(post.Id), post.Content, post.Author}
		err := csvWriter.Write(line)
		if err != nil {
			panic(err)
		}
	}
	csvWriter.Flush()
	file, err := os.Open("ch6/csv/posts.csv")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	reader := csv.NewReader(file)
	reader.FieldsPerRecord = -1
	record, err := reader.ReadAll()
	if err != nil {
		panic(err)
	}

	var posts []Post
	for _, item := range record {
		id, _ := strconv.ParseInt(item[0], 0, 0)
		post := Post{Id: int(id), Content: item[1], Author: item[2]}
		posts = append(posts, post)
	}

	fmt.Println(posts[0].Id)
	fmt.Println(posts[0].Content)
	fmt.Println(posts[0].Author)
}
