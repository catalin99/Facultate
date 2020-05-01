%{
#include <stdio.h>
#include "y.tab.h"
#include<string.h>
%}
%%
inceput {return INCEPUT;}
sfarsit {return SFARSIT;}
variabila {return VARIABILA;}
maxim {return MAX;}
minim {return MIN;}
modul {return MOD;}
cmmdc {return CMMDC;}
cmmmc {return CMMMC;}
afiseaza {return AFISEAZA;}
[a-zA-Z][a-zA-Z0-9]*  {yylval.nume=strdup(yytext);return ID;}
"-"?[1-9][0-9]* {yylval.val=atoi(yytext);return NR;}
[ \t\f]+ ;
"\r\n"|"\n" {}
. {return yytext[0];}
%%