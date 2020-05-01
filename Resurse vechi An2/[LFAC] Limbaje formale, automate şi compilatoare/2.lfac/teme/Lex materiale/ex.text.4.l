%{
#include <stdio.h>
%}
litera_a [b-zB-Z]
litera_c [abd-zABD-Z]
litera [a-zA-Z]
cifra_non [1-9]
cifra [0-9]
nr_1 {cifra}
nr_2 {cifra_non}{cifra}
nr_100_399 [123]{cifra}{cifra}
nr_400 400
nr {nr_1}|{nr_2}|{nr_100_399}|{nr_400}
cuvant ({litera}*{litera_c})|({litera}*{litera_a}{litera})
v [,]
element {nr}|{cuvant}
%%
"{"({element}{v})*{element}"}" {ECHO;fprintf(yyout,"\n");}
.|\n   
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