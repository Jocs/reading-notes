package main

import (
	"database/sql"

	_ "github.com/lib/pq"
)

type Text interface {
	fetch(id int) (err error)
	create() (err error)
	update() (err error)
	delete() (err error)
}

type Post struct {
	Db      *sql.DB
	Id      int    `json:"id"`
	Content string `json:"content"`
	Author  string `json:"author"`
}

func (post *Post) fetch(id int) (err error) {
	err = post.Db.QueryRow("SELECT id, content, author FROM posts WHERE id = $1", id).Scan(&post.Id, &post.Content, &post.Author)
	return
}

func (post *Post) create() (err error) {
	statement := "INSERT INTO posts (content, author) VALUES ($1, $2) RETURNING id"
	stmt, err := post.Db.Prepare(statement)
	if err != nil {
		return
	}
	defer stmt.Close()
	err = stmt.QueryRow(post.Content, post.Author).Scan(&post.Id)
	return
}

func (post *Post) update() (err error) {
	_, err = post.Db.Exec("UPDATE posts SET content = $2, author = $3 WHERE id = $1", post.Id, post.Content, post.Author)
	return
}

func (post *Post) delete() (err error) {
	_, err = post.Db.Exec("DELETE FROM posts WHERE id = $1", post.Id)
	return
}
