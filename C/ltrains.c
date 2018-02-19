#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef char string[20];

int main(int argc,char *argv[]){
int i,j,k,status;
pid_t pid;
for(i=1;i<=argc;i++){
	pid = fork();
	if(pid==0){
		string s = "";
		for(j=0;j<2;j++)
			s[j]=argv[i][j];
		if(strcmp(s,"ic")==0||strcmp(s,"ic")==0||strcmp(s,"ic")==0){
			for(j=2;j<6;j++)
				s[j]=argv[i][j];
				if(argv[i][j]>'9'||argv[i][j]<'0'){
					printf("TRENO NON VALIDO %s\n",argv[i]);
					break;
					//exit(9);
				}
				else{
					printf("TRENO VALIDO %s\n",s);
					string ss ="";
				for(k=0;k<2;k++)
					ss[k]=argv[i][k];			
					if(strcmp(ss,"ic")==0)
						exit(1);
					if(strcmp(ss,"es")==0)
						exit(2);
					if(strcmp(ss,"rg")==0)
					exit(3);
			}
		}
	//else exit(9);
	printf("TRENO NON VALIDO %s\n",argv[i]);
	}
	else{
		wait(&status);
		k=WEXITSTATUS(status);
		if(k==1)
			printf("ic:%s\n",argv[i]);
		if(k==2)
			printf("ies:%s\n",argv[i]);
		if(k==3)
			printf("eg:%s\n",argv[i]);
	}



}//for


}//main
