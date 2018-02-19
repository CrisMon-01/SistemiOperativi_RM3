#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char Stringa[20];

int insv(Stringa nome, int voto,Stringa nomef){
	if(voto>10||voto<0)	printf("ERRORE");	
	else{
	FILE *f = fopen(nomef,"a+");
	Stringa s;
	int v;
	int c = 0;
	fprintf(f,"%s %d\n",nome,voto);
	fseek(f,0,SEEK_SET);
	while(!feof(f)){
		fscanf(f,"%s %d\n",s,&v);
		c++;
	}	
	fclose(f);
	return c;
	}
	return 0;
}
void cambiavoto(Stringa nome, int vv,int nv, Stringa file){
	if(nv>10||nv<0)printf("ERRORE");
	else{
		FILE *f = fopen(file,"r+");
		Stringa s;
		int v,test=0;
		long pos;
		while(!feof(f)&&(!(test))){
			pos = ftell(f);
			fscanf(f,"%s %d\n",s,&v);
			if((strcmp(s,nome)==0) && vv == v){
				fseek(f,pos,SEEK_SET);
				fprintf(f,"%s %d\n",s,nv);
				test = 1;
			}
		}
	fclose(f);
}
	return;
}
int maxV(Stringa nf){
	int m=0;
	FILE *f=fopen(nf,"r");
	Stringa tmp;
	int v;
	while(!feof(f)){
		fscanf(f,"%s %d\n",tmp,&v);
		if(v > m) 
			m = v;
	}
	fclose(f);
	return m;
}

void creazione(Stringa nf){
	int v;
	Stringa tmp;
	Stringa s = "tes";
	FILE *f = fopen(nf,"r");	
	while(!feof(f)){
		fscanf(f,"%s %d\n",s,&v);
		strcat(s,v);
		FILE *fo = fopen(s,"a");
		fprintf(fo,"%s %d\n", s,v);
		fclose(fo);
	}
	fclose(f);
	return;
}

int main(){
	int k = insv("Claudio",4,"tes.txt");
	printf("%d\n",k);
	cambiavoto("Claudio",4,5,"tes.txt");
	int m = maxV("tes.txt");
	printf("%d\n",m);
	creazione("tes.txt");
	return;
}
