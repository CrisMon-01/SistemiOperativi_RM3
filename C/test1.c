#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("creato.txt","r");
    char singoline[150];
    while(!(feof(fp))){
        fgets(singoline,150,fp);
        puts(singoline);
    }
    fclose(fp);
    return 0;
}