#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char string[20];

int creaB(string nf, string f){
FILE *fi = fopen(nf,"r");
FILE *fo = fopen("frut_p.dat","ab");
if(fi==NULL){
	printf("ERRORE");
	return -1;
}
int c=0;
string n,f1,f2,f3;
while(!feof(fi)){
	int k = 0;
	fscanf(fi,"%s %s %s %s\n",n,f1,f2,f3);
	if((strcmp(f,f1)==0)||(strcmp(f,f2)==0)||(strcmp(f,f3)==0)){
		k = 1;
		fprintf(fo,"%s [%d]\n",n,k);
		c++;
	}	
	else fprintf(fo,"%s [%d]\n",n,k);
}
fclose(fi);
fclose(fo);
return c;
}

int main(){
	int k = creaB("persone_frutta.txt","pera");
	printf("%d\n",k);
}
