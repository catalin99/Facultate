%{
#include <stdio.h>
%}
%option noyywrap
abc ((a)+(b)+(c)+)+
subsir ([a-z]*{abc}[a-z]*{abc}[a-z]*)+
nr [13579][0-9]*[13579][0-9][02468]
%%
\.{subsir}\. {fprintf(yyout,"%s \n",yytext);}
{nr}  {ECHO;}
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