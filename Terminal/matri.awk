#!/bin/awk -f

BEGIN{ FS = "+";}
{
	print $1"\t"$2"\t"$3" \t |" $1+$2+$3
	a+=$1;
	b+=$2;
	c+=$3;
}
END{
	print a"\t"b"\t"c"\t  "(a+b+c)
}
