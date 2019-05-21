#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	char dirname[256];
	DIR *dp;
	struct dirent *direntp;
	if (argc == 1) /* list the current directory */
		strcpy(dirname, ".");
	else
		strcpy(dirname, argv[1]);
	if ((dp = opendir(dirname)) == NULL) {
		printf("Error in opening directory %s\n",
			dirname);
		exit(1);
	}
	while (( direntp=readdir(dp)) != NULL)
		printf(" file name = %s, i-node number=%ld\n", 
			direntp->d_name, direntp->d_ino);
	closedir(dp);
	exit(0);
}
