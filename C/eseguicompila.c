#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char string [20];

int main(int argc, char *argv[]){
pid_t pid1,pid2;
int status1,status2,i;
	for(i=1;i<argc;i++){
		pid1 = fork();
		if(pid1 <0){
			printf("err");
			exit(9);
		}
		else if(pid1==0){
			pid2=fork();
				string ex;
				int j = 0;
				while(argv[i][j]!='.'){
					ex[j] = argv[i][j];
					j++;
				}
				if(pid2<0){exit(9);}
				if(pid2 == 0){
					string gcc = "/usr/bin/gcc";
					execlp(gcc,gcc,argv[i],"-o",ex,NULL);
					exit(1);				
				}			
				else  {
				wait(&status1);
				string a = "./";
				strcat(a,ex);
				execlp(a,ex,NULL);
				exit(1);
					}
				}		
		else {
			printf("procedo con il comando %s\n",argv[i]);
			wait(&status2);
		}
	}
}

