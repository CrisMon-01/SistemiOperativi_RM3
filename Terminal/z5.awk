#!/bin/awk

BEGIN{FS = " "
	OFS = "\t"
	print "SQUARA \t PUNTI"}
{
	if($3>$4){
		c[$1]+=3
		c[$2]+=0		
		}
	if($3<$4){
		c[$1]+=0
		c[$2]+=3		
		}
	if($3==$4){
		c[$1]+=1
		c[$2]+=1		
		}
}
END{
	for(i in c)
		printf("%s \t %d\n", i,c[i])	| "sort -k 2nr"
}
