#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define BUFSIZE 512
char *msg = "Hello";
int main()
{
	char buf[BUFSIZE];
	int p[2], pid;
	if (pipe(p) < 0) {
		perror ("pipe call"); exit(1);
	}
	if ((pid=fork()) < 0) {
		perror("Fork call"); exit(1);
	}

	if (pid > 0) { // parent
		read (p[0], buf, BUFSIZE);
		printf("%s\n", buf);
	}
	if (pid == 0) { // child
		close (p[0]);
		write (p[1], msg, strlen(msg) + 1);
		//wait ((int *) 0);
		sleep(10);
		close (p[1]);
		printf("write closed\n");
		sleep(10);
		printf("Child terminated\n");
		exit(0);
	}
	exit(0);
}
