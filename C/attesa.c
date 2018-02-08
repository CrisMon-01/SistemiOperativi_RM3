#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){
  int status;
  pid_t pid = fork();
  if(pid<0)
  {
    perror("error fork\n");
    exit(2);
  }
  if(pid==0){
    printf("sono filgio pid: %d \n quello di mio padre : %d \n",getpid(), getppid());
    exit(24);
  }
  else {
    wait(&status);
      printf("pid figlio %d \nha terminato con: %d \n", pid,WEXITSTATUS(status));
	exit(0);
  }
  }
