package main

import (
	"log"
	"net/http"

	"gopl.io/ch3/surface"
)

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func handler(w http.ResponseWriter, r *http.Request) {
	// fmt.Fprintf(w, "URL.Path = %q\n", r.URL.Path)
	w.Header().Set("Content-Type", "image/svg+xml")
	surface.Output(w)
}
