#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char stringa[30];
stringa voti[11] = {"0","1","2","3","4","5","6","7","8","9"};

int inserisci (stringa nome, int voto, stringa nomefile){
	FILE *fp = fopen(nomefile, "a+");
	int c=0;	
	int t1;
	stringa t2;
	fprintf(fp,"%s %d\n", nome, voto);
	fseek(fp,0,SEEK_SET);
	while(!(feof(fp))){
		c++;
		fscanf(fp,"%s %d\n",t2, &t1);
	}
	fclose(fp);
	return c;
}
void cambiaVoto	(stringa nome, int vecchio_voto, int nuovo_voto, stringa nomefile){
	FILE *fp = fopen(nomefile, "r+");
	int t1,test=1;
	stringa t2;
	long pos = 0;
	fseek(fp,0,SEEK_SET);
	while(!(feof(fp)) && test){
		pos=ftell(fp);
		fscanf(fp,"%s %d\n", t2, &t1);
		if(!(strcmp(t2, nome)) && t1==vecchio_voto){
			fseek(fp,pos,SEEK_SET);
			fprintf(fp,"%s %d\n", t2, nuovo_voto);
			test = 0;
		}
	}
	if(test)
	   printf("err");
	fclose(fp);
}

int maxVoto(stringa nomefile){
  FILE *fp = fopen(nomefile, "r");
   int max = 0;
   int t1;
   stringa t2;
  //fseek(fp,0,SEEK_SET);
   while(!(feof(fp))){
     fscanf(fp, "%s %d\n",t2, &t1);
     if(t1>max)
	max = t1;
   }
   return max;
  }

void creaFiles(stringa nomefile){
  FILE *fp = fopen(nomefile,"a+");
  int t1;
  stringa t2;
  while(!(feof(fp))){
   fscanf(fp,"%s %d\n", t2, &t1);
   stringa newstring;
   strcpy(newstring, nomefile);
   strcat(newstring,"-");
   strcat(newstring,voti[t1]);
   strcat(newstring,".txt");
   inserisci(t2,t1,newstring);
  }
}
  
int main()
{
	printf("Operazioni 1 inserisci \n 2 cambiavoto \n 3 maxvoto \n 4 creaFile\n");
int comando;
scanf("%d", &comando);
if(comando == 1){
	printf("inserire nome \n");
	stringa nome;
	scanf("%s", nome);
	printf("inserire voto \n");
	int voto;
	scanf("%d", &voto);
	if(voto<0 || voto > 10){
		printf("err");
		return 0;
		}
	printf("%d\n",inserisci(nome, voto, "file1.txt"));
}
if(comando == 2){
	printf("nome da aggiornare \n");
	stringa nome;
	scanf("%s", nome);
	printf("inserire nuovo voto \n");
	int voton;
	scanf("%d", &voton);
	printf("inserire vecchio voto \n");
	int votov;
	scanf("%d", &votov);
	if(votov <0 || votov >10){
		printf("err");
		return 0;
	}
	cambiaVoto(nome, votov,voton, "file1.txt");
	printf("voto aggiornato\n");
	return 0;
}
if(comando == 3){
  int max = maxVoto("file1.txt");
  printf("%d\n",max);
}
if(comando == 4){
    creaFiles("file1.txt");
    printf("comando eseguito\n");
}
return 0;
}
