#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signal){
	if(signal==SIGINT){
		printf("Terminated\n");	
		exit(0);	
	}
}

int main(){
	for(;;){
	signal(SIGINT,handler);
	printf("HelloWorld\n");	
	sleep(1); 	 
	}
}
