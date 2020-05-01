directivaprepocesare ("load"|"define")
librarie ("basic"|"extended_basic"|"basic_math"|"basic_string")
litera [a-zA-Z]
cifra [0-9]
numar [0-9]*
variabila ("_"|{litera})("_"|{litera}|{cifra})*
tipdate ("int"|"long int"|"short int"|"char"|"bool"|"float"|"double"|"long double"|"wchar_t"|"string"|"signed char"|"unsigned char"|"short"|"signed short")
string (\")([^\"])*(\")
operator_aritmetic ("+"|"-"|"*"|"/"|"%"|"=")
operator_logic ("&&"|"||"|"<="|">="|"=="|"!="|"<"|">")
stocare_date ("extern"|"static")
space_char (" ")*

%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
("$"){directivaprepocesare}{space_char}?{librarie}("\.bld") {return LOAD;}
{numar} {return NUMAR;}
{tipdate} {return TIP_DATE;}
{string} {return STRING;}
{stocare_date} {return STOC_DATE;}
{operator_aritmetic} {return OP_ARITMETIC;}
"++" {return INC;}
"--" {return DEC;}
{operator_logic} {return OP_LOGIC;}
"begin" {return BGIN;}
"end" {return END;}
"$:" {return ASSIGN;}
"if" {return IF;}
"else" {return ELSE;}
"fi" {return FI;}
"while" {return WHILE;}
"eow" {return EOW;} 
"for" {return FOR;} 
"eoff" {return EOFF;} 
"read" {return READ;}
"write" {return WRITE;}
"function$" {return INIT_FUNC;}
"define function$" {return DEFINE_FUNC;}
"run function$" {return RUN_FUNCTION;}
"having parameters:" {return HAVING_PARAMS;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
