#!/bin/bash
if [ $# -eq 0 ]
then
    echo -n "Dati numele fisierului sursa .y : "
    read fisier_yacc
    echo -n "Dati numele fisierului sursa .l : "
    read fisier_lex
else
   
    if [ $# -eq 1 ]
then
    echo -n "Dati numele fisierului sursa .l : "
    read fisier_lex
    fisier_yacc=$1
else
	fisier_yacc=$1
    fisier_lex=$2
	fi
fi
out=`basename $fisier_lex .c`
out+=".exe"
yacc $fisier_yacc -d
lex -ll $fisier_lex                #fisier.l----->lex.yy.c
gcc lex.yy.c y.tab.c -lfl -ly -o $out         # compilare
if [ $? -eq 0 ]             # compilare fara erori
    then
        if [ $# -lt 3 ]
        then
            echo -n "Dati parametrul functiei: "
            read param
        else
            param=$3
        fi
        ./$out $param
    else   # erori la compilare                       
        printf "Compile errors\nPress Enter to exit the program"
fi
read edt
if [ -z "$edt" ]
    then exit
fi       