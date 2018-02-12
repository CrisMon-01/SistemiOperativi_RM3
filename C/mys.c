#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef char string [20];

int main(){
pid_t pid;
int status;
string s;
for(;;){
	printf("myshell#");
	scanf("%s",s);
	pid = fork();
	if(pid < 0){
	perror("err");
	exit(9);}
	if(pid == 0){
		system(s);
		exit(1);
	}
	else wait(&status);
}
}
