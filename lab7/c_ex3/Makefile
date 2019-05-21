# makefile for testtoken
# the filename must be either Makefile or makefile
testex3: c_ex3.o token.o
	gcc c_ex3.o token.o -o ex3

c_ex3.o: c_ex3.c token.h
	gcc -c c_ex3.c

token.o: token.c token.h
	gcc -c token.c

clean:
	rm *.o
