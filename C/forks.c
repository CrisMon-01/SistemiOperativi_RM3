#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
pid_t pid;
int status;
pid = fork();
if(pid<0){
	perror("ERR");
	exit(9);
}
else if(pid>0){
	sleep(5);
	printf("PARENT: MIO PID %d\n",getpid());
	printf("PARENT: PID FIGLIO %d\n",pid);
	printf("ATTENDO MIO FIGLIO\n");
	wait(&status);
	printf("PARENT: FIGLIO TERMINATO CON:%d\n",WEXITSTATUS(status));
}
else{
	printf("CHILD: SONO IL FIGLIO CON PID %d\n",getpid());
	printf("CHILD: SONO IL FIGLIO DI %d\n",getppid());
	printf("DAMMI UN CODICE SI USCITA\n");
	int e;
	scanf("%d",&e);
	exit(e);
}

}
