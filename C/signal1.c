#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void handler(int sign){
	if(sign == SIGINT){
		printf("Forse hai premuto per sbaglio Ctrl-C? \nVuoi realmente sospendere l'esecuzione [y/n]?");
	char c;
	scanf("%c",&c);
	if(c=='y')
		exit(0);	
	}
}
int main(){
	signal(SIGINT,handler);
	for(;;){
		printf("HelloWorld \n");
		sleep(1);
}	
}
