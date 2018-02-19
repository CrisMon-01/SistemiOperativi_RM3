 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <signal.h>

int main(){
	pid_t pid1,pid2;
	pid1 = fork();
	if(pid1<0){exit(0);}
	else if(pid1==0){
		for(;;){
		printf("SONO ATTIVO FIGLIO  	1 \n");
		sleep(1);
		}
		}
	else{ pid2 = fork();
		if(pid2<0){exit(0);}		
		else if (pid2==0){
			for(;;){
			printf("SONO ATTIVO FIGLIO 2\n");			
			sleep(1);}
			}
		else{ printf("PADRE FACCIO OP SU FIFLIO\n");
			sleep(3);
			kill(pid1,SIGSTOP);
			sleep(3);
			kill(pid1,SIGCONT);
			sleep(3);
			printf("TERMINO FIGLI\n");
			kill(pid1,SIGINT);	
			kill(pid2,SIGINT);	
			printf("TERMINO TUTTO\n");
			return;
		}
	}	
}
