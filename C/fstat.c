#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int status,e;
pid = fork();
if(pid==0){
printf("CHILD: SONO IL FIGLIO CON PID %d\n",getpid());
printf("CHILD: FIGLIO DI %d\n",getppid());
printf("INSERIRE UN CODICE DI USCITA\n");
scanf("%d",&e);
exit(e);
}
else{
sleep(5);
printf("PARENT SONO IL PADRE CON CODICE %d\n",getpid());
printf("PARENT: SONO IL PADRE DI %d\n",pid);
printf("ATTENDO MIO FIGLIO \n");
wait(&status);
printf("CODICE USCITA MIO FIGLIO %d\n",WEXITSTATUS(status));
exit(0);
}

}
