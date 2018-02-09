#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Stringa[30];

int modificaColore(Stringa nome_file, Stringa corrente,Stringa nuovo){
	int c = 0, b;
	long ind;
	Stringa n,c1,c2,c3;
	FILE *f = fopen(nome_file,"r+");
	while(!feof(f)){
		b = 0;
		ind = ftell(f);
		fscanf(f,"%s %s %s %s\n",n,c1,c2,c3);
		if(strcmp(c1,corrente)==0){
			strcpy(c1, nuovo);
			c++;
			b = 1;
		}
		if(strcmp(c2,corrente)==0){
			strcpy(c2, nuovo);
			c++;
			b = 1;
		}
		if(strcmp(c3,corrente)==0){
			strcpy(c3, nuovo);
			c++;
			b = 1;
				}
		if(b == 1)
		{
			fseek(f,ind,SEEK_SET);
			fprintf(f,"%s %s %s %s\n",n,c1,c2,c3);
		}
			printf("\n");

	}
	fclose(f);
	return c;
	}



int main(){
	int k = modificaColore("esfin.txt","giallo","viola");
	printf("%d\n",k);
}

