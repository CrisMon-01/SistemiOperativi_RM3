# per ogni linea stampa 1 e 2 campo seguti da ... poi conta linee e stampa alla fine
BEGIN {print "Scanning file"}
{
printf "line %d:%s %s...\n", NR,$1,$2;
lineCount++;
wordCount+=NF;
}
END{
    printf "lines %d, words=%d\n", lineCount,wordCount;
}