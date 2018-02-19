#!/bin/awk -f

BEGIN{OFS = "\t";
	print "SQUADRA \tPUNTI";
}
{
	if($3>$4){
		cl[$1]+=3;
		cl[$2]+=0;
	}
		if($3<$4){
		cl[$2]+=3;
		cl[$1]+=0;
	}
		if($3==$4){
		cl[$1]+=1;
		cl[$2]+=1;
	}
}
END{
	for(i in cl){
		print i "\t\t" cl[i];
	}
}


