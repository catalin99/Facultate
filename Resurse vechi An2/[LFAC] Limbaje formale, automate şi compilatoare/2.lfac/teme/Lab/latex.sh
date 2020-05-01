#!/bin/bash

if [ $# -eq 0 ]
then
    echo -n "Dati numele fisierului sursa .l : "
    read fisier
else
    fisier=$1
fi

edt=$#  

while [ $edt !=  0 ]
do
    #mcedit $fisier# se va inlocui comanda mcedit cu numele editorului preferat
    echo -n "Doriti compilarea programului $fisier ? (y/n) "
    read ans
    if [ $ans = "y" ]
    then
        out=`basename $fisier .c`
        out+=".exe"
        lex $fisier     #latex  
        gcc lex.yy.c -o $out         # compilare
        if [ $? -eq 0 ]             # compilare fara erori
        then
            echo -n "Doriti executarea programului? (y/n) "
            read ans;
            if [ $ans = "y" ]
            then
                echo -n "Dati parametrul functiei, daca exista: "
                read param
                # if(param=='n')
                #then ./$out 
                #else 
                    ./$out $param
                #fi  
                let edt=edt-1
            else
                echo "Finished ..."
                exit 0
            fi
        else                       # erori la compilare
            echo "Apasa <Enter> pentru a continua ..."
            read edt               # acest read are doar rol de pauza
            
        fi
    else
        let edt=edt-1
    fi
done