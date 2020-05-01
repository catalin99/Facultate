%{
#include <stdio.h>
%}
cuvant ([a-d]*[f-z]*)?e([a-d]*[f-z]*)?e([a-d]*[f-z]*)? 
nr [3-9][0-9][0-9]
nr2 [1-2][0-9][0-9][0-9]
list {cuvant}|{nr}|{nr2}
%%
([(]({list}[,])+{list}[)])|([(]{list}[)]) {fprintf(yyout,"%s\n",yytext);}
.|\n;
 /*{cuvant} {ECHO;fprintf(yyout,"\n");}*/
 /*{nr} {ECHO;fprintf(yyout,"\n");}*/
 /*{nr2} {ECHO;fprintf(yyout,"\n");}*/
.|\n ;
%%
int main(){
FILE *g;
yyin = fopen("in4A-nr1.txt","r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;

yylex();

}



