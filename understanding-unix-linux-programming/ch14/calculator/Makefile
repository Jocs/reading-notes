server: server.o socklib.o common.h
	gcc -o server server.o socklib.o

server.o: server.c common.h
	gcc -c server.c common.h

socklib.o: socklib.c common.h
	gcc -c socklib.c common.h

clean:
	-rm server server.o socklib.o