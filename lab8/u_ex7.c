#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void catch(int signo)
{
	printf("Signal %d caught\n", signo);
	sleep (4);
	printf("Signal %d returns\n", signo);
}
int main()
{
	int i;
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = catch;
	sigfillset( & (act.sa_mask) ); // to block all
	if (sigaction(SIGINT, &act, NULL) != 0) {
		perror("sigaction"); exit(1);
	}
	for (i=0; i<10; ++i) {
		printf("sleep %d ....\n", i); sleep (1);
	}
	exit(0);
}
