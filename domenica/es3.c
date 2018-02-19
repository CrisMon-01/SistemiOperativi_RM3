#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char str[10];

void handler(int sign){
	if(sign == SIGINT){
		printf("VUOI VERAMENTE SOSPENDERE?[y/n]\n");
		str s;
		scanf("%s",s);
		if(strcmp("y",s)==0)		
			exit(1);
		else{
			signal(SIGINT,SIG_IGN);
		}				
	}
}

int main(){
signal(SIGINT,handler);
printf("MI METTO IN PAUSA\n");
for(;;)
	pause();
return;
}
