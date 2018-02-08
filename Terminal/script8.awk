#!/bin/awk

BEGIN{
tot = 0;
print "TOTALE \t PRODOTTO \t COSTO%"
}
{
tot += $1
spesa[$3]=$1;	
}
END{
	print tot""
	for(i in spesa)
		print ("\t" i "\t\t" (spesa[i]*100/tot)"%");	
}
