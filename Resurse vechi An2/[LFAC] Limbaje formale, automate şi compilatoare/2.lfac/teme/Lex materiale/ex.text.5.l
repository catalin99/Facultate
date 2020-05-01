%{
#include <stdio.h>
%}
cifra_non [1-9]
cifra [0-9]
nr_1 {cifra}
nr_2 {cifra_non}{cifra}
nr_100_299 [12]{cifra}{cifra}
nr_300 300
litera [a-zA-Z]
litera_x_z [a-wyA-WY]
cuvant {litera}*b{litera}*b{litera}*b{litera}*{litera_x_z}|{litera}*b{litera}*b{litera}*b{litera_x_z}*
el {cuvant}|{nr_1}|{nr_2}|{nr_100_299}|{nr_300}

el_cons {el}","
lista "["{el_cons}*{el}"]"

%%
{lista} {ECHO;fprintf(yyout,"%s\n");}  
.|\n ;  
%%
int main(int argc, char** argv){
FILE *g;
if(argc>0)
 yyin = fopen(argv[1],"r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;

yylex();

}