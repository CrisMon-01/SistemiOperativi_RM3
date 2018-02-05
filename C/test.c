#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("letto.txt","w");
    fprintf(fp, "scrittura\n");      //print inTo the File
    fclose(fp);
return 0;
}
