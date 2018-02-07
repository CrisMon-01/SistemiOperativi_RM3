#!/bin/awk -f

BEGIN{ FS = ",";}

{
    vec[NR];
        for(j=NR;j>0;j--){
        for( i=NF; i>=1 ;i--){
            s = $i " ";
            vec[j] = vec[j] s;
    }
}
vec[j] = vec[j] " ";
}
END{
    for(i = NR; i>0;i--)
        printf("%s \n", vec[i]);
    printf("campi stampati al contrario\n");
    }
