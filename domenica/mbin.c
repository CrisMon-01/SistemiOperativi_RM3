#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char str [10];

typedef struct{
	str nome;
	int pos;
}rec_b;

int creaB(str nf,str col){
	FILE *f = fopen(nf,"r");
	FILE *fo=fopen("pcb.dat","ab");
	int c[3];
	while(!feof(f)){
		int v = 0;
		rec_b rb;
		str n,col1,col2,col3;
		fscanf(f,"%s %s %s %s\n",n,col1,col2,col3);
		if(strcmp(col,col1)==0){
			strcpy(rb.nome,n);
			rb.pos = 1;
			v=1;
		}
		if(strcmp(col,col2)==0){
			strcpy(rb.nome,n);
			rb.pos = 2;
			v = 1;
		}
		if(strcmp(col,col3)==0){
			strcpy(rb.nome,n);
			rb.pos = 3;
			v = 1;
		}
		if(v!=0){
			fwrite(rb.nome,rb.pos,sizeof(rec_b),fo);
		}
	}
	fclose(fo);
	fclose(f);
/*	int max = c[0];
	int index = 1;
	int i;
	for(i = 1;i<3;i++){
		if(c[i]<max)
			max = c[i];
			index = (i+1);
	}	
	return index;*/
	return 0;
}

int main(){
	int k = creaB("s_us.txt","verde");
	printf("%d\n",k);
}
