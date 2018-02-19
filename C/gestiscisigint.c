#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void handler(signal){
	if(signal == SIGINT)
		printf("HAI PREMUTO CTRL+C\n");
}

int main(){
	signal(SIGINT,handler);
	for(;;){
		sleep(1);
		printf("PRINTF \n");
	}		
}
