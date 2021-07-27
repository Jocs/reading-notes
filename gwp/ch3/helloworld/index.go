package main

import (
	"fmt"
	"log"
	"net/http"
)

// MyHandler 处理器
type MyHandler struct{}

func (h *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello World")
}

func main() {
	handler := MyHandler{}
	server := http.Server{
		Addr:    "127.0.0.1:8880",
		Handler: &handler,
	}

	log.Fatal(server.ListenAndServe())
}
