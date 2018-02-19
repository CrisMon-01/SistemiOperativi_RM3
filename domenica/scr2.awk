#!/binawk -f

{
qti[$4]+=$3
c[$4]+=1
}
END{
	for(i in qti)
	print i ":\t"(qti[i]/c[i])
}
