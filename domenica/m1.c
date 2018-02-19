#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char str [10];

int creaB(str nf,str col){
	FILE *f = fopen(nf,"r");
	FILE *fo=fopen("pos_col.dat","ab");
	int c[3];
	while(!feof(f)){
		str n,col1,col2,col3;
		fscanf(f,"%s %s %s %s\n",n,col1,col2,col3);
		if(strcmp(col,col1)==0){
			c[0]+=1;
			fprintf(fo,"%s [%d]\n",n,1);
		}
		if(strcmp(col,col2)==0){
			c[1]+=1;
			fprintf(fo,"%s [%d]\n",n,2);
		}
		if(strcmp(col,col3)==0){
			c[2]+=1;
			fprintf(fo,"%s [%d]\n",n,3);
		}
	}
	fclose(fo);
	fclose(f);
	int max = c[0];
	int index = 1;
	int i;
	for(i = 1;i<3;i++){
		if(c[i]<max)
			max = c[i];
			index = (i+1);
	}	
	return index;
}

int main(){
	int k = creaB("s_us.txt","verde");
	printf("%d\n",k);
}
