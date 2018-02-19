#!/bin/awk -f

{
k = 1
for(i=2;i<=NF;i++)
	if($i<0||$i>90)
		k=0;
for(i=2;i<=NF&&k;i++){
	e[$i]++;
}	
}
END{
	for(i in e){
		printf i "\t" e[i] "\n" | "sort -k 1n"
	}
}
