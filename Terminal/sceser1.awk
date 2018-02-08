#!/bin/awk -f
	
BEGIN{print "NAZIONE \t CONTINENTE \n"}
{
	print $1 "\t\t" $4
}
