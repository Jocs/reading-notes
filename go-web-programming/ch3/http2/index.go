package main

import (
	"fmt"
	"net/http"

	"golang.org/x/net/http2"
)

// MyHandler 处理器
type MyHandler struct{}

func (h *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello world http2")
}

func main() {
	hello := MyHandler{}
	server := http.Server{
		Addr:    "127.0.0.1:8080",
		Handler: &hello,
	}
	http2.ConfigureServer(&server, &http2.Server{})
	server.ListenAndServeTLS("cert.pem", "key.pem")
}
