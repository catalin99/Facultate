%{
#include <stdio.h>
#include "y.tab.h"
#include<string.h>
%}
%%
begin {return BGIN;}
end {return END;}
var {return VAR;}
max {return MAX;}
min {return MIN;}
print {return PRINT;}
[a-zA-Z][a-zA-Z0-9]*  {yylval.nume=strdup(yytext);return ID;}
= {return EGAL;}
[0-9]+ {yylval.val=atoi(yytext);return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%%