#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int status;
pid = fork();
if(pid<0){
	perror("err");
	exit(2);
}
else if(pid>0){
	wait(&status);
	printf("IL FIGLIO %d HA TERMINATO CON STATUS %d\n",pid,status/256);
	}
	else {
		printf("SONO IL FIGLIO CON PID: %d MIO PADRE È: %d\n",getpid(),getppid());
		exit(24);
	}
}
