#!bin/awk

{
nomi[NR] = $1
}
END{for(i = NR;i>=1;i--)
	print nomi[i]
}
