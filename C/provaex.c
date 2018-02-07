#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid;
    int i;
    for(i=0;i<atoi(argv[1]);i++){
    pid = fork();
    if(pid<0){
        perror("error");
        exit(2);
    }
    else   if(pid>0){
        printf("PADRE: sono il padre\n");
        printf("PADRE uqesto è il mio pid : %d\n", getpid());
        printf("PADRE: pid figlio attuale: %d\n",pid);
    }else if(pid == 0){
        printf("FIGLIO : sono il figlio\n");
        printf("FIGLIO : il mio pid %d\n",getpid());
        sleep(3);
        printf("FIGLIO : mio pdre è: %d\n",getppid());
        exit(0);
    }
    }


}