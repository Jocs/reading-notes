FROM golang

ADD . /go/src/gwp/ch7/web
WORKDIR /go/src/gwp/ch7/web

RUN go get github.com/lib/pq
RUN go install gwp/ch7/web

ENTRYPOINT /go/bin/web

EXPOSE 8080