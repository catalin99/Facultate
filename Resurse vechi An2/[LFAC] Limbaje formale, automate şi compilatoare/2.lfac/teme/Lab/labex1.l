%{
#include<stdio.h>
%}
%option noyywrap
spatiu [\t ]
newline [\n]
%%
.{spatiu}. {printf("_",yylex);}
{newline} {printf(".\n",yylex);}
.|\n {printf("%s");}
%%
int main(int argc,char** argv){
FILE *g;
if(argc>0)
    yyin=fopen(argv[1],"r");
    
if(!(g=fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else 
    yyout=g;

yylex();

}