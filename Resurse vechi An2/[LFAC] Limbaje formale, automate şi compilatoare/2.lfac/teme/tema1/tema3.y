%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token LOAD ID NUMAR TIP_DATE STRING OP_ARITMETIC OP_PTR OP_LOGIC BGIN END ASSIGN IF FI WHILE EOW FOR EOFF STOC_DATE INIT_FUNC DEFINE_FUNC INC DEC READ WRITE ELSE RUN_FUNCTION HAVING_PARAMS
%start translation_unit
%%
translation_unit
	: LOAD prototip_declaratii mainprogram {printf( "Program corect sintactic!\n" );} 
	;
prototip_declaratii
	: declaratii
	| declaratii definire_functii
	;
declaratii
	: declaratie
	| declaratii declaratie
	;
declaratie
	: decl1
	| decl2
	| decl1 '('params')' 
	| decl2 '('params')'
	| decl1 '['params_vector']'
	| decl2 '['params_vector']'
	;
decl1
	: TIP_DATE ID
	| decl1 ',' TIP_DATE ID
	;
decl2
	: STOC_DATE TIP_DATE ID
	| decl2 ',' STOC_DATE TIP_DATE ID
params
	: NUMAR
	| STRING
	;
params_vector
	: NUMAR
	| params_vector ',' NUMAR
	| STRING
	| params_vector ',' STRING
	;
definire_functii
	: definire_functie
	| definire_functii definire_functie
	;
definire_functie
	: INIT_FUNC TIP_DATE ID '(' ')'
	| INIT_FUNC STOC_DATE TIP_DATE ID '(' ')'
	| INIT_FUNC TIP_DATE ID '(' args_func ')'
	| INIT_FUNC STOC_DATE TIP_DATE ID '(' args_func ')'
	;
args_func
	: TIP_DATE ID
	| args_func ',' TIP_DATE ID
	| STOC_DATE TIP_DATE ID
	| args_func ',' STOC_DATE TIP_DATE ID
	;
mainprogram
	: declarare_functii
	| instructiuni
	| declarare_functii instructiuni apel_functii
	| instructiuni declarare_functii apel_functii
	;
apel_functii
	: RUN_FUNCTION ID
	| apel_functii RUN_FUNCTION ID
	| RUN_FUNCTION ID HAVING_PARAMS '['params_vector']'
	| apel_functii RUN_FUNCTION ID HAVING_PARAMS '['params_vector']'
	;
declarare_functii
	: DEFINE_FUNC ID BGIN instructiuni END
	| declarare_functii DEFINE_FUNC ID BGIN instructiuni END
	| DEFINE_FUNC ID '(' args_func ')' BGIN instructiuni END
	|declarare_functii DEFINE_FUNC ID '(' args_func ')' BGIN instructiuni END
	;
instructiuni
	: instruc_aritmetice 
	| instructiuni instruc_aritmetice 
	| instruc_control
	| instructiuni instruc_control
	| instruc_io
	| instructiuni instruc_io
	;
instruc_io
	: READ ID
	| WRITE ID
	;
instruc_aritmetice
	: ID
	| ID OP_ARITMETIC instruc_aritmetice
	| ID ASSIGN ID
	| ID ASSIGN NUMAR
	| ID INC
	| ID DEC
	| ID ASSIGN ID INC
	| ID ASSIGN ID DEC
	| ID ASSIGN ID OP_ARITMETIC instruc_aritmetice
	;
instruc_control
	: IF '('conditii_logice')' BGIN instructiuni END FI
	| IF '('conditii_logice')' BGIN instructiuni END ELSE BGIN instructiuni END FI
	| WHILE '('conditii_logice')' BGIN instructiuni END EOW
	| FOR '(' ID ASSIGN date_cond ';' date_cond OP_LOGIC date_cond ';' ID ASSIGN instruc_aritmetice ')' BGIN instructiuni END EOFF
	| FOR '(' ID ASSIGN date_cond ';' date_cond OP_LOGIC date_cond ';' ID INC ')' BGIN instructiuni END EOFF
	| FOR '(' ID ASSIGN date_cond ';' date_cond OP_LOGIC date_cond ';' ID DEC ')' BGIN instructiuni END EOFF
	;
conditii_logice
	: date_cond
	| date_cond operator conditii_logice
	;
date_cond
	: ID
	| NUMAR
	;
operator
	: OP_ARITMETIC
	| OP_LOGIC
	;

%%
int yyerror(char * s){
printf("[err]: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
/*int yydebug=1;*/
yyin=fopen(argv[1],"r");
yyparse();
} 