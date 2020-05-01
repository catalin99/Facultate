%{
#include <stdio.h>
#include <string.h>
%}
%union {
int intval;
char* strval;
char charval;
}
%token <charval>CHR <intval>NR
%type <intval>e
%type <strval>str


%start s
%%
s : e {printf("s-a recunoscut valoarea numerica:%d\n",$<intval>$);}
 | str  {printf("s-a recunoscut sirul:%s\n",$<strval>$);}
 ;
e: '(' e '+' e ')' {printf("s-a aplicat o regula e->(e+e)\n");$$=$2+$4;}
 | NR {printf("s-a aplicat o regula e->NR\n");$$=$1;}
 ;  
str : '(' str '+' str ')' {printf("s-a aplicat o regula str->(str+str)\n"); 
			   char* s=malloc(sizeof(char)*(strlen($2)+2));
                           strcpy(s,$2); strcat(s,$4);
			   $$=s;
			 }   
    | CHR {
               printf("s-a aplicat o regula str->CH\n");
               char* s=malloc(sizeof(char));
               s[0]=$1;
               $$=s;
	     }
    ; 			 
%%
int main(){
 yyparse();
}    