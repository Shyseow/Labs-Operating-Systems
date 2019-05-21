#include<stdio.h>
#include<stdlib.h>

void fillArray(int array[], int arraySize);
int *getArray(int aSize);

int main(void)
{
int *pi;
int aSize;
printf("Enter the size of the array\n");
scanf("%d",&aSize);
pi=getArray(aSize);
fillArray(pi,aSize);
free(pi);
exit(0);
}

void fillArray(int array[],int arraySize)
{

int i;
for (i=0; i<arraySize; ++i){
    array[i] = i + 100;
 }

for (i=0; i<arraySize; ++i){
   printf("a[%d]=%d\n", i, array[i]);
}

}

int *getArray(int aSize){
int *array;
array=malloc(aSize * sizeof(int));
return array;
}



