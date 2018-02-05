#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("text.txt","w");
    fputs("stringa inerita", fp);
    fseek(fp, 7, SEEK_SET);
    fputs("hello",fp);
    fclose(fp);
    return 0;
}