#!bin/awk

{
	if($2=="*")
		printf( $1 * $3"\n");
        if($2=="/")
                printf( $1 / $3"\n");
        if($2=="+")
                printf( $1 + $3"\n");
        if($2=="-")
                printf( $1 - $3 "\n");
	if($1 == "q")
		exit;

}
