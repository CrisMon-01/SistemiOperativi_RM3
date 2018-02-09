#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main(){
pid_t pid;
pid = fork();
if(pid<0){
	perror("err");
	exit(2);
}
else if (pid == 0){
	printf ("sono il processo figlio\n");
	exit(0);
}
else {
	printf("sono il processo padre\n");
	exit(0);
}
}
