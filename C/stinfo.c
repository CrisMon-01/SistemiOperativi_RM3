#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
if(strcmp(argv[1],"nipote")==0){	
printf("SONO IL NIPOTE DEL PRIMO FIGLIO\n");
}
else
	printf("SONO IL FIGLIO DEL SECONDO PADRE\n");
}
