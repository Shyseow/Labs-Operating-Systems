#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
Stack *s;
int i;

s= create_stack();
for (i=0; i<argc; ++i)
push_stack(s, argv[i]);
printf("there are %d strings in the stack\n", size_of_stack(s));
while (!empty_stack(s))
printf("Stack item: %s\n", pop_stack(s));
printf("now there are %d strings in the stack\n", size_of_stack(s));
exit(0);
}

