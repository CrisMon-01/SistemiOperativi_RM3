#!/bin/awk -f

BEGIN{ string = "" }
{
string = string $0 " "
}
END{print string}
