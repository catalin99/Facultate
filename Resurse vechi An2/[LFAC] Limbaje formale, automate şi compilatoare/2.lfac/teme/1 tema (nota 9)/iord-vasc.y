%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID CLASA INCEPUT_CLASA SFARSIT_CLASA PRIVAT PROTEJAT PUBLIC TIP PACHET INCEPUT_FUNCTIE SFARSIT_FUNCTIE DIMENSIUNE RETURNARE OPERATOR CAT_TIMP DACA ATUNCI ALTFEL DECREMENTARE INCREMENTARE ICNUTA RATIONAL SFARSIT INCEPUT LEFTLA PENTRU SIR_CARACTERE INTREG NR CARACTER SAGEATA CONST COMPARATOR_COMPLEX SCADERE
%start inceput_program
%left '+'
%left '*'
%left '-'
%left '/'
%left '%'
%left '>'
%left '<'
%left COMPARATOR_COMPLEX
%left SCADERE
%%
inceput_program  : librarii clase {printf("Programul apartine limbajului Iord-Vasc");}

librarii  : PACHET ID'!'
		  | librarii PACHET ID'!'
		  ;
			   ;
clase  : clasa 
	   | clase clasa
	   ;

clasa  :  CLASA ID definitie_clasa
	   ;

definitie_clasa  :  INCEPUT_CLASA definitie SFARSIT_CLASA
				 ;

definitie  :  bloc_privat bloc_protected bloc_public
		   ;

bloc_privat  : PRIVAT declaratii 
			 |
			 ; 

bloc_protected  : PROTEJAT declaratii
				|
				;

bloc_public  : PUBLIC declaratii
			 |
			 ;

declaratii  : variabila functie
			;


variabila  : variabila var';' 
		   |
		   ;

var  : CONST TIP iduri
	 | TIP iduri
	 | ID ID '=' 'n''o''u' ID '(' ')'
	 ;

iduri  : ID
	   | ID'='valoare
	   | ID'='ID
	   | ID '=' ID DIMENSIUNE
	   | ID DIMENSIUNE
	   | ID DIMENSIUNE '=' valoare 
	   | ID '=' 'n''o''u' TIP '(' valoare ')'
	   | ID '=' ID DIMENSIUNE ',' iduri
	   | ID ',' iduri
	   | ID'='valoare',' iduri
	   | ID'='ID',' iduri
	   | ID DIMENSIUNE',' iduri
	   | ID DIMENSIUNE '=' valoare',' iduri
	   | ID '=' 'n''o''u' TIP '(' valoare ')' ',' iduri
	   ;

valoare  : SIR_CARACTERE
		 | RATIONAL
		 | INTREG
		 | CARACTER
		 ;

functie  : TIP ID '(' parametri_da_nu ')' bloc_functie functie 
		 |
		 ;

parametri_da_nu  : parametri
				 |
				 ;

parametri  : TIP ID val_par m_m_parametri
		   | CONST TIP ID val_par m_m_parametri
		   | expresie m_m_parametri
		   ;


m_m_parametri  : ',' parametri
			   |
			   ;

val_par  : DIMENSIUNE
		 | '(' parametri ')'
		 | '=' valoare
		 |
		 ;

bloc_functie  : INCEPUT_FUNCTIE element SFARSIT_FUNCTIE
			  ;

element  : var ';' element
		 | expresie element
		 | iteratie element
		 | dacaatuncialtfel element
		 |
		 ;

expresie  : ID dreapta_3_var
		  ;
 
dreapta_3_var  : '=' dreapta ';'
			   | '=' ID '(' parametri_da_nu ')' ';'
			   | '=' ID DIMENSIUNE ';'
			   | INCREMENTARE ';'
			   | DECREMENTARE ';'
			   ;

dreapta   : dreapta '+' dreapta
          | dreapta '*' dreapta
          | dreapta SCADERE dreapta
          | dreapta '/' dreapta
          | dreapta '%' dreapta
          | dreapta '>' dreapta
          | dreapta '<' dreapta
          | dreapta COMPARATOR_COMPLEX dreapta
          | '('dreapta '+' dreapta ')'
          | '('dreapta '*' dreapta ')'
          | '('dreapta SCADERE dreapta')'
          | '('dreapta '/' dreapta')'
          | '('dreapta '%' dreapta ')'
          | '('dreapta '<' dreapta ')'
          | '('dreapta '>' dreapta ')'
          | '('dreapta COMPARATOR_COMPLEX dreapta ')'
          | ID
		  | valoare
		  ;

iteratie  : cat_timp 
		  | pentru
		  ;

cat_timp  : CAT_TIMP '(' cat_timp_element '<' cat_timp_element ')' INCEPUT element SFARSIT
		  | CAT_TIMP '(' cat_timp_element '>' cat_timp_element ')' INCEPUT element SFARSIT
		  | CAT_TIMP '(' cat_timp_element COMPARATOR_COMPLEX cat_timp_element ')' INCEPUT element SFARSIT
		  | CAT_TIMP '(' cat_timp_element ')' INCEPUT element SFARSIT
		  ;

cat_timp_element : ID
				 | expresie
				 | valoare
				 | ID '(' iduri ')'
				 | ID '(' ')'
				 ;

pentru  : PENTRU ID SAGEATA pentru_interval ':' expresie INCEPUT element SFARSIT
		| PENTRU ID SAGEATA pentru_interval ':' valoare INCEPUT element SFARSIT
		| PENTRU ID SAGEATA pentru_interval ':' ID INCEPUT element SFARSIT
		;

pentru_interval  : ID ',' ID
                 | valoare ',' ID
                 | ID ',' valoare
                 | valoare ',' valoare
                 ;

dacaatuncialtfel  : DACA '(' conditia_daca ')' ATUNCI element ICNUTA ALTFEL element LEFTLA
				  | DACA '(' conditia_daca ')' ATUNCI element ICNUTA
				  ;

conditia_daca : val_cond_daca COMPARATOR_COMPLEX val_cond_daca
			  | ID
			  | valoare
			  | expresie
			  ;

val_cond_daca : valoare
			  | ID
			  |expresie
			  ;

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 