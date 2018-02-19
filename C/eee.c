#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void handler(int signal){
	if(signal == SIGINT)
		printf("TERMINATED\n");
	exit(1);
}

int main(){
signal(SIGINT,handler);
for(;;){
	printf("HELLO\n");
	sleep(1);
}
}
