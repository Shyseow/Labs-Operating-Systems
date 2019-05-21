#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
pid_t pid;
int n,i;

printf("Please enter the number of direct child processes to be created: ");
scanf("%d", &n);
for(i=1;i<=n; ++i){
pid=fork();
if(pid==0)
{
printf("Child %d: my pid is %d, and my ppid is %d\n",i,getpid(),getppid());
sleep(i*60);
exit(0);
}
}
waitpid(pid,NULL,0);

exit(0);
}
