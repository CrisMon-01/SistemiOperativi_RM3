#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char stringa [20];

int main(int argc,char *argv[]){
pid_t pid;
int status,i;
for(i=1;i<argc;i++){
	pid = fork();
	stringa s ="";
	int j;
	if(pid<0){exit(9);}
	else if (pid==0){
		for(j=0;j<2;j++){
			s[j] = argv[i][j];
		}
		if(strcmp(s,"ic")==0 || strcmp(s,"es")==0 || strcmp(s,"rg")==0){
			for(j=2;j<6;j++){
				if(argv[i][j]<'0'||argv[i][j]>'9'){
					printf("NON VALIDO \n");
					exit(2);
				}			
			}
			printf("CODICE VALIDO %s\n",argv[i]);
			exit(1);
		}
		else {exit(2);
		printf("CODICE NON VALIFO\n");}
	}	
	wait(&status);
}
exit(1);
}
	
