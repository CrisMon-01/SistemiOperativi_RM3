#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#define max 10

void handler(int sign){
	if(sign==SIGUSR1){
		printf("processo attivo %d\n", getpid());	
	}
	else
		printf("processo non attivo %d\n",getpid());
	exit(0);
	}

int main(int argc,int *argv[]){
	pid_t pid [10];
	int i,status;

	for(i=0;i<atoi(argv[1]);i++){
		pid[i] = fork();
		if(pid[i]<0){
		perror("err");
		exit(2);
		}
		else if(pid[i] == 0){
			signal(SIGUSR1,handler);
			signal(SIGUSR2,handler);
			pause();	//wait per aspettare padre						
				
		}
		else {
		printf("Creato processo figlio %d \n", pid[i]);
		printf("Attivare il processo creato? [y/n]\n");
		char c = getchar();
		if(c=='y')	kill(pid[i],SIGUSR1);
		else kill(pid[i],SIGUSR2);
		 c = getchar();
		wait(&status);		
	}
	}	

}
