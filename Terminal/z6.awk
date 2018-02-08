#"/bin/awk -f

BEGIN{
	print "TOTALE \t PRODOTTO \t COSTI%"
	tot=0;
}
{
	tot+=$1;
	app[$3]=$1
}
END{
	printf("%d\n",tot)
	for(i in app)
		printf("\t %s \t %d\n",i,app[i]*100/tot)
}
