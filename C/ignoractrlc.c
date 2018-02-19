#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
	
int main(){
	printf("YOU CAN STOP ME WITH CTLC+C\n");
	sleep(3);
	signal(SIGINT,SIG_IGN);
	printf("YOU CAN'T STOP ME WITH CTLC+C\n");	
	sleep(3);
	signal(SIGINT,SIGINT);
	printf("YOU CAN STOP ME WITH CTLC+C\n");
	sleep(5);	
}
