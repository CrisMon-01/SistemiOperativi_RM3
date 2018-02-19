#!/bin/awk -f

{
k=0
if($4=="ASIA")
	k=1
if(k)
	print $1 "\t"$2"\t" $3 
}
