#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef char string [20];

int main(){
pid_t pid;
int status;
FILE *f = fopen("t.txt","w+");
pid = fork();
if(pid<0){
	perror("ERR");
	exit(2);
}
else if(pid>0){
	printf("PADRE: INSERIMENTO DI STRINGA NEL FILE\n");
	string s = "sono il padre";
	fprintf(f,"%s",s);
	long pos = ftell(f);
	printf("OFFSET SU FILE BY PADRE : %ld\n",pos);
	printf("PADRE CHIUDO IL FILE E CANCELLO\n");
	fclose(f);
	string k = "t.txt";
	remove(k);
	exit(1);
}
else{
	printf("FIGLIO ATTENDO 4 SECONDI\n");
	sleep(4);
	long pos = ftell(f);
	printf("OFFSET DAL FIGLIO %ld\n",pos);
	fseek(f,0,SEEK_SET);
	string s1;
	string s2;
	string s3;	
	fscanf(f,"%s %s %s\n",s1,s2,s3);
	printf("CONTENUTO : %s %s %s\n",s1,s2,s3);
	printf("FIGLIO CHIUDO FILE\n");
	fclose(f);
	exit(0);
}
}
