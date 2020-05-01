%{
#include <stdio.h>
%}
%s pas
%%
password: {ECHO; BEGIN pas;}
<pas>[^ \n] {printf("*");}
<pas>[ \n] {ECHO; BEGIN 0;} 
[0-9]+ {printf("[%s]", yytext);}
%%
int main(){
yyin = fopen("ex3.txt","r");
yylex();
}
