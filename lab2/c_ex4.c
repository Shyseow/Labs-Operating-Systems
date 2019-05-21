#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

int main(void)
{
char line [BUFSIZE];

char reverse, temp;
printf("Please enter a line: ");
fgets(line,BUFSIZE, stdin);

int i = 0;
int index = strlen(line)-1;

while (i < index)
{
temp=line[i];
line[i]=line[index];
line[index]=temp;
i++;
index--;
}

printf("Reverse output is %s\n", line);
exit(0);
}