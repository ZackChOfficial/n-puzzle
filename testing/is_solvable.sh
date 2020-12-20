#!/bin/sh

size=3
loop=50
i=0
while [ $i -le $loop ]
do
    
    python ../gen.py -s $size > ../examples/test
    echo "\033[0;32m TEST Solvable " $i "  : " $( cat ../examples/test ) "\033[0m"
    cat ../examples/test | ../out/build/./n-puzzle -s
    i=`expr $i + 1`
done

echo ""

i=0
while [ $i -le $loop ]
do
    python ../gen.py -s $size > ../examples/test
    echo "\033[0;32m TEST Unsolvable " $i "  : " $( cat ../examples/test ) "\033[0m"
    cat ../examples/test | ../out/build/./n-puzzle -u
    i=`expr $i + 1`
done
