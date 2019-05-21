
#include <stdlib.h>
#include <stdio.h>
void fillArray(int array[], int arraySize);
int main(void)
{
int ai[10];
fillArray(ai,10);
exit(0);
}

void fillArray (int array[], int arraySize)
{
int i;
for(i=0; i<arraySize; ++i)
{
int temp;
printf("Enter an integer value: ");
scanf("%d", &temp);
array[i] = temp;
}
}