#!/bin/awk -f

{
    for(i=1 ; i<=NF ; i++){
        if(i%2==1) 
            printf("dispari ");
        else printf("pari ");
        if(i == NF)
            printf("\n");
    }
}