#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define N 20

typedef char string [20];
int main(){
  pid_t pid;
  int cmd,i,status;
  printf("quanti comandi vuoi dare?\n");
  scanf("%d",&cmd);
  if(cmd>20 || cmd <0){
      printf("err");
      exit(0);
  }
  string vett[cmd];
  for(i=0;i<cmd;i++){
    printf("dai comando\n");
    scanf("%s",vett[i]);
  }
  for(i=0;i<cmd;i++){
    pid = fork();
    if(pid<0){
      perror("err");
      exit(2);
    }
    if(pid==0){
      system(vett[i]);
      exit(0);
    }
    else{
      printf("Comando %s con cod %d\n",vett[i]);
      wait(&status);
    }
  }
  
}