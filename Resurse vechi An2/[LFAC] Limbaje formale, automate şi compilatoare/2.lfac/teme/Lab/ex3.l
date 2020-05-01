%{
#include <stdio.h>
%}
%s classkw
%option noyywrap
%%
class[ \t\n]+ {BEGIN classkw;}
<classkw>[a-zA-Z][a-zA-Z0-9]*[ \t\n]* {ECHO;}
<classkw>"{" {BEGIN 0;}
.|\n;
%%
int main(int argc, char** argv){
if(argc>0)
 yyin = fopen(argv[1],"r");
yylex();
}
