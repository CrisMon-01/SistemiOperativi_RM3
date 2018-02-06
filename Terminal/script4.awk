#!/usr/bin/awk -f

BEGIN{FS=" "; OFS=":"}
{
if($1 == "A:"){
	printf("A:")	
	for(i = 2;i<=NF;i++){
		if($i ~ /[0-9]/)		
		printf("%d ",$i*2);
		else printf("%s ",$i);
}
}
	else for(i = 1;i<=NF;i++)
		printf("%s ",$i);
	printf("\n");
}

