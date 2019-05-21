# makefile for testtoken
# the filename must be either Makefile or makefile
testex2: c_ex2.o command.o
	gcc c_ex2.o command.o -o testex2

c_ex2.o: c_ex2.c command.h
	gcc -c c_ex2.c

command.o: command.c command.h
	gcc -c command.c

clean:
	rm *.o
