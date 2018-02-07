#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void sig_usr(int sign){
	exit(0);	
}

int main(){
	int status;
	signal(SIGINT, sig_usr);
	for(;;){
		printf("HelloWolrd\n");
		sleep(2);	
}
}
