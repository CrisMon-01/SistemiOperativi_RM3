#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
pid_t pid;
int status,i;
for(i=1;i<=10;i++){
	pid=fork();
	if(pid<0){
		perror("ERR\n");
		exit(2);
	}
	else if(pid>0){
		printf("GENERATO FIGLIO %d\n",pid);
		wait(&status);
		printf("FIGLIO %d TERMINATO CON STATUS: %d\n",i,status/256);
	}
	else{
		sleep(1);
		printf("SONO IL FIGLIO %d\n",i);
		sleep(1);
		exit(100+i);
	}
}
}
