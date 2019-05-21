#include <stdlib.h> //for exit
#include <stdio.h>  //for printf

int main(void)
{
char *fname = "test_file";
FILE *fstr;

fstr = fopen (fname, "w+");
if(fstr == NULL){
fprintf(stderr, "Cannot open file %s, terminate program\n",fname);
exit(1);
}
int day = 8;
char *month = "August";
int year = 2006;
fprintf(fstr, "Today is %04d %s %d.\n",day,month,year);
fclose(fstr);
exit(0);
}