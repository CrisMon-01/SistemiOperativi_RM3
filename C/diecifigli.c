#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status, i;
	for(i = 1; i<11;i++){
		 pid = fork();
	if(pid<0){
		perror("err");
		exit(2);}
	if(pid==0){
		sleep(1);
		printf("Figlio : #%d\n", i);
		sleep(1);
		exit(100+i);
	}
	else 
		printf("Ho generato il figlio %d con pid %d\n",i,pid);		
	}
	for(i=1;i<11;i++){
	wait(&status);
	printf("Mio figlio ha terminato con %d\n",WEXITSTATUS(status));
	}
	exit(0);
	}

