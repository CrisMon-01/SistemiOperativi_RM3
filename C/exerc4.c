#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef char str [20];

void handler(int signal){
	if(signal==SIGUSR1){		//p pari
			if(getpid()%2){
				SIGKILL;
			}
		}
	else{				//p disp
		if(getpid()%2==1)
			SIGKILL;

	}
}

int main(int argc, char *argv[]){
pid_t pid[argc];
int status,i;
for(i = 1;i<=argc;i++){
	pid[i] = fork();
	if(pid[i]<0)
		exit(9);
	else if(pid[i]>0){
		printf("PID PADRE: %d\n",getpid());
		if(pid[i]%2==0){		//p pari
			kill(0,SIGUSR2);
			}
		else{				//p dispari
			kill(0,SIGUSR1);
			}
		}
		else{
			printf("PID FIGLIO: %d\n",getpid());
			signal(SIGUSR1,handler);
			signal(SIGUSR2,handler);
			pause();
			str s = "./cia";
			strcat(s,argv[i]);
			execlp(s,s,NULL);
			exit(1);
		}

}//for

}//main
