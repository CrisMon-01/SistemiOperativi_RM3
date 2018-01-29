#!/usr/bin/awk -f
BEGIN {print "Owner\tFile"}
{print $3, "\t", $9}
END {print "-DONE-"}