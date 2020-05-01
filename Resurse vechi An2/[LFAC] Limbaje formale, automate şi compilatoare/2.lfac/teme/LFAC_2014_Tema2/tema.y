%{
#include <stdio.h>
#include <string.h>
void yyerror(){}
%}
%union {
int intval;
char* strval;
       }
%token <strval>CHR<intval>NR
%token EGAL
%type <intval>e
%type <strval>str
%nonassoc  '|'  EGAL
%left '(' ')'
%left '+' '-'  
%left '*'  '`' '#' '?'
 
%start s
%%
      s : e { printf("Rez: %d\n", $<intval>$); }
        | str  { if (strlen($<strval>$) != 0) 
                     printf("Rez: %s\n",$<strval>$);
                  else 
                     printf("Returneaza NULL\n"); }
        ;  
    str : '(' str ')' { $$=$2;}
        | CHR {
               char* s=malloc(sizeof(char)*strlen($1));
               strcpy(s,$1);
               $$=s;
	     }
        | str '+' str    {char* s=malloc(sizeof(char)*(strlen($1)+2));
                           strcpy(s,$1); strcat(s,$3);
                           $$=s;
                      }
        | str '-' str   {  
                           char* p=malloc(sizeof(char)*strlen($1));
                           char* s=malloc (sizeof(char)*strlen($1));
                           strcpy(s,$1);p=strstr(s,$3);
                           int a=0; 
                          
                          if(strlen(s)>= strlen($3))
                          {if (strlen($3)>0)
                            while ( p != NULL )
                         {  
                          strcpy(p,p+strlen($3));
                          p= strstr (s,$3); 
                         } $$=s;}
                           else printf("s1 < s2 : scadere \n"); 
                           
                             
                         }
        | str '*' e {  
                   char* s=malloc(sizeof(char)*(strlen($1)+$3));
                   char* st=malloc(sizeof(char)*(strlen($1)+2));
                           strcpy(st,$1); 
                   int n ; n= $3; 
                     if(n==0) printf("s1 * zero\n");
                           while(n)
                       { strcat(s,st);
                         n--;
                       }
                    
			   $$=s;
                 }

        | str '#' e  {    
                     int p; 
                     char* s=malloc(sizeof(char)*(strlen($1)));
                     strcpy(s,$1);
                     if(strlen(s)< $3 )printf("lack of chars : #\n");
                     p=strlen(s) -$3;
                     strcpy(s,s+p);
                     $$=s;
  
               }

        | e '`' str {
                  char* s=malloc(sizeof(char)*(strlen($3)));
                  char* alt=malloc(sizeof(char)*(strlen($3)));
                  int i,nr=$1;
                  strcpy(s,$3);
             
                  if(strlen(s)>nr) 
                  for (i=0;i<nr;i++)
                      alt[i]=s[i];
                  else printf("lack of chars : `\n");
                  $$=alt;

                 }
        ;
   e : '(' e '*' e ')' {$$=$2*$4;}
     | e '*' e {$$=$1*$3;}
     | '(' e '-' e ')' {$$=$2-$4;}
     | e '-' e {$$=$1-$3;}
     | '(' e '+' e ')' {$$=$2+$4;}
     | e '+' e {$$=$1+$3;}
     | NR { $$=$1; }
     | str '?' str         { 
                           char* p=malloc(sizeof(char)*strlen($1));
                           char* s=malloc (sizeof(char)*strlen($1));
                           strcpy(s,$1);p=strstr(s,$3);
                           int n=0;
                           while ( p != NULL )
                         { n++;
                          strcpy(p,p+strlen($3));
                          p=strstr (s,$3);
                         }
                             $$=n;
                         }
    | '(' str '?' str ')'   {  
                           char* p=malloc(sizeof(char)*strlen($2));
                           char* s=malloc (sizeof(char)*strlen($2));
                           strcpy(s,$2);p=strstr(s,$4);
                           int n=0;
                           while ( p != NULL )
                         { n++;
                          strcpy(p,p+strlen($4));
                          p=strstr (s,$4);
                         }
                             $$=n;
                         }
    | str EGAL  str      {
                      int a;
                      if (strcmp($1,$3) == 0 ) a=1;
                         else a=0;
                      $$=a;
                   }
    | '(' str EGAL  str ')'     {
                      int a;
                      if (strcmp($2,$4) == 0 ) a=1;
                         else a=0;
                      $$=a;
                                  }

    | '|' str '|' {  int a;a=strlen($2);
                       if (a == 0) a=0;
                      $$=a;
                     }
    | '(' '|' str '|' ')' {  int a;a=strlen($3);
                       if (a == 0) a=0;
                      $$=a;
                     }


    ; 			 
%%
int main(){
 yyparse();
}    
