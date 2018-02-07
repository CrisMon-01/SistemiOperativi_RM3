#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

static void sig_usr(int signo) {    //gestione signali 1 o 2
	if(signo == SIGUSR1)
		printf("Processo %d attivato\n",getpid());
	else
		printf("Processo %d non attivato\n",getpid());		
	exit(0);
}

int main(int argc,char *argv[]){
	pid_t pid[10];  //creo array pid
	int i, status;
	char bol;
	for(i=0;i<=atoi(argv[1]);i++){
	    pid[i] = fork();    //riempio i pid
	    if(pid[i]<0){   //ctrl err
		perror("error");
		exit(2);
	    }	
	    
	    else if(pid[i] == 0){   //caso figlio
		signal(SIGUSR1, sig_usr);
		signal(SIGUSR2, sig_usr);
		pause();
	    }

	    else {      //caso padre
		printf("PADRE questo è il mio pid : %d\n", getpid());
		printf("PADRE: pid figlio attuale: %d\n",pid[i]);
		printf("Vuoi attivare il processo %d [y/n]\n",pid[i]);
		scanf("%c", &bol);

		if(bol == 'y')		
			kill(pid[i], SIGUSR1);
		else
			kill(pid[i], SIGUSR2);

		wait(&status);
	    }
	}
		exit(1);
}