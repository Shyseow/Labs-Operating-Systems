#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void catch(int signo)
{
	if(signo == SIGCHLD)
		printf("The child %d has been been terminated\n", getpid() );
	if(signo == SIGALRM)
		printf("The alarm clock has expired\n");
	if(signo == SIGINT)
		printf("Signal %d received\n", signo);
}
int main()
{
	int i;
	struct sigaction act;
	pid_t pid;

	act.sa_flags = 0;
	act.sa_handler = catch;
	
	sigaction(SIGINT, &act, 0);
	sigaction(SIGALRM, &act, 0);
	sigaction(SIGCHLD, &act, 0);

	pid = fork();
	if(pid == 0){
		sleep(10);
		exit(0);
	}
	else
		alarm(20);
	
	i = 1;
	while(1){
		printf("sleep %d ....\n", i); sleep (1); i++;
	}
	exit(0);
}
