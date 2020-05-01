%{
#include <stdio.h>
%}
cifra [0-9]
cifra_p [02468]
cifra_nz [1-9]
nr {cifra_nz}{cifra}*{cifra_p}|{cifra_p}
%%
\<{nr}(,{nr})*\> {ECHO;fprintf(yyout,"\n");}
ab+  {printf ("[%s]\n", yytext);}
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