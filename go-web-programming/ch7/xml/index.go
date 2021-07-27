package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"os"
)

type Post struct {
	XMLName xml.Name `xml:"post"`
	Id      string   `xml:"id,attr`
	Content string   `xml:"content"`
	Author  Author   `xml:"author"`
	Xml     string   `xml:,innerxml`
}

type Author struct {
	Id   string `xml:"id,attr"`
	Name string `xml:,chardata`
}

func main() {
	xmlFile, err := os.Open("ch7/xml/post.xml")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer xmlFile.Close()

	data, err := ioutil.ReadAll(xmlFile)
	if err != nil {
		fmt.Println(err)
		return
	}
	var post Post
	xml.Unmarshal(data, &post)
	fmt.Println(post)
}
