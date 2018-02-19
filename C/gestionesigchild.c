#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int signal){
	if(signal == SIGCHLD){
		printf("RIPRENDO DOPO LA MORTE DI MIO FIGLIO\n");		
		}
	}

int main(){
	pid_t pid;
	int status;
	signal(SIGCHLD,handler);
	pid = fork();
	if(pid<0){exit(9);}
	else if(pid==0){
		sleep(3);
		printf("SONO IL FIGLIO\n");
		exit(1);
	}
	else{
	printf("SONO IL PADRE\n");
	pause();
	}
}
