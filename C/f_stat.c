#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int status;
pid = fork();
if(pid < 0){
	perror("err");
	exit(9);
}
else if(pid==0){
	printf("CHILD: sono il figlio\n");
	printf("CHILD: il mio pid:%d \n",getpid());
	printf("CHILD: mio padre %d\n",getppid());
	printf("Dammi un codice di uscita");
	int e;
	scanf("%d",&e);
	exit(e);	
	}
	else{
	printf("FATHER: sono il padre %d\n",getpid());
	printf("PID FIGLIO: %d\n",pid);
	printf("aspetto\n");
	sleep(5);
	wait(&status);
	int k = WEXITSTATUS(status);
	printf("CODICE USCITA FIGLIO %d\n",k);
	}
}
