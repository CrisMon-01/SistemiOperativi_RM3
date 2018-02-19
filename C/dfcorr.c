#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
pid_t pid[10];
int i;
for(i=0;i<10;i++){
	pid[i]=fork();
	if(pid[i]<0){
		perror("err");
		exit(2);
	}
	else if(pid[i]>0){
		printf("HO GENERATO FIGLIO INDICE %d\n",pid[i]);
	}
	else{
		sleep(1);
		printf("SONO IL FIGLIO #%d\n",i+1);
		sleep(1);
		exit(100+i+1);
	}
}
for(i=0;i<10;i++){
	int status;
	wait(&status);
	printf("HA TERMINATO IL FIGLIO %d\n",WEXITSTATUS(status));
}

}
