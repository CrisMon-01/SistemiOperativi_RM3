#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>



int main(){
pid_t pid1,pid2,pid3;
int status;
pid1 = fork();
if(pid1<0) exit(9);
else if(pid1>0){
	printf("SONO IL PRIMO PADRE \n");
	wait(&status);
	pid3 = fork();
	if(pid3<0) exit(9);
	else if(pid3>0){
		printf("SONO IL SECONDO PADRE\n");
		wait(&status);
	}
	else{
		execlp("./stainforma","./stainforma","figlio",NULL);
		exit(1);
	}
	
}
else {
	printf("SONO IL FGLIO DEL PRIMO PADRE\n");
	pid2=fork();
	if(pid2<0) exit(9);
	else if(pid2>0){
		wait(&status);
		exit(1);
	}	
	else{
		execlp("./stainforma","./stainforma","nipote",NULL);
		exit(2);
	}
}

}
