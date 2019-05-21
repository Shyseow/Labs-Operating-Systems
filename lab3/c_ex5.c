#include <stdlib.h> //for exit
#include <stdio.h>  //for scanf

#define BUF_SIZE 4

int main(void)
{
int date;
char month[BUF_SIZE];
int year;
printf("Please enter the date in the form of date-short_month-year, ");
printf("such 8-August-2006, where a month is written in exactly three letters: ");
scanf("%d-%3s-%d", &date,month,&year);
printf("the date you entered was: %d-%s-%d\n",date,month,year);
exit(0);
}