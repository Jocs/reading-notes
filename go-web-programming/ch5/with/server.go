package main

import (
	"html/template"
	"net/http"
)

func reverse(s string) string {
	ss := []byte(s)
	len := len(ss)
	for i := 0; i < (len+1)/2; i++ {
		ss[i], ss[len-1-i] = ss[len-1-i], s[i]
	}
	return string(ss)
}

func with(w http.ResponseWriter, r *http.Request) {
	funcMap := template.FuncMap{"reverse": reverse}
	t := template.New("tmpl.html").Funcs(funcMap)
	t, _ = t.ParseFiles("ch5/with/tmpl.html")
	t.Execute(w, "wujingwen")
}

func main() {
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}

	http.HandleFunc("/with", with)

	server.ListenAndServe()
}
