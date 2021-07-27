package main

import (
	"fmt"
	"net/http"
)

// 处理器函数
func headers(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, r.Header["Accept"])
}

func main() {
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}

	http.HandleFunc("/headers", headers)

	server.ListenAndServe()
}
