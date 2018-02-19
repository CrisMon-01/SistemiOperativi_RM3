#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char str[20];

int main(int argc, char *argv[]){
pid_t pid;
int status,i,j,v;
for(i=1;i<argc;i++){
	pid = fork();
	v = 1;
	if(pid<0){	exit(9);}
	else if(pid==0){
		if(strlen(argv[i])!=6){
			printf("TRENO %s NON VALIDO 1\n",argv[i]);
			}
		else{
			str s = "";
			for(j=0;j<2;j++)
				s[j]=argv[i][j];
			if((strcmp(s,"ic")!=0) && (strcmp(s,"es")!=0) && (strcmp(s,"rg")!=0)){
				printf("TRENO %s NON VALIDO 2\n",argv[i]);
				}
			else{
				for(j=2;(j<6 && (v==1));j++){
					if((argv[i][j]<'0')||(argv[i][j]>'9')){
						v=0;
						printf("TRENO %s NON VALIDO 3\n",argv[i]);
						}
					}
				if(v==1){
					printf("TRENO %s VALIDO\n",argv[i]);
					if(argv[i][j]=='i')
						exit(1);
					if(argv[i][j]=='e')
						exit(2);
					if(argv[i][j]=='r')
						exit(3);
				}		
			}
		}
	exit(9);
	}
	else{
		int b = wait(&status);
		if(WEXITSTATUS(status)==1){
			str f = "";
			for (j=2;j<6;j++){
				f[j-2]=argv[i][j];			
			}
			printf("IC VALIDO %s\n",f);
		}
		if(WEXITSTATUS(status)==2){
			str f = "";
			for (j=2;j<6;j++){
				f[j-2]=argv[i][j];			
			}
			printf("es VALIDO %s\n",f);
		}
		if(WEXITSTATUS(status)==3){
			str f = "";
			for (j=2;j<6;j++){
				f[j-2]=argv[i][j];			
			}
			printf("rg VALIDO %s\n",f);
		}
	}
}
}