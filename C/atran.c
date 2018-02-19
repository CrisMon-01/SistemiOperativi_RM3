#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char str[20];

int main(){
pid_t pid1,pid2,pid3;
int status1,status2;
pid1 = fork();
if(pid1<0) exit(9);
else if(pid1>0){
		pid2=fork();
		if(pid2<0) exit(9);
		else if(pid2==0){
			pid3=fork();
			if(pid3>0)
				exit(getpid());
			else {
				printf("TERZO FIGLIO PID:%d\n",getpid());
				sleep(rand()%5);
				exit(0);	
			}
			}
			else{
				int u,s;
				u = wait(&status1);
				s = wait(&status2);
				printf("PRIMO: %d \t SECONDO:%d\n",u,s);
			}	
	}
	else{
		printf("FIGLIO1 CON PID:%d\n",getpid());
		str s = "./ss";
		str s1 = "uno";
		str s2 = "due";
		str s3 = "tre";
		execlp(s,s,s1,s2,s3,NULL);
		exit(getpid());
	}



}
