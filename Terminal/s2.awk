#!/bin/awk -f

BEGIN{print "ASIATICHE"}
{
if($4=="Asia")
	print $1"\t" $2"\t" $3
}

