#!/bin/awk -f

BEGIN{print "NAZIONI ASIATICHE \n"}
{
if($4 == "ASIA")
	print $1 "\t" $2 "\t" $3 "\t"
}
