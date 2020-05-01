#!/bin/bash

if [ $# -eq 0 ]
then
    echo -n "Dati numele fisierului sursa .l : "
    read fisier
else
    fisier=$1
fi

out=`basename $fisier .c`
out+=".exe"
lex $fisier                #fisier.l----->lex.yy.c
gcc lex.yy.c -lfl -o $out         # compilare
if [ $? -eq 0 ]             # compilare fara erori
    then
        if [ $# -lt 2 ]
        then
            echo -n "Dati parametrul functiei: "
            read param
        else
            param=$2
        fi
        ./$out $param
    else   # erori la compilare                       
        printf "Compile errors\nPress Enter to exit the program"
fi
read edt
if [ -z "$edt" ]
    then exit
fi       