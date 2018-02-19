#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char str[10];

void handler(int sign){
	if(sign == SIGUSR1)
		printf("PROCESSO ATTIVO:%d\n",getpid());
	else 
		printf("PROCESSO NON ATTIVO: %d\n",getpid());
}

int main(int argc, char *argv[]){
int n = atoi(argv[1]);
int i,status;
pid_t pid;
for(i=0;i<n;i++){
	pid = fork();
	if(pid<0){
		perror("err");
		exit(9);
		}
	else if(pid>0){
		printf("CRETO PROCESSO FIGLIO:%d\n",pid);
		printf("VUOI ATTIVARE IL PROCESSO %d [y/n]\n",pid);
		str s = "";		
		scanf("%s",s);
		if(strcmp(s,"y")==0)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		wait(&status);
	}
	else{
		signal(SIGUSR1,handler);
		signal(SIGUSR2,handler);
		pause();
		exit(1);
	}
}
}
