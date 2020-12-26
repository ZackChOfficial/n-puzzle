#!/bin/sh

size=25
loop=50
i=0
while [ $i -le $loop ]
do
    
    python ../gen.py -s $size > ../examples/test
    echo "\033[0;32m TEST Solvable " $i "  : " $( cat ../examples/test ) "\033[0m"
    cat ../examples/test | ../build/./n-puzzle -s
    i=`expr $i + 1`
done

echo ""

i=0
while [ $i -le $loop ]
do
    python ../gen.py -u $size > ../examples/test
    echo "\033[0;32m TEST Unsolvable " $i "  : " $( cat ../examples/test ) "\033[0m"
    cat ../examples/test | ../build/./n-puzzle -u
    i=`expr $i + 1`
done
