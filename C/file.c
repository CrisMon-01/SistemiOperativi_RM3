#include <stdio.h>
#include <stdlib.h>

typedef char Stringa[30];
int inserisci (Stringa nome, int voto, Stringa nomefile){
	FILE *fp = fopen(nomefile,"a+");
	Stringa n;
	int v;
	int c = 0;
	if(fp == NULL || voto<0 || voto >10)
		printf("err");	
	fprintf(fp,"%s %d\n",nome,voto);
	fseek(fp,0,SEEK_SET);
	while(!feof(fp)){
		fscanf(fp,"%s %d\n",n,&v);
		c++;
	}
	fclose(fp);
	return c;	
}

void cambiavoto(Stringa nome, int v_v, int n_v, Stringa nome_f){
	FILE *fp = fopen(nome_f,"r+");
	Stringa n;
	int trovato = 0;
	long pos;
	int v;
	if(fp==NULL||n_v >10 || n_v<0)
		printf("err");
	while(!feof(fp)){
		pos = ftell(fp);		
		fscanf(fp,"%s %d\n",n,&v);
		if((strcmp(n,nome)==0) &&(v_v==v)){				
			fseek(fp,pos,SEEK_SET);
			fprintf(fp,"%s %d\n",nome,n_v);
			return;
	}
	}
	fclose(fp);
	return;
}

int maxVoto(Stringa nome_f){
FILE *fp = fopen(nome_f,"r");
Stringa n;
int m=0;
int v;
if(fp==NULL)
	printf("err");
while(!(feof(fp))){
	fscanf(fp,"%s %d\n", n,&v);
	if(m<v)
		m=v;
		
}
fclose(fp);
return m;
}

void creaFile(Stringa nomef){
	FILE *fp = fopen(nomef,"r+");
	FILE *fi[10];
	Stringa s,v,tmp;
	if(fp==NULL)
		printf("err");
	while(!feof(fp)){
		fscanf(fp,"%s %s\n",s,v);
		strcpy(tmp,v);
		fi[atoi(v)] = fopen(strcat(tmp,nomef),"a+");
		fprintf(fi[atoi(tmp)],"%s %s\n",s,v);

}
}

int main(){
int uno = inserisci("Laura",10,"file.txt");
printf("%d\n",uno);
cambiavoto("Laura", 10, 9, "file.txt");
int max = maxVoto( "file.txt");
printf("%d\n",max);
creaFile("file.txt");
return 0;
}
