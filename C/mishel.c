#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char str[20];

int main(){
pid_t pid;
int status;
str ss;
for(;;){
	printf("myshell#");
	scanf("%s",ss);
	pid = fork();
	if(pid<0){
		exit(9);
	}	
	else if(pid==0){
		system(ss);
	} 
	else wait(&status);
}
}
