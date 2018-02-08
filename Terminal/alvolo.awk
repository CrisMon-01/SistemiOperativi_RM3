#!/bin/awk

BEGIN{
c=0;
FS=";";
}
{
for(i=1;i<=NF;i++){
	if($i=="Luigi")
		c++;
}
}
END{
	printf("%d\n",c);
}
