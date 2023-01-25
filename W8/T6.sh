#!/bin/bash

# Bash script that prints the 10 most common words (case insensitive) from an input file.

if [ ! -z "$1" ]
then
    grep -E '\w+' $1 -o|sort | uniq -ci | sort -g | tail -n 10 | sort -rg
fi

: '
./T6.sh test_text.txt
    573 and
    562 the
    472 i
    337 to
    275 you
    267 of
    264 a
    240 in
    201 my
    195 is
' 