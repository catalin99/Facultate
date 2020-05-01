%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token IMPORT DECL IMPL TYPE START_INSTR END_INSTR END_PROGRAM FUNCTION PROCEDURE DATA_STRUCTURE IF ELSE WHILE FOR UNTIL ARRAY STRUCT CLASS_SPECIFIER MATH_OP BOOL_OP CMP_OP ASSIGN NR ID CHR RETURNED CONST NOT_BOOL_OP CREATE
%start progr
%%

/* Structura programului */
progr 	: using DECL declarations IMPL block { printf("\nSucces!\nProgram corect sintactic!\n"); }
     	;

/* importari de biblioteci */
using: IMPORT
     | using IMPORT
     ;

/* Declaratii: clase, variabile, metode */
declarations : declaration  
             | declarations declaration 
             ;

/* Tipuri de declaratii */
declaration: methods
	   | variables ';' 		
	   | aclass
	   | definedtype
	   | constants ';'
           ;

/* Structura clasei */
aclass : DATA_STRUCTURE ID ASSIGN STRUCT START_INSTR classdeclarations END_INSTR
      ;

/* Tipuri definite de utilizator */
definedtype : DATA_STRUCTURE ID ASSIGN ID START_INSTR declarations END_INSTR  
      ;

/* Declaratiile membrilor clasei */
classdeclarations : classdeclaration  
             | classdeclarations classdeclaration 
             ;

/* Membrii clasei si specificatori */
classdeclaration: methods
	   | variables ';' 		
	   | aclass
	   | CLASS_SPECIFIER
	   | constants ';'
           ;

/* Metode */
methods: FUNCTION ID '(' variables ')' ':' TYPE ';'
       | PROCEDURE ID '(' variables ')' ';'
       ;

/* Variabile */
variables: more_ids ':' TYPE
	 | more_ids ':' ARRAY TYPE
	 ;

/* Parametrii si declaratii multiple */
more_ids: ID ',' more_ids
       | ID 
       ;

/* Constante */
constants: CONST ID ':' TYPE '=' CHR
         | CONST ID ':' TYPE '=' NR
	 ;

/* Main Program 
   IMPLEMENTATION */
block : FUNCTION ID '(' variables ')' ':' TYPE START_INSTR list RETURNED ASSIGN expression ';' END_PROGRAM block
      | PROCEDURE ID '(' variables ')' START_INSTR list END_PROGRAM block
      |	FUNCTION ID '(' variables ')' ':' TYPE START_INSTR list RETURNED ASSIGN expression ';' END_PROGRAM
      | PROCEDURE ID '(' variables ')' START_INSTR list END_PROGRAM
      ;

/* Lista de instructiuni */
list : statements 
     | list statements
     | ' '
     ;

/* o singura linie de instructiune */
statements: ID ASSIGN expression ';'
	        | ID '(' funct_param ')' ';'
          | ID ASSIGN CHR ';'
          | control_instr
	        | classop ';'
          ;

classop: ID '.' CREATE '(' funct_param ')'
       | ID '.' CREATE
       | ID '.' statements
       | ID '.' ID
       ;

/* loops si declaratii conditionale */
control_instr : IF conditions START_INSTR list END_INSTR ELSE START_INSTR list END_INSTR
              | IF conditions START_INSTR list END_INSTR
              | FOR ID ASSIGN tkn UNTIL tkn START_INSTR list END_INSTR
              | WHILE conditions START_INSTR list END_INSTR
              ;

/* Tokens -pentru loop */
tkn : ID
    | NR
    ;


conditions: condition BOOL_OP conditions
	        | condition
	        ;

condition : NR
          | ID
          | ID '(' funct_param ')'
          | ID CMP_OP condition
          | NR CMP_OP condition
          ;

operator : MATH_OP
         | BOOL_OP
         | CMP_OP
         ;

expression	: ID
	 	        | NR
	 	        | ID operator expression
	 	        | NR operator expression
	 	        | ID '(' funct_param ')' operator expression
	 	        | ID '(' funct_param ')'
	 	        ;

funct_param : expression
	          | funct_param ',' expression
	          | CHR
	          | funct_param ',' CHR
	          ;



%%
int yyerror(char * s){
printf("Line %d. ERROR: %s \n",yylineno,s);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
