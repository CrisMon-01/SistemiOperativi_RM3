#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){

	if(strcmp(argv[1],"nipote")==0)
		printf("Sono il nipote del primo padre\n");	
	else printf("Sono il figlio del secondo padre\n");
}
