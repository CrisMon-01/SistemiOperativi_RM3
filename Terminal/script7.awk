#!/bin/awk

BEGIN{print "ELENCO RIBALTATO \n"
	riga[NR]
}
{
	riga[NR] = $0;
}
END{
	for(i=NR;i>0;i--)
		print riga[i]
}
