#!/bin/awk -f

BEGIN{ 
	print "CONTINENTE \t N MED ABITANTI"
}
{
	
	naz[$4]+=$3
	c[$4]+=1
}
END{	
	for(i in naz)
		print  i "\t \t" (naz[i]/c[i])
}
