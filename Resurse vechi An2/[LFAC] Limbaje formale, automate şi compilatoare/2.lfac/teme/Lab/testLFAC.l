
%{
#include <stdio.h>
int line_no=1;
%}
%option noyywrap
nume ([a-zA-Z])+
prenume ([a-zA-Z])+
numar [0-9]
nr_x [4-9]
an (19{nr_x}{numar})|(2000)
spatiu [ ] 
douap [:]
virgula [,]
NUME_X {nume}{spatiu}{prenume}{douap}{an}
secventa ({NUME_X}{virgula})*{NUME_X}
%%
\[{secventa}\] {fprintf(yyout,"%d %s \n",line_no,yytext);line_no++;}
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