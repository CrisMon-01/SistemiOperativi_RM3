#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid[10];
int status;
int i;
int f;
for(i=0;i<10;i++){
	pid[i] = fork();
	if(pid[i]<0){
	perror("err");
	exit(2);
	}
	else if(pid[i]==0){
		sleep(1);
		printf("Figlio #%d\n",i);
		sleep(1);
		exit(100+i);
	}
	else wait(&status);
		f= WEXITSTATUS(status);
		printf("FIGLIO TERMINATO CON: %d\n",f);	
}
}
