#!/bin/awk -f

BEGIN{print "TOTALE" "\t" "PRODOTTI" "\t" "COSTO%"}
{
	tot += $1;
	c[$3] = $1;	
}
END{
	print tot;
	for(i in c){
		print "\t" i "\t\t" ((c[i]*100)/tot"%")
	}
}
