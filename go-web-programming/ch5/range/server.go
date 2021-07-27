package main

import (
	"html/template"
	"net/http"
)

func iterater(w http.ResponseWriter, r *http.Request) {
	weekDays := []string{"Mon", "Tue", "Wen"}
	t, _ := template.ParseFiles("ch5/range/tmpl.html")
	t.Execute(w, weekDays)
}

func main() {
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}

	http.HandleFunc("/range", iterater)

	server.ListenAndServe()
}
