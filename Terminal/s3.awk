#!/bin/awk -f

BEGIN{print "CONTINENTE \t NUMERO_MEDIO"}
{
 continente[$4]+=$3
 c[$4]+=1
}
END{
	for(i in c)
		print i "\t\t"(continente[i]/c[i]) 
}
