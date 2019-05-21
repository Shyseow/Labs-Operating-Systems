#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COMMAND_LINE_SIZE 1024

int main(int argc, char *argv[]){
char command[COMMAND_LINE_SIZE];
pid_t pid;

while(1){
 printf("$ ");
 scanf("%s",command);
 getchar();

 if (strcmp(command,"bye")==0)
  break;
 else{
 if ((pid=fork())<0){
    perror("fork");
    exit(1);
    }
  else if (pid==0){
    execlp(command,command,NULL);
    }
}
waitpid(pid,NULL,0);
}
return 0;
}
