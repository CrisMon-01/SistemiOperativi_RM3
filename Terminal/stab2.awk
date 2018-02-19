#!/bin/awk -f

BEGIN{ FS=";";
	c=0;}
{
for(i=1;i<=NF;i++)
	if($i=="Luigi")	
		c++;
}
END{print "IL NOME LUIGI OCCORRE :" c}

