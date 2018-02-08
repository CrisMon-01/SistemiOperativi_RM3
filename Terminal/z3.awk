#!/bin/aewk

BEGIN{
	FS=";"
}
{
for(i=1;i<NF;i++){
	if($i=="Luigi")
		c++
}
}
END{printf("Nel file Luigi ricorre %d volte\n",c)}
