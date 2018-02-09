#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define N 20

typedef char string[20];

int main(){
string cmd[N];
pid_t pid;
int status,qti,i;
printf("scrivere quanti comandi\n");
scanf("%d",&qti);
for(i=0;i<qti;i++){
	printf("comando \n");
	scanf("%s",cmd[i]);
}
for(i=0; i<qti;i++){
	pid = fork();
	if(pid<0){
	perror("err");
	exit(9);
	}
	else if(pid==0){
	system(cmd[i]);
	exit(1);	
	}
	else{
		wait(&status);
	}
}

}
