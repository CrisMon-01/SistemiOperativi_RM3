#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef char stringa [20];

int main(int argc,char *argv[]){
pid_t pid;
int status,i;
	for(i=0;i<argc-1;i++){
		pid = fork();
		if(pid <0){
		perror("err");
		exit(9);
		}
		else if (pid==0){
			stringa s = "";
			int j = 0;
			for(j = 0;j<2;j++){
			s[j]=argv[i][j];
			}	
			if(strcmp(s,"ic")!=0 ||strcmp(s,"es")!=0 || strcmp(s,"rg")!=0)
				exit(2);
			else{
				for(j=2;j<6;j++){
					if(argv[i][j]<'0' || argv[i][j]>'9')
					exit(2);
				else exit(1);
			}	
			}
				
		}	
		else{
		wait(&status);
		int v = WEXITSTATUS(status);
		if (v==1){
			printf("%s",argv[i]);
		}
		}
	}

}
