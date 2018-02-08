#!/bin/awk

BEGIN{FS="+"
	riga=0
	colonna=0
}
{
a+=$1;b+=$2;c+=$3;
tot=($1+$2+$3);
print  "\t" $1, $2, $3,"|  "tot;
}
END{
       print "\t________________________________\n";
       print "\t" a, b, c, "--> "(a+b+c)" (Totale)","\n";
}
