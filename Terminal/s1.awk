#!/bin/awk -f

BEGIN{
	print "NAZIONE \t CONTINENTE"
}
{
print $1 "\t\t"$4
}
