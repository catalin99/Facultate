%{
#include <stdio.h>
%}
%option noyywrap
abc ((a)+(b)+(c)+)+
impar [13579]
par [02468]
nr {impar}{par}({impar}{par})+{impar}?
subsir [a-z]*{abc}[a-z]*|[a-z]*{abc}[a-z]*({abc}[a-z]*{abc}[a-z]*)*[a-z]*
%%
{subsir} {fprintf(yyout,"%s \n",yytext);}
\ {nr}\  {ECHO;}
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