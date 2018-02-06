#!bin/awk

BEGIN{printf("SQUADRA  ""  PUNTI \n" )}
{
	if($3>$4){
		c[$1] += 3;
		c[$2] += 0;	
	}
	if($3<$4){
		c[$1] += 0;
		c[$2] += 3;	
	}	
	if($3==$4){
		c[$1] += 1;
		c[$2] += 1;	
	}
	
}
END {
	ordina = "sort -k 2nr"
	for(i in c)
		printf("%s %d \n", i, c[i]) | ordina
	close(ordina);
}      
