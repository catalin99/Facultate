%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

extern FILE* yyin;
#define YYERROR_VERBOSE

#define kMaxNumOfArgs 100
int argv[kMaxNumOfArgs];
int numOfArgs = 0;

void addArgumentInCurrentFunctionContext(int value)
{
  numOfArgs++;
  argv[numOfArgs-1] = value;
}

void resetCurrentFunctionContext()
{
 numOfArgs = 0;
}

#define kMaxStackSize 1000
#define kMaxNumOfIdentifiers 1000
int numOfIdentifiers = 0;

int valueStack[kMaxStackSize];
int stackCount = 0;

char identifierNames[kMaxNumOfIdentifiers][100]; //max 100 chars for an identifier
int identifierValues[kMaxNumOfIdentifiers];
int initilizedIdentifiers[kManNumOfIdentifiers];

int isIdentifierExistent(char *identName)
{
  int i;
  for(i = 0; i<numOfIdentifiers; i++)
  if( strcmp(identifierNames[i], identName) == 0)
   return 1;
   
   return 0;
  
}

void addNewIdentifier(char *identifierName)
{
   numOfIdentifiers++;
   strcpy(identifierNames[numOfIdentifiers-1], identifierName);
   printf("\n added a new identifier : %s \n", identifierName);
}

int getValueForIdentifier(char *identName)
{
  int i;
  for(i=0; i<numOfIdentifiers; i++)
   if ( strcmp(identifierNames[i], identName) == 0)
      return identifierValues[i];
      
  // if we got so far, this means the identifier is non-existent
  printf("Error! Non-existent identifier : %s ", identName);
  exit(1);
}

void setValueForIdentifier(int value, char *identName)
{
   int i;
   for(i = 0; i<numOfIdentifiers; i++)
   if( strcmp(identifierNames[i], identName) == 0)
   { identifierValues[i] = value; 
    printf("\n did set %d to identifier %s\n", value, identName);
   return;}
   
   // so far means there is no identifier
   printf("Non existent identifier while trying to set a value : %s", identName);
   exit(1);
}



void addValueInStack(int value)
{
  printf("\n adding %d value in stack \n", value);
  stackCount ++; 
  valueStack[stackCount-1] = value;
}

int isIdentifierInitilized(char *identifierName)
{
	int i;
	for(i=0; i<numOfIdentifiers; i++)
	if ( strcmp(identifierNames[i], identifierName) == 0)
      		return initilizedIdentifiers[i];
}

void addIdentifierValueInStack(char *ident)
{
	if(isIdentifierInitilized(ident))
	{
		printf("\n added %s \'s value in the stack \n", ident);
		int val = getValueForIdentifier(ident);
		addValueInStack(val);
		return;
	}
	printf("Error: uninitilized identifier used\n");
	exit(1);
}


int popValueFromStack()
{
  if(stackCount == 0)
   {
     printf("\nWARNING! INVALID POP\n");
   }
  int value = valueStack[stackCount-1];
  stackCount --;
  
  printf("\n popping %d from the stack \n", value);
  
  return value;
  }


void addTopValueInCurrentFunctionContext()
{
 int value = popValueFromStack();
 printf("\n adding topValue %d in current function context \n", value);
 addArgumentInCurrentFunctionContext(value);
}

void closeFunctionContext(char *functionName)
{
  printf(" \n closeFunctionContext for %s \n", functionName);
  
  intFunc theFunc = getFunctionFromName(functionName);
  
  if( theFunc == NULL)
   {
     printf("\n Error! No predefined function with the name: %s\n", functionName);
     exit(1);
   }
  
  int result = theFunc(argv, numOfArgs);
  addValueInStack(result);
  
  resetCurrentFunctionContext();
  
}

void addIdentifierInCurrentFunctionContext(char *identifier)
{
	if(isIdentifierInitilized(ident))
	{
		printf("\n addIdentifier %s  in current function context\n", identifier);
		int idValue = getValueForIdentifier(identifier);  
		addArgumentInCurrentFunctionContext(idValue);
		return;
	}
	printf("Error: uninitilized identifier used\n");
	exit(1);
  
}

void closeBinaryOperatorContext(char binaryOp)
{
  printf("\n close binary operator context for %c \n", binaryOp);
  
  int r = popValueFromStack();
  int l = popValueFromStack();
  
  int res = 0;
  
  switch(binaryOp)
  {
   case '+':
     res = r + l;
     break;
   case '-':
     res = l - r;
     break;
   case '*':
     res = l * r;
     break;
   case '/':
   res = l / r;
   break;
   
   default: break;
  
  }
  
  addValueInStack(res);
  
  
}

void setIndentifierInitilized(char *identifierName)
{
	int i;
	for(i=0; i<numOfIdentifiers; i++)
	if ( strcmp(identifierNames[i], identifierName) == 0)
	{
      initilizedIdentifiers[i] = 1;
      return;
    }
    
    printf("Error: Indentifier not found \n");
    exit(1);
}

void assignTopValueToIdentifier(char *ident)
{
  setIndentifierInitilized(ident);
  int value = popValueFromStack();
  printf("\n Assigning %d to %s \n", value, ident);
  setValueForIdentifier(value, ident);
}



%}


%token NR NR_INT NR_REAL NR_INT_POZ STRING CHAR ID OP_ASSIGN BEGIN_BLOCK END_BLOCK END_STMT OPEN_P CLOSED_P OP_PLUS OP_MINUS OP_MULT OP_DIV
VAL_BOOL OP_LT OP_GT OP_EQ OP_NEQ OP_LEQ OP_GEQ OP_AND OP_OR OP_NOT OP_ASSIGN_BOOL TIP_ATOMIC TIP_VOID IF ELSE FOR WHILE CLASS
BEGIN_CLASS END_CLASS BEGIN_CLASS_FUNC END_CLASS_FUNC GLOBAL_VAR COMMA VEC_OPEN VEC_CLOSE POINT EXPRAS EXPRAE EXPRBS EXPRBE PRINT
%left OP_NOT
%left OP_AND
%left OP_OR

%left OP_LT OP_GT OP_EQ OP_NEQ OP_LEQ OP_GEQ 

%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV
%start program
%%

program : sectiuneDeclaratii  sectiuneInstructiuni  {printf("\nprogram bine definit!\n");}
	;

sectiuneDeclaratii : declaratieVariabila END_STMT
		   | sectiuneDeclaratii declaratieVariabila END_STMT
		   ;

sectiuneInstructiuni : ID OP_ASSIGN expresieAritm END_STMT { assignTopValueToIdentifier($1);}
		     | sectiuneInstructiuni ID OP_ASSIGN expresieAritm END_STMT { assignTopValueToIdentifier($2);}
		     | printFunction END_STMT
		     | sectiuneInstructiuni printFunction END_STMT

asignariSimple : ID OP_ASSIGN expresieAritm END_STMT { printf("\t assignment for %s", $1);}  // assignTopValueToIdentifier($1);}
	       | asignariSimple ID OP_ASSIGN expresieAritm END_STMT { printf("\t assignment for %s", $2);}  //assignTopValueToIdentifier($2);}
	       ;

printFunction : PRINT OPEN_P ID CLOSED_P {printf("\t the value of %s is %d\n", $3, getValueForIdentifier($3));}
	      ;

corpProgram : declaratieClass
			| corpProgram declaratieClass
			| declaratieFunctie
			| corpProgram declaratieFunctie
			| GLOBAL_VAR declaratieVariabila END_STMT
			| corpProgram GLOBAL_VAR declaratieVariabila END_STMT
			;
/*corpProgram : declaratieFunctie
			;*/

declaratieClass : CLASS ID BEGIN_BLOCK contentClass END_BLOCK
				;
	    
contentClass : declaratieVariabila END_STMT
			| contentClass declaratieVariabila END_STMT
			| BEGIN_CLASS_FUNC declaratieFunctie END_CLASS_FUNC
			| contentClass BEGIN_CLASS_FUNC declaratieFunctie END_CLASS_FUNC
			;

declaratieFunctie : tipReturnat ID OPEN_P parametriInDeclarare CLOSED_P BEGIN_BLOCK bloc END_BLOCK
		          | tipReturnat ID OPEN_P CLOSED_P BEGIN_BLOCK bloc END_BLOCK
		          ;
		  

tipReturnat : TIP_ATOMIC
	    | TIP_VOID
	    ;

parametriInDeclarare : listaParametriFormali
		     | TIP_VOID
		     ;

listaParametriFormali : declaratieVariabila
	       | listaParametriFormali COMMA  declaratieVariabila
	       ;

apelFunctie : ID OPEN_P listaParametriActuali CLOSED_P {closeFunctionContext($1);}
	    | ID OPEN_P TIP_VOID CLOSED_P {closeFunctionContext($1);}
	    | ID OPEN_P CLOSED_P{closeFunctionContext($1);}
	    ;
	    
listaParametriActuali : ID {addIdentifierInCurrentFunctionContext($1);}
		      | listaParametriActuali COMMA ID {addIdentifierInCurrentFunctionContext($3);}
		      | apelFunctie
		      | listaParametriActuali COMMA apelFunctie
		      | EXPRAS expresieAritm EXPRAE {addTopValueInCurrentFunctionContext();}
		      | listaParametriActuali COMMA EXPRAS expresieAritm EXPRAE {addTopValueInCurrentFunctionContext();}
		      | EXPRBS expresieBool EXPRBE
			  | listaParametriActuali COMMA EXPRBS expresieBool EXPRBE
		      ;

ifSimpluBloc : IF OPEN_P expresieBool CLOSED_P BEGIN_BLOCK bloc END_BLOCK
	 ;

elseBloc : ELSE BEGIN_BLOCK bloc END_BLOCK
	 | ELSE ifElseBloc
	 ;

ifElseBloc : ifSimpluBloc
    	   | ifSimpluBloc elseBloc
    	   ;

forBloc : FOR OPEN_P asignare END_STMT expresieBool END_STMT asignare CLOSED_P BEGIN_BLOCK bloc END_BLOCK
	;

whileBloc : WHILE OPEN_P expresieBool CLOSED_P BEGIN_BLOCK bloc END_BLOCK
	  ;

bloc : asignare END_STMT
     | bloc asignare END_STMT
     | declaratieVariabila END_STMT
     | bloc declaratieVariabila END_STMT
     | apelFunctie END_STMT
     | bloc apelFunctie END_STMT
     | ifElseBloc
     | bloc ifElseBloc
     | forBloc
     | bloc forBloc
     | whileBloc
     | bloc whileBloc
     | accesare END_STMT
     | bloc accesare END_STMT
     ;
     
accesare: ID POINT ID
		| accesare ID POINT ID 
		| ID POINT apelFunctie
		| accesare ID POINT apelFunctie
		| ID POINT ID vec
		| accesare POINT ID POINT ID vec
		;
		
asignare : ID OP_ASSIGN expresieAritm
	 | ID OP_ASSIGN_BOOL expresieBool
	 | ID vec OP_ASSIGN expresieAritm
	 | accesare OP_ASSIGN expresieAritm
	 ;
	 
asignareDeclaratie : OP_ASSIGN expresieAritm
				   ;
	 
vec : VEC_OPEN NR_INT_POZ VEC_CLOSE
	| vec VEC_OPEN NR_INT_POZ VEC_CLOSE
	;

declaratieVariabila : TIP_ATOMIC ID {if(isIdentifierExistent($2) == 0) addNewIdentifier($2); else {printf("Already existent identifier %s!", $2); exit(1);}}
			| TIP_ATOMIC ID asignareDeclaratie  
			{
			   printf("\n asignare cu declaratie \n");
			  if(isIdentifierExistent($2) == 0) 
			  {
			    addNewIdentifier($2);
			    setIndentifierInitilized($2);
			    assignTopValueToIdentifier($2); 
			    }
			 else 
			   {
			  printf("Already existent identifier %s!", $2); 
			  exit(1);
			     }
			
			}
			/*| TIP_ATOMIC ID vec
			| TIP_ATOMIC ID vec asignareDeclaratie
			| ID ID
			| ID ID asignareDeclaratie
			| ID ID vec
			| ID ID vec asignareDeclaratie */
		    ;
	 
RHValue : NR
	| NR_INT
	| NR_REAL
	| NR_INT_POZ
	//| STRING
	//| CHAR
	;

simbolExpresie : ID {addIdentifierValueInStack($1);}
	       | RHValue {addValueInStack($1);}
	       //| ID vec
	       //| accesare
	       ;


expresieAritm : simbolExpresie
	      | expresieAritm OP_PLUS expresieAritm {closeBinaryOperatorContext('+');}
	      | OPEN_P expresieAritm OP_PLUS expresieAritm CLOSED_P {closeBinaryOperatorContext('+');}
	      | expresieAritm OP_MINUS expresieAritm {closeBinaryOperatorContext('-');}
	      | OPEN_P expresieAritm OP_MINUS expresieAritm CLOSED_P {closeBinaryOperatorContext('-');}
	      | expresieAritm OP_MULT expresieAritm {closeBinaryOperatorContext('*');}
	      | OPEN_P expresieAritm OP_MULT expresieAritm CLOSED_P {closeBinaryOperatorContext('*');}
	      | expresieAritm OP_DIV expresieAritm {closeBinaryOperatorContext('/');}
	      | OPEN_P expresieAritm OP_DIV expresieAritm CLOSED_P {closeBinaryOperatorContext('/');}
	      | apelFunctie END_STMT  // in the closing of the function context, the function result is put automatically in the stack
	      | OPEN_P apelFunctie CLOSED_P
          ;
              
simbolExpresieBool : expresieAritm
		   | VAL_BOOL
		   ;

expresieBool : simbolExpresieBool
	     | expresieBool OP_LT expresieBool
	     | OPEN_P expresieBool OP_LT expresieBool CLOSED_P
	     | expresieBool OP_GT expresieBool
	     | OPEN_P expresieBool OP_GT expresieBool CLOSED_P
	     | expresieBool OP_EQ expresieBool
	     | OPEN_P expresieBool OP_EQ expresieBool CLOSED_P
	     | expresieBool OP_LEQ expresieBool
	     | OPEN_P expresieBool OP_LEQ expresieBool CLOSED_P
	     | expresieBool OP_GEQ expresieBool
	     | OPEN_P expresieBool OP_GEQ expresieBool CLOSED_P
	     | expresieBool OP_NEQ expresieBool
	     | OPEN_P expresieBool OP_NEQ expresieBool CLOSED_P
	     | expresieBool OP_AND expresieBool
	     | OPEN_P expresieBool OP_AND expresieBool CLOSED_P
	     | expresieBool OP_OR expresieBool
	     | OPEN_P expresieBool OP_OR expresieBool CLOSED_P
	     | OP_NOT expresieBool
	     ;
%%
int main (int argc, char *argv[]) 
{
 yyin = fopen(argv[1], "r");
	return yyparse();
	}

/* Added because panther doesn't have liby.a installed. */
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
	}
