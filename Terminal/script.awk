#!bin/awk -f
 
BEGIN {RS="\n"; ORS=" ";print "\n"} 
{
	print $1	
}
END{print "\n"}
