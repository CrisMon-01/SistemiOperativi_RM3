#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef char string[20];

int main(){
pid_t pid;
int status,i,k;
printf("DIMMI QUANTI CMD VUOI DARE\n");
scanf("%d",&k);	
if(k>20||k<0)
	return;
string a[k];
for(i=0;i<=k-1;i++){
	printf("INSERIRE COMANDO\n");
	scanf("%s",a[i]);
}
for(i=0;i<k;i++){
	pid = fork();
	if(pid<0){
		perror("ERR");
		exit(9);
	}
	else if(pid>0){
		wait(&status);
	}
	else{
		execlp(a[i], a[i],NULL);
//		system(a[i]);
		exit(1);
	}
}
}
