%{
#include <stdio.h>
%}
%option noyywrap
cifra_non [1-9]
cifra [0-9]
nr_1 {cifra}
nr_2 {cifra_non}{cifra}
nr_100_399 [123]{cifra}{cifra}
nr_400 400
nr {nr_1}|{nr_2}|{nr_100_399}|{nr_400}
cuvant [a-zA-Z]*[b-zB-Z][abd-zABD-Z]|[a-zA-Z]
v [,]
element {nr}|{cuvant}
elemente ({element}{v})*{element}

%%
\{{elemente}\} {fprintf(yyout,"%s \n",yytext);}
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