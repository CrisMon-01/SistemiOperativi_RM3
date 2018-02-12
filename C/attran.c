#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char stringa[20];

int main(){
pid_t pid1,pid2,pid3;
int status1,status2,t1,t2;
pid1=fork();
if(pid1 == 0){
	printf("PID PRIMO FIGLIO%d\n",getpid());
	stringa s = "./stampa_argv ciao1 ciao2";
	system(s);
	exit(1);
}
else {
	pid2 = fork();
	if(pid2==0){
		pid3 = fork();
		if(pid3==0){
			printf("PID TERZO %d\n",getpid());
			sleep(rand()%5);
			printf("MI SONO SVEGLIATO TERMINO\n");
			exit(3);
			}
		else {printf("PID SECONDO FIGLIO %d\n",getpid());
			exit(2);}		
	}
	else{
		t1=wait(&status1);
		t2=wait(&status2);		
	printf("1°: %d \t 2°: %d\n",t1,t2);
		}
}
}
