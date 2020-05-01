%{
#include <stdio.h>
#include "functii.h"
int erori=0;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID VAR NR BGIN END EGAL CMMDC CMMMC MAX MIN PRINT PLUS MINUS IMPARTIT ORI
%union {int val;char *nume;}
%type<nume> ID
%type<val> NR functie expresie E
%start progr
%%
progr: declaratii instructiuni {afis();if(erori==0)printf("limbaj corect sintactic\n");else printf("\nlimbaj cu %d erori",erori);}
     ;

declaratii :  declaratie ';'
     | declaratii declaratie ';'	
     ;
declaratie : VAR ID {if(declarat($2)==0)add1($2);else yyerror() ;}
    | VAR ID EGAL NR {if(declarat($2)==0)add2($2,$4);else yyerror(); }
           ;
      
/* instructiuni */
instructiuni : BGIN list END  
     ;
     
/* lista instructiuni */
list :  instructiune ';' 
     | list instructiune ';'
     ;

/* instructiune */
instructiune: ID EGAL expresie {if(declarat($1)==0)yyerror(); else atribuire($1,$3);}
            | PRINT '(' NR ')' {printf("\nprinted  %d ",$3);}
            | PRINT '(' ID ')' {if(declarat($3)==0) yyerror();else printspecial($3);}
            ;
        
expresie : E '+' E {$$=$1+$3;}
	| E '-' E {$$=$1-$3;}
	| E '*' E {$$=$1*$3;}
	| E '/' E {$$=$1/$3;}
	| E {$$=$1;}
E :   NR {$$=$1;}
      | ID {if(declarat($1)==0) yyerror();$$=val[declarat($1)];}
      | functie {$$=$1;}
      ;
functie : MAX '(' E ',' E ',' E ')' {$$=max($3,$5,$7);printf(" max=%d ",$$);}
        | MIN '(' E ',' E ',' E ')' {$$=min($3,$5,$7);printf(" min=%d ",$$);}
        ;
%%
int yyerror(char * s){
erori++;
printf("\n!!!  eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");

yyparse();
}