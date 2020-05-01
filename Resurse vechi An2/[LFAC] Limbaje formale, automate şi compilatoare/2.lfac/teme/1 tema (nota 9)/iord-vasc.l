%{
#include <stdio.h>
#include "y.tab.h"
%}
%x comentariu
%x comentariu_linie
%%

"com:" {BEGIN comentariu_linie;}
<comentariu_linie>\n {BEGIN 0;}
<comentariu_linie>. ;
"b.com" {BEGIN comentariu;} 
<comentariu>"e.com" {BEGIN 0;}
<comentariu>. ;
"cat timp" {return CAT_TIMP;}
"pentru" {return PENTRU;}
"adevarat?"|"intreg"|"rational"|"caracter"|"sir caractere" {return TIP;}
">="|"<="|"=="|"sau"|"si" {return COMPARATOR_COMPLEX;}
"minus" {return SCADERE;}
\'.\' {return CARACTER;}
\".*\" {return SIR_CARACTERE;}
0|"-"?([1-9][0-9]*) {return INTREG;}
0|"-"?([1-9][0-9]*)"."[0-9]+|"-"?([1-9][0-9]*) {return RATIONAL;}
[0-9]+ {return NR;}
("["[0-9]+"]")+ {return DIMENSIUNE;}
"incrementat" {return INCREMENTARE;}
"decrementat" {return DECREMENTARE;}
"returnam" {return RETURNARE;}
"pachet" {return PACHET;}
"clasa" {return CLASA;}
"inceput:" {return INCEPUT;}
":sfarsit" {return SFARSIT;}
"inceput clasa->" {return INCEPUT_CLASA;}
"<-sfarsit clasa" {return SFARSIT_CLASA;}
"privat!" {return PRIVAT;}
"protejat?" {return PROTEJAT;}
"public:)" {return PUBLIC;}
"inceput functie:" {return INCEPUT_FUNCTIE;}
":sfarsit functie" {return SFARSIT_FUNCTIE;}
"daca" {return DACA;}
"atunci:" {return ATUNCI;}
":icnuta" {return ICNUTA;}
"altfel" {return ALTFEL;}
"leftla" {return LEFTLA;}
"<-" {return SAGEATA;}
"constanta" {return CONST;}
"@"[a-zA-Z][a-zA-Z0-9]* {return ID;}
[ \t] ;
\n {}
. { return yytext[0];}
