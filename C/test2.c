#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("appoggio.txt","a");
    fprintf(fp, "\n- a testo appeso");
    fclose(fp);
    return 0;
}