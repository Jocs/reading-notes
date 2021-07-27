package main

import (
	"fmt"
	"net/http"
)

// HelloHandler 处理器
type HelloHandler struct{}

func (h *HelloHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello!")
}

func log(h http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		fmt.Printf("Handler called - %T", h)
		h.ServeHTTP(w, r)
	})
}

func main() {
	handler := HelloHandler{}
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}
	http.Handle("/hello", log(&handler))

	server.ListenAndServe()
}
