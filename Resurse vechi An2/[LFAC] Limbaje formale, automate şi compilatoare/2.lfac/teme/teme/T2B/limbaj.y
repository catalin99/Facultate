%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID TYPE INIT END ASSIGN NO FLOAT_NO INT_NO UNSGN_INT_NO VOID_TYPE INIT_FCN END_FCN RET TYPE_CLASS INIT_CLASS END_CLASS OP_COMP OP_INEG VAL_BOOL IF THEN END_THEN ELSE END_ELSE EXEC WHILE END_WHILE FOR END_FOR CHAR STRING_CHAR BOOL
%start progr
%%
progr: inits set {printf("PROGRAM CORECT!\n");}
     ;
inits : init ';'
	   | inits init ';'
	   ;
init : init_var
	   | func func_body
           | init_class
	   ;
init_class : TYPE_CLASS ID INIT_CLASS inits END_CLASS
	        ;
init_var : TYPE ID 
	  	    | TYPE ID ASSIGN assig_val
		    | TYPE ID init_row
		    | TYPE_CLASS ID ID
		    ;
assig_val: UNSGN_INT_NO 
		| INT_NO 
		| FLOAT_NO 
		| CHAR 
		| STRING_CHAR
 	        | ID '(' list ')'
      	 	| ID '.' ID '(' list ')'
		;
func : TYPE ID '(' list_param ')' //declar functii
       | TYPE ID '(' ')'
       | VOID_TYPE ID '(' list_param ')'
       | VOID_TYPE ID '(' ')'
       ;
func_body: INIT_FCN list_func END_FCN
	    ;
list_func : RET expresion ';'
	     | list_func RET expresion ';'
	     | statement ';' 
     	     | list_func statement ';'
	     | set_logic_func
    	     | list set_logic_func
             ;
set_logic_func: IF logic_expresion 
				THEN list_func END_THEN
			   	ELSE list_func END_ELSE
	  	  | WHILE logic_expresion
				list_func 
	    	    END_WHILE
          	  | FOR statement WHILE logic_expresion EXEC statement
				list_func
	    	     END_FOR
	  	  ;
init_row : '[' UNSGN_INT_NO ']' 
    	         | init_row '[' UNSGN_INT_NO ']'
                 ;
vector : '[' expresion ']'
       | vector '[' expresion ']'
       ;
lista_param : param
            | lista_param ','  param 
            ;
param : TYPE ID      
      ; 
set : INIT list END  
     ;   
list : set_logic /* liste instructiuni */
     | list set_logic
     | statement ';' 
     | list statement ';'	
     ;
set_logic: IF logic_expresion 
		THEN list END_THEN
	        ELSE list END_ELSE
	  | WHILE logic_expresion
		list 
	    END_WHILE
          | FOR statement WHILE logic_expresion EXEC statement
		list
	    END_FOR
	  ;
statement: init_var /* instructiuni */
	 | ID ASSIGN ID
         | ID ASSIGN UNSGN_INT_NO
         | ID ASSIGN INT_NO
         | ID ASSIGN FLOAT_NO 
         | ID ASSIGN expresion 
	 | ID vector ASSIGN expresion
         | ID '(' list ')'
	 | ID '.' ID '(' list ')'
         ;
expresion: simbol
	| expresion '+' expresion
	| '('expresion '+' expresion ')'
	| expresion '-' expresion
	| '('expresion '-' expresion ')'
	| expresion '*' expresion
	| '('expresion '*' expresion ')'
	| expresion ':' expresion
	| '('expresion ':' expresion ')'
	;
simbol: ID
      | '-' ID
      | '-' ID vector
      | ID vector
      | UNSGN_INT_NO
      | INT_NO
      | FLOAT_NO
      | ID '(' list ')'
      | ID '.' ID '(' list ')'
      ;
logic_expresion : logic_condition
		| '(' logic_condition ')'
		| logic_expresion BOOL logic_expresion
		| '(' logic_expresion BOOL logic_expresion ')'
		;
logic_condition : VAL_BOOL OP_INEG VAL_BOOL
		| VAL_BOOL OP_INEG expresion
 		| expresion OP_COMP expresion  
		| expresion OP_INEG expresion 
		| expresion OP_INEG VAL_BOOL
		;
list : expresion
           | list ',' expresion
           | STRING_CHAR
 	   | list ',' STRING_CHAR
           | CHAR
 	   | list ',' CHAR
	   |  /*empty*/
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}
int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
