#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int status;
FILE *f = fopen("test.txt","w+");
pid = fork();
if(pid<0){
	perror("err");
	exit(2);
}
else if(pid==0){
	printf("FIGLIO attendo 4 secondi\n");
	sleep(4);
	printf("OFFSET F: %ld\n",ftell(f));
	printf("FIGLIO: CHIUDO IL FILE");
	fclose(f);
	exit(0);
}
else{
	printf("PADRE INSERISCO UNA STRINGA\n");
	fprintf(f,"%s","Sono il padre");
	long k = ftell(f);
	printf("OFFSET P: %ld\n", k);
	printf("CHIUDO IL FILE E ELIMINO\n");
	system("cat test.txt");	
	fclose(f);
	remove("test.txt");
	exit(0);
}
}
