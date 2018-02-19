#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
printf("NOME PROGRAMMA: %s\n",argv[0]);
int i;
for(i=1;i<argc;i++){
	printf("Param %d: %s\n",i,argv[i]);
}

}
