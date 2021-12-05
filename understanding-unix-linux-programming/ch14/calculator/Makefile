server: server.o socklib.o cJSON.o common.h cJSON.h
	gcc -o server server.o socklib.o cJSON.o

server.o: server.c common.h
	gcc -c server.c common.h

socklib.o: socklib.c common.h
	gcc -c socklib.c common.h

cJSON.o: cJSON.c cJSON.h
	gcc -c cJSON.c cJSON.h

clean:
	-rm server server.o cJSON.o socklib.o