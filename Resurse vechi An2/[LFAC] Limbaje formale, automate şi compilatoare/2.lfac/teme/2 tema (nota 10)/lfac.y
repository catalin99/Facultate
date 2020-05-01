%{
#include <stdio.h>
#include "functii.h"
int erori=0;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID VARIABILA NR MAX MIN PRINT MOD CMMDC CMMMC AFISEAZA INCEPUT SFARSIT
%union {int val;char *nume;}
%type<nume> ID
%type<val> NR functie expresie
%start progr
%left '+' '-'
%left '*' '/'
%%
progr: declaratii instructiuni {if(erori==0){printf("%s",buffer); printf("program corect sintactic\n");}else printf("\nprogram cu %d erori",erori);}
     ;

declaratii :  declaratie ';'
    	   | declaratii declaratie ';'	
     	   ;

declaratie : VARIABILA ID {if(declarat($2)==-1)decl_fara_init($2);else {yyerror();printf("Variabila deja a fost declarata\n");}}
   		   | VARIABILA ID '=' NR {if(declarat($2)==-1)decl_cu_init($2,$4);else {yyerror(); printf("Variabila nu a fost declarata\n");}}
           ;
      
instructiuni : INCEPUT bloc SFARSIT  
     		 ;
     
bloc :  instructiune ';' 
     | bloc instructiune ';'
     ;

instructiune : ID '=' expresie {if(declarat($1)==-1){yyerror();printf("Variabila nu a fost declarata\n");} else atribuire($1,$3);}
             | AFISEAZA '(' NR ')' {if(erori==0){scrie_buffer_int($3);}}
             | AFISEAZA '(' ID ')' {if(declarat($3)==-1){ yyerror();printf("Variabila nu a fost declarata\n");} else if (initializat($3)==0){yyerror();printf("Variabila nu a fost initializata\n");}else if(erori==0){printspecial($3);}  }
             ;
         
expresie : expresie '+' expresie {$$=$1+$3;}
		 | expresie '-' expresie {$$=$1-$3;}
		 | expresie '*' expresie {$$=$1*$3;}
	   	 | expresie '/' expresie {$$=$1/$3;}
         | NR {$$=$1;}
         | ID {if(declarat($1)==-1){yyerror();printf("Variabila nu a fost declarata\n");}$$=variabile[declarat($1)].valoare;}
         | functie {$$=$1;}
		     ;

functie : MAX '(' expresie ',' expresie ')' {$$=maxim($3,$5);}
        | MIN '(' expresie ',' expresie ')' {$$=minim($3,$5);}
        | MOD '(' expresie ')' {$$=modul($3);}
        | CMMDC '(' expresie ',' expresie ')' {$$=cmmdc($3,$5);}
        | CMMMC '(' expresie ',' expresie ')' {$$=cmmmc($3,$5);}
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