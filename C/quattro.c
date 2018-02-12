#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

typedef char stringa[20];

void handler(int signal){
	if(signal==SIGUSR1){printf("SONO ATTIVO\n");}
	else{printf("SONO DISATTIVO\n");}
	}

int main(int argc, char *argv[]){
	pid_t pid[argc];
	int status,i;
	for(i = 0;i<=argc;i++){
		pid[i]=fork();
		if(pid[i]<0){exit(9);}
		else if(pid[i]==0){
			int padre = getppid();
			if(padre%2){
				if((getpid()%2)!=0){
					signal(SIGUSR1,handler);
					system(argv[i]);					
					exit(1);	
				}
				else{
					exit(0);
					}	
			}
			else{
				if((getpid()%2)==0){
					signal(SIGUSR1,handler);
					system(argv[i]);
					exit(1);
				}
			else{
					exit(0);
					}				
			}
			pause();
			}
	else wait(&status);
	}	
	exit(0);
	//for(i = 0; i<argc;i++){
		//kill(0,SIGUSR1);		
	//}
}
