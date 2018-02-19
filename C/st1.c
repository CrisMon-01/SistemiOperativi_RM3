#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int status;
pid = fork();
if(pid<0){
	perror("ERR");
	exit(2);
	}
else if(pid>0){
	printf("SONO IL PADRE\n");
	exit(0);
	}
	else{
	printf("SONO IL FIGLIO\n");
	exit(0);
	}
}
