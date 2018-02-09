#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
pid_t pid;
int status;
int f;
pid = fork();
if(pid<0){
	perror("err");
	exit(2);	
}
else if(pid==0){
	printf ("FIGLIO PID: %d\n",getpid());
	printf("PID PADRE: %d\n",getppid());
	exit(24);
}
	else 
	wait(&status);
	f = WEXITSTATUS(status);
	printf("PID FIGLIO: %d\n",pid);
	printf("CODICE RIT: %d\n", f);
}
