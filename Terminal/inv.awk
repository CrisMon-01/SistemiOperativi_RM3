#!/bin/awk -f

{
	arr[NR] = $1;
}
END{for(i = NR;i>=1;i--)
	print arr[i];
}
