%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%

"begin_class_func" {ECHO; return BEGIN_CLASS_FUNC;}
"end_class_func" {ECHO; return END_CLASS_FUNC;}

"for" {ECHO; return FOR;}
"while" {ECHO; return WHILE;}

"if" {ECHO; return IF;}
"else" {ECHO; return ELSE;}
"print" {ECHO; return PRINT;}


"int"|"float"|"char"|"string" {ECHO; return TIP_ATOMIC;}
"void" {ECHO; return TIP_VOID;}

"-" {ECHO; return OP_MINUS;}
"+" {ECHO; return OP_PLUS;}
"/" {ECHO; return OP_DIV;}
"*" {ECHO; return OP_MULT;}
"(" {ECHO; return OPEN_P;}
")" {ECHO; return CLOSED_P;}
"," {ECHO; return COMMA; }
\. {ECHO; return POINT; }


"AND" {ECHO; return OP_AND;}
"OR" {ECHO; return OP_OR;}
"NOT" {ECHO; return OP_NOT;}

"TRUE" {ECHO; return VAL_BOOL;}
"FALSE" {ECHO; return VAL_BOOL;}

"class" {ECHO; return CLASS; }
"exprae" {ECHO; return EXPRAE; }
"expras" {ECHO; return EXPRAS; }
"exprbe" {ECHO; return EXPRBE; }
"exprbs" {ECHO; return EXPRBS; }
"globalvar" {ECHO; return GLOBAL_VAR; }

\'.\' {ECHO; return CHAR; }
\".*\" {ECHO; return STRING; }
[_a-zA-Z][_a-zA-Z0-9]* {ECHO; yylval = strdup(yytext);return ID;}
0|[1-9][0-9]* {ECHO; yylval = atoi(yytext); return NR_INT_POZ;}
-?0|([1-9][0-9]*) {ECHO; yylval = atoi(yytext); return NR_INT;}
-?(0|[1-9][0-9]*)","[0-9]* {ECHO; yylval = atoi(yytext); return NR_REAL;}
[0-9]+ {ECHO;yylval = atoi(yytext) ;return NR;}
"=" {ECHO; return OP_ASSIGN;}
"{" {ECHO; return BEGIN_BLOCK;}
"}" {ECHO; return END_BLOCK;}
";" {ECHO; return END_STMT;}
"[" {ECHO; return VEC_OPEN;}
"]" {ECHO; return VEC_CLOSE;}

"<-" {ECHO; return OP_ASSIGN_BOOL;}
"<" {ECHO; return OP_LT;}
"<=" {ECHO; return OP_LEQ;}
">" {ECHO; return OP_GT;}
">=" {ECHO; return OP_GEQ;}
"==" {ECHO; return OP_EQ;}
"!=" {ECHO; return OP_NEQ;}


. {}
%%
