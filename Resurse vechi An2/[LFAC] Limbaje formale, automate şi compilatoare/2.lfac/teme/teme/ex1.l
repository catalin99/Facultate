%{
#include <stdio.h>
%}
cuvant [a-z]*b[a-z]* 
 /*nr ([1-9][0-9]*)?[02468]/[^0-9]*/
%%
{cuvant} {ECHO;fprintf(yyout,"\n");}
 /*ab+  {printf ("[%s]\n", yytext);}*/
.|\n ;  
%%
int main(int argc, char** argv){
 /*FILE *g;
if(argc>0)
 yyin = fopen(argv[1],"r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;
*/
yylex();

}



