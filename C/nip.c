#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char string[20];

int main(){
	pid_t pid1,pid2,pid3;
	int status;
	pid1 = fork();
	if(pid1 < 0){
		perror("err");
		exit(9);
	}
	else if(pid1 == 0){
		printf("SONO IL PRIMO FIGLIO %d\n",getpid());
		printf("PID PADRE %d\n",getppid());
		pid2 = fork();
		if(pid2<0){
			perror("err");
			exit(9);
		}
		else if(pid2==0){
			string s = "./sss";
			execlp(s,s,"nipote",NULL);
			exit(2);
		}
		else{ wait(&status);
			exit(1);
			}
	}	
	else{
		printf("SONO IL PRIMO PADRE %d\n",getpid());
	}
		pid3 = fork();
		if(pid3<0)
			perror("err");
		else if(pid3==0){
			printf("PID PADRE %d\n",getppid());
			string s = "./sss";
			execlp(s,s,"figlio",NULL);
			exit(1);
		}
		else{	printf("SONO IL SECONDO PADRE %d\n",getpid());
			 wait(&status);
		exit(0);
		}
}
