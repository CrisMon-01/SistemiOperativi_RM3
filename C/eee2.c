#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char string[20];

void handler(int signal){
	if(signal==SIGINT){
		printf("Forse hai premuto per sbaglio, vuoi termiante [y/n]\n");
		string s;		
		scanf("%s",s);
		if(strcmp(s,"y")==0)
			exit(1);
	}
}

int main(){
	signal(SIGINT,handler);
	for(;;)
	pause();
}
