%{
   #include<stdio.h>
	#include<iostream>
   #include<math.h>
   #include<list>
	using namespace std;

   FILE *output2;
   list<char *> listVar,listStru,listApl;

%}
%x comm
%s stru
%s variabila
cifra [0-9]
letter [a-zA-Z]
cuv {letter}+
ID {letter}({letter}|{cifra})*
number 0|([1-9]{cifra}*) 
%%
("#include") {fprintf(yyout,"<%s INCL>",yytext);}
("<")({letter})+(".h>") {fprintf(yyout,"<%s LIB>",yytext);}
"/*" {BEGIN comm;} 
<comm>"*/" {BEGIN 0;}
<comm>. ;
({ID}\(\)) { 
					char *date=new char[strlen(yytext)];
					strcpy(date,yytext);
					listApl.push_back(date);
	    REJECT;
	   }
{ID}\((({ID}|{number}),)*({ID}|{number})\) { 					
					char *date=new char[strlen(yytext)];
					strcpy(date,yytext);
					listApl.push_back(date);
						REJECT;
					    }
if|else|return|for|while|do|switch|case|default|goto|try|catch|template|this|const|auto|static|sizeof|typedef|namespace|define|register|union|enum|public|protected|private {
			 
	                 printf("<%s REZ>",yytext);
			}
 
unsigned|signed|int|short|float|long|double|char { 
						BEGIN variabila;
    					        printf("<%s TIP>",yytext);
					}
<variabila>{ID} {
		BEGIN 0;
		char *date=new char[strlen(yytext)];
		strcpy(date,yytext);
		listVar.push_back(date);
		REJECT;
		}
struct|class {
		printf("<%s REZ>",yytext);
		BEGIN stru;
	     }
<stru>; {BEGIN 0;}
<stru>{ID} {			char *date=new char[strlen(yytext)];
					strcpy(date,yytext);
					listStru.push_back(date);
		   }
{ID} {printf("<%s VA>",yytext);}
("(") {fprintf(yyout,"<%s PARS>",yytext);}
(")") {fprintf(yyout,"<%s PARD>",yytext);}
("{") {fprintf(yyout,"<%s ACOS>",yytext);}
("}") {fprintf(yyout,"<%s ACOD>",yytext);}
("[") {fprintf(yyout,"<%s PARPS>",yytext);}
("]") {fprintf(yyout,"<%s PARPD>",yytext);}
(";") {fprintf(yyout,"<%s PV>",yytext);}
(",") {fprintf(yyout,"<%s V>",yytext);}
("=") {fprintf(yyout,"<%s ASSIG>",yytext);}
[0-9]+ {fprintf(yyout,"<%s NR>",yytext);}
">"|"<"|"<="|">="|"=="|"!=" {fprintf(yyout,"<%s CO>",yytext);}
"++"|"--" {fprintf(yyout,"<%s INCDEC>",yytext);}
"+" {fprintf(yyout,"<%s ADD>",yytext);}
"-" {fprintf(yyout,"<%s DEC>",yytext);}
"*" {fprintf(yyout,"<%s MUL>",yytext);}
"/" {fprintf(yyout,"<%s IMP>",yytext);}
(" *a"|" *b"|" *c"|" *d"|" *e"|" *f"|" *g"|" *h"|" *i"|" *j"|" *k"|" *l"|" *m"|" *n"|" *o"|" *p"|" *q"|" *r"|" *s"|" *t"|" *u"|" *v"|" *x"|" *z") {fprintf(yyout,"<%s POINT>",yytext);}
"+="|"-="|"/="|"*=" {fprintf(yyout,"<%s SEQ>",yytext);}
"->" {fprintf(yyout,"<%s IMPLI>",yytext);}
"<-" {fprintf(yyout,"<%s IMPLI>",yytext);}
">>" {fprintf(yyout,"<%s CIN>",yytext);}
"<<" {fprintf(yyout,"<%s COUT>",yytext);}
\n {ECHO;}
\t ;
. ;

%%
int main()
{
     stdin=fopen("input.txt","r");
     stdout=fopen("output1.txt","w");
     output2=fopen("output2.txt","w");
       yylex();
       
     list<char *>::iterator i;
     fprintf(output2,"Variabile:");

    for(i=listVar.begin(); i != listVar.end(); ++i)
           {
           fprintf(output2,"%s ",*i);
			}
      fprintf(output2,"\n");
      
          fprintf(output2,"\nStructur:");

    for(i=listStru.begin(); i != listStru.end(); ++i)
            fprintf(output2,"%s ",*i);
      fprintf(output2,"\n");
       
    fprintf(output2,"\nApel Functii:");

    for(i=listApl.begin(); i != listApl.end(); ++i)
            fprintf(output2,"%s ",*i);
      fprintf(output2,"\n");
     
   
 
      return 0;
}
