#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char stringa[20];

int main(int argc, char *argv[]){
int i,j;
stringa s;
for(j=2;j<11;j++){
	s[j-2]=argv[0][j];
}	
printf("Nome programma: \t   %s\n",s);
for(i=1;i<argc;i++){
	printf("parametro: %d\t %s\n",i,argv[i]);
}
}
