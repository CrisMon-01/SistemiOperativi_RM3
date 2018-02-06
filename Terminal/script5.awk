#!bin/awk -f

BEGIN{FS = " "}
{
	b = int($7);
	while(b>0){
		printf("*");
		b=b-1;		
	}
	printf ("\n");
}
