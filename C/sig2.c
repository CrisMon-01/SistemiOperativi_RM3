#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signal){
	if(signal == SIGINT){
		printf("Hai premuto per sbaglio Ctrl-C\nVuoi realmente sospendere l' exe? [y/n]");
		char c;
		scanf("%c",&c);
		if(c=='y'){	
		printf("SBLOCCATO");		
		exit(0);		
		}
	}
}

int main(){
	signal(SIGINT,handler);
	for(;;){
		printf("Hello World\n");
		sleep(1);
	}
}
