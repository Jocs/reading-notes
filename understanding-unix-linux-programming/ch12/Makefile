server: webserver.o socklib.o common.h
	gcc -o server webserver.o socklib.o

webserver.o: webserver.c common.h
	gcc -c webserver.c common.h

socklib.o: socklib.c common.h
	gcc -c socklib.c common.h

clean:
	-rm server webserver.o socklib.o