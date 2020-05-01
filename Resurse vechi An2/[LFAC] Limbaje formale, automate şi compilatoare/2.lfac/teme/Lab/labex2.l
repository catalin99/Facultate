%{
#include<stdio.h>
int sum_t=0;
int sum_suta=0;
%}
%option noyywrap
nr [0-9]*
%%
{nr} {int x=atoi(yytext);sum_t=sum_t+x;REJECT;}
{nr}00 {int x=atoi(yytext); sum_suta=sum_suta+x;}
%%
int main(int argc,char** argv){
if(argv > 0)
    yyin=fopen(argv[1],"r");
yylex();
printf("suma nr = %d \n suma nr div cu 100 = %d",sum_t,sum_suta);
}