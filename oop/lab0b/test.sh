#!/bin/bash 
for ((i=1; i <= $5; ++i))
do
    dd status=none if=/dev/urandom of=in.txt bs=1M count=1
    echo -ne "\n$i"
    ./$1 $2 $3
    `LC_ALL=C sort $2 > $4`
    if cmp $3 $4
    then
        echo -n " OK"
    else
        exit
    fi
done
echo
