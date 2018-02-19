#!/bin/awk -f

BEGIN {RS="\n"; ORS=" ";print "\n"} {print $0} END{print "\n\n"}
