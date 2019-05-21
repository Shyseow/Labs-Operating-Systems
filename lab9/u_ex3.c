#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

char *mesg="Hello, world!";
/* convert upper case to lower case or vise versa */
char conv(char c)
{
	if (islower(c)) return toupper(c);
	if (isupper(c)) return tolower(c);
	return c;
}
int main()
{
	pid_t pid, AB[2], BA[2];
	char buf[20];
	/* create two pipes */
	if (pipe(AB)<0 || pipe(BA)<0)
		perror("pipe calls"), exit(1);
	/* create process B */
	if ((pid=fork())<0)
		perror("fork call"), exit(2);
	if (pid>0) { /* process A */
		close(AB[0]); close(BA[1]); 		// L1
		printf("A sends: %s\n", mesg);
		write(AB[1], mesg, strlen(mesg));
		close(AB[1]); 						// L2
		printf("A receives: ");
		while (read(BA[0], buf, 1)==1)
			printf("%c", buf[0]);
		printf("\n"); exit(0);
	}
	if (pid==0) { /* process B */
		close(BA[0]); //close(AB[1]); 		// L3
		while (read(AB[0], buf, 1)==1) {
			buf[0] = conv(buf[0]);
			write(BA[1], buf, 1);
		}
		exit(0);
	}
}
