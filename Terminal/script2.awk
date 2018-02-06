#!bin/awk

BEGIN{ FS=";"}
{
for(j=1;j<NF;j++){
	if($j=="Luigi")
	c++
}

}

END{ printf("%d\n",c);}
