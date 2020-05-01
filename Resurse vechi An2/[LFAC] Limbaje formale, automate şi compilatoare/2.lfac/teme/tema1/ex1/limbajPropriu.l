%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"@uses"[ ]+([A-Z]|[a-z])+[.]([A-Z]|[a-z])+; {return IMPORT;} /**/
"%DECLARATIONS:" {return DECL;} /*cuvant folosit sa anuntam ca incep declaratiile*/
"%IMPLEMENTATION:" {return IMPL;} /*cuvant folosit sa anuntam ca incepe implementarea*/
"var_N"|"var_Z"|"var_R"|"string"|"bool"|"char" {return TYPE;}/*tipuri de variabile*/
"start" {return START_INSTR;}
"end" {return END_INSTR;}
"end." {return END_PROGRAM;}
"function" {return FUNCTION;}
"procedure" {return PROCEDURE;}
"$type" {return DATA_STRUCTURE;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"until" {return UNTIL;}
"Result" {return RETURNED;}
"permanent" {return CONST;}
"create" {return CREATE;}
"array"[ ]("["0\-[1-9][0-9]*"]")+[ ]"of" {return ARRAY;}
"class"|"record" {return STRUCT;}
("private"|"public"|"protected")[ ]"section" {return CLASS_SPECIFIER;}
"#".* ;
"+"|"-"|"*"|"/"|"%" {return MATH_OP;}
"^"|"&"|"|"|"<<"|">>" {return BOOL_OP;}
"!" {return NOT_BOOL_OP;}
"<"|">"|"=="|"<>"|"<="|">=" {return CMP_OP;}
[_a-zA-Z][_a-zA-Z0-9]*("["[0-9]+"]")* { return ID;}
":=" {return ASSIGN;}
(-?[1-9][0-9]*("."[0-9]+)?)|0 {return NR;}
(\~.+\~) {return CHR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
