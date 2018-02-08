#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Stringa[30]; 

int modificacolore(Stringa nome_file,Stringa colore_corrente, Stringa colore_nuovo){
  FILE *fp = fopen(nome_file,"r+");
  if(fp==NULL)
    printf("err");
  int c = 0;
  Stringa nome,c1,c2,c3;
  while(!feof(fp)){
    int pos = ftell(fp);
    fscanf(fp,"%s %s %s %s\n",nome,c1,c2,c3);
    if(strcmp(c1,colore_corrente)==0){
      fseek(fp,pos,SEEK_SET);
      fprintf(fp,"%s %s %s %s\n",nome,colore_nuovo,c2,c3);
      c++;
    }
    if(strcmp(c2,colore_corrente)==0){
      fseek(fp,pos,SEEK_SET);
      fprintf(fp,"%s %s %s %s\n",nome,c1,colore_nuovo,c3);
      c++;
    }
    if(strcmp(c3,colore_corrente)==0){
      fseek(fp,pos,SEEK_SET);
      fprintf(fp,"%s %s %s %s\n",nome,c1,c2,colore_nuovo);
      c++;
    }
  }
  fclose(fp);
  return c;
}
int main(){
  int c = modificacolore("social_user.txt", "giallo","bianco");
  printf("%d",c);
  return;
}