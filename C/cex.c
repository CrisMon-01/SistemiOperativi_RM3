#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char str[20];

int main(int argc,char *argv[]){
pid_t pid1,pid2;
int status,i,j;
for(i = 1;i<argc;i++){
	pid1 = fork();
	if(pid1<0)	exit(9);
	else if(pid1>0){
		printf("PROCEDO COL COMANDO %s\n",argv[i]);
		wait(&status);
		}
		else{
			pid2 = fork();
			j=0;
			str gcc = "/usr/bin/gcc";
			str s = "";
			while(argv[i][j]!='.'){
			s[j]=argv[i][j];
			j++;
			}				
			if(pid2<0) exit(9);
			else if(pid2 == 0){
				execlp(gcc,gcc,argv[i],"-o",s, NULL);
				exit(2);
			}
			else {
				wait(&status);
				str ss = "./";
				strcat(ss,s);
				execlp(ss,s,NULL);
				exit(1);
			}
		}	
}

}
