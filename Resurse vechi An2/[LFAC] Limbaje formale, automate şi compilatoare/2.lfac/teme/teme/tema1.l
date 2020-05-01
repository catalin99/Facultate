%{
#include <stdio.h>
%}
letter [a-zA-Z]
number [0-9]
ch [ `~!@#$%^&*]
g [\"]
sir ({letter}|{number}|{ch})*
%%
("/*")({sir})("*/") {fprintf(yyout,"",yytext);}
(\n) {fprintf(yyout,"\n",yytext);}
("#include") {fprintf(yyout,"<%s INCL>",yytext);}
("<")({letter})+(".h>") {fprintf(yyout,"<%s LIB>",yytext);}
("int"|"char"|"long"|"float"|"double"|"unsigned int"|"unsigned long"|"unsigned float"|"unsigned double") {fprintf(yyout,"<%s TIP>",yytext);}
("for"|"while"|"if"|"do"|"struct"|"return"|"main"|"void"|"class"|"auto"|"break"|"case"|"continue"|"default"|"cout") {fprintf(yyout,"<%s REZ>",yytext);}
("else"|"enum"|"extern"|"goto"|"register"|"signed"|"sizeof"|"static"|"switch"|"typedef"|"union"|"volatile"|"cin") {fprintf(yyout,"<%s REZ>",yytext);}
("(") {fprintf(yyout,"<%s PARS>",yytext);}
(")") {fprintf(yyout,"<%s PARD>",yytext);}
("{") {fprintf(yyout,"<%s ACOS>",yytext);}
("}") {fprintf(yyout,"<%s ACOD>",yytext);}
("[") {fprintf(yyout,"<%s PARPS>",yytext);}
("]") {fprintf(yyout,"<%s PARPD>",yytext);}
(";") {fprintf(yyout,"<%s PV>",yytext);}
(",") {fprintf(yyout,"<%s V>",yytext);}
("=") {fprintf(yyout,"<%s ASSIG>",yytext);}
[_a-zA-Z][_a-zA-Z0-9]* {fprintf(yyout,"<%s VA>",yytext);}
[0-9]+ {fprintf(yyout,"<%s NR>",yytext);}
">"|"<"|"<="|">="|"=="|"!=" {fprintf(yyout,"<%s CO>",yytext);}
"++"|"--" {fprintf(yyout,"<%s INCDEC>",yytext);}
"+" {fprintf(yyout,"<%s ADD>",yytext);}
"-" {fprintf(yyout,"<%s DEC>",yytext);}
"*" {fprintf(yyout,"<%s MUL>",yytext);}
"/" {fprintf(yyout,"<%s IMP>",yytext);}
("*a"|"*b"|"*c"|"*d"|"*e"|"*f"|"*g"|"*h"|"*i"|"*j"|"*k"|"*l"|"*m"|"*n"|"*o"|"*p"|"*q"|"*r"|"*s"|"*t"|"*u"|"*v"|"*x"|"*z") {fprintf(yyout,"<%s POINT>",yytext);}
"+="|"-="|"/="|"*=" {fprintf(yyout,"<%s SEQ>",yytext);}
"->" {fprintf(yyout,"<%s IMPLI>",yytext);}
"<-" {fprintf(yyout,"<%s IMPLI>",yytext);}
">>" {fprintf(yyout,"<%s CIN>",yytext);}
"<<" {fprintf(yyout,"<%s COUT>",yytext);}
.|\n ;
%%
int main(){
FILE *g;
yyin = fopen("input.txt","r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;

yylex();

}



