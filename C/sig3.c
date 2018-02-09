#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

typedef char stringa[20];
void handler(int signal){
	if(signal==SIGUSR1){
		printf("SONO ATTIVO\n");
		exit(0);
	}
	else {
     	printf("NON SONO ATTIVO\n");
	exit(0);
	}
}

int main(int argc,char *argv[]){
pid_t pid [argc-1];
int i,j,status;
for(i=0;i<argc-1;i++){
	pid[i] = fork();
	if(pid[i]<0){
		perror("err");
		exit(9);
	}
	else if(pid[i]==0){
		pid_t attuale = getpid();
		if(attuale%2==0){
			if(getppid()%2==1)
				signal(SIGUSR1,handler);
			else signal(SIGUSR2,handler);					
		}
		else{
			if(getppid()%2==0)
				signal(SIGUSR1,handler);
			else signal(SIGUSR2,handler);					

		}
//		signal(SIGUSR1,handler);
//		signal(SIGUSR2,handler);
		pause();
		stringa s = "./";
		strcat(s,argv[0]);
		execlp(s,argv[i],NULL);
		exit(1);
	}
	else{
		pid_t corrente = getpid();
		if(corrente%2!=0)
		for(j=1;j<argc-1;j++){
			kill(pid[i],SIGUSR1);		
		}
		else 
			for(j=1;j<argc-1;j++){
			kill(pid[i],SIGUSR2);			
			}
		wait(&status);
	}
}

	
}
