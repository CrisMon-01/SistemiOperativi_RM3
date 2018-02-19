#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int stat;
	pid = fork();
	if(pid == 0){
		printf("SONO IL FIGLIO PID: %d\n",getpid());
		exit(1);
	}
	else {
		printf("SONO IL PADRE MIO ATTUALE PID: %d\n",getpid());
		wait(&stat);
		printf("PID DOPO ATTESA FIGLIO:%d\n",getpid());
	}
}
