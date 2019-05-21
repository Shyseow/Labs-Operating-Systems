teststack: test_stack.o stack.o
	gcc test_stack.o stack.o -o teststack
test_stack.o: test_stack.c stack.h
	gcc -c test_stack.c
stack.o: stack.c stack.h
	gcc -c stack.c
clean:
	rm *.o
