#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
pid_t pid;
int status;
pid = fork();

if(pid == 0)
{
printf("I am the child, and my pid is %d\n", getpid());
exit(10);
}
else if(pid>0);
{
printf("I am the parent, and my pid is %d\n", getpid());
waitpid(pid, &status, 0);
printf("The child has terminated with exit status %d\n",WEXITSTATUS(status));
}
exit(0);
}