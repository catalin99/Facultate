%{
#include <stdio.h>
int i=0;
%}
an 19[456789][0-9]|2000
nume_prenume [A-Z][a-z]*
element {nume_prenume}" "{nume_prenume}":"{an}
element_urmator {nume_prenume}" "{nume_prenume}":"{an}","
lista "["(({element})|({element_urmator}*{element}))"]"

%%
{lista} {i++;fprintf(yyout,"%d.",i);ECHO;fprintf(yyout,"\n");}  
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