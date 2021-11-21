.PHONY:  clean

objects = smsh1.o execute.o splitline.o

smsh1: ${objects}
	gcc -o smsh1 ${objects}

smsh1.o: smsh.h
execute.o:
splitline.o: smsh.h

clean:
	@echo "Cleaning up..."
	-rm smsh1 ${objects}