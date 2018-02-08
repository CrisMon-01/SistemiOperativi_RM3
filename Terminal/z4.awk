#!/bin/awk -f

BEGIN{a[NR]
	i=0;
	}
{
	a[NR]=$0;
		
}
END{
	for(j=0;j<=NR;j++){
		print a[(NR-j)]
}
}
