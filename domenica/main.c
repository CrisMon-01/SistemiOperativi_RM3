#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char str[20];

void cambiaV(str nome,int vv, int nv,str nomef){
	FILE *f=fopen(nomef,"r+");
	if(f==NULL){
		printf("ERRORE");
		return;
		}
	long pos;
	str n;
	int v;
	while(!feof(f)){
		pos = ftell(f);	
		fscanf(f,"%s %d\n",n,&v);
		if((strcmp(n,nome)==0)&&(vv==v)){
			fseek(f,pos,SEEK_SET);
			fprintf(f,"%s %d\n",n,nv);
		}
	}
	fclose(f);
	return;
}

void creaf(str nf){
FILE *f = fopen(nf,"r");
int i = 0;
str s = "";
while(nf[i]!='.'){
	s[i]=nf[i];
	i++;
}
str ss;
int v;
while(!feof(f)){
	fscanf(f,"%s %d\n",ss,&v);
	s[i] = '0'+v;
	FILE *fo = fopen(s,"a");
	fprintf(fo,"%s %d\n",ss,v);
	fclose(fo);
}
fclose(f);
return;
}

int main(){
	cambiaV("Giuseppe",7,8,"f.txt");
	creaf("f.txt");
	return;
}
