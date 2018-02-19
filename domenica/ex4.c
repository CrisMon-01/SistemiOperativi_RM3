#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

typedef char str[10];
str s;
void handler(int signal){
	if(signal==SIGUSR1){	//p pari
		if((getpid()/2)==1){	//f disp
			printf("SONO ATTIVO\n");
			execlp(s,s,NULL);	
		}
		else{	printf("PROCESSO NON ATTIVO\n");
			kill(getpid(),SIGINT);
			}
		}
	else{			//p disp
		if((getpid()/2)==0){	//f pari
			printf("SONO ATTIVO\n");
			execlp(s,s,NULL);
			}
		else{	printf("NON SONO ATTIVO\n");
			kill(getpid(),SIGINT);
			}		
	}
}

int main(int argc,char *argv[]){
pid_t pid;
int status,i;
for(i=1;i<argc;i++){
	strcpy(s,argv[i]);
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	pid=fork();
	if(pid<0)  exit(9);
	else if(pid==0){
		pause();
		exit(1);
	}
	else{
		if((getpid()/2)==0)
			kill(pid,SIGUSR1);
		else 	kill(pid,SIGUSR2);
		sleep(3);
		wait(&status);
	}

}//for 

}//main
