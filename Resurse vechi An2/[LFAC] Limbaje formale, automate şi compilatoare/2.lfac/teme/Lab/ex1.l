%{
#include <stdio.h>
%}
%option noyywrap
cifra_para [02468]
cifra [0-9]
nr {cifra}+
nr_par {cifra}*{cifra_para}
%%
\<{nr_par}\> {ECHO;fprintf(yyout,"\n");}
{nr_par}  {printf ("[%s]\n", yytext);}
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



