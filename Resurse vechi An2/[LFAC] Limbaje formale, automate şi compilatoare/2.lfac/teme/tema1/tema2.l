librarie ("iostream"|"conio"|"string"|"fstream"|"math"|"stdio"|"stdlib"|"errno"|"unistd"|"netdb")
directivaprepocesare ("include"|"define"|"ifndef"|"endif"|"ifdef"|"pragma")
litera [a-zA-Z]
cifra [0-9]
numar [0-9]*
string (\")([^\"])*(\")
variabila ("_"|{litera})("_"|{litera}|{cifra})*
operator_relational ("=="|"!="|">"|"<"|">="|"<=")
operator_aritmetic ("+"|"-"|"*"|"/"|"++"|"--"|"%"|"=")
comentariu ("/*")([^"*/"]|"*")*("*/")
comentariu_linie "//"
cuvant_rezervat ("while"|"throw"|"case"|"try"|"catch")
instr_control ("if"|"for"|"switch")
instr_control_oprire ("return;"|"break;"|"continue;")
tipdate ("int"|"long int"|"short int"|"char"|"bool"|"float"|"double"|"long double"|"wchar_t"|"string"|"signed char"|"unsigned char"|"short"|"signed short"|"signed short int"|"unsigned short"|"unsigned short int"|"long unsigned"|"long int")
functie ("printf"|"scanf"|"fprintf"|"fscanf"|"putc"|"getc"|"cout"|"cin"|"system"|"perror")
space_char (" ")*
declarare_var ({tipdate}"*"?{space_char}{variabila}("["{numar}?"]")?{space_char}?("=")?{space_char}?({variabila}|{numar})?("+"|"-"|"*"|"/")?({variabila}|{numar})?)
continuare_declarare ({variabila}("["{numar}?"]")?{space_char}?("=")?{space_char}?({variabila}|{numar})?("+"|"-"|"*"|"/")?({variabila}|{numar})?)
vector "["{space_char}?{numar}{space_char}?"]"
%START cond_start_class
%START cond_start_struct
%START cond_start_dowhile

%{
#include <stdio.h>
#include <string.h>
FILE *in,*out;
%}

%%
("#"){directivaprepocesare} {printf("%s este o directiva de preprocesare\n",yytext);
			     fprintf(out,"<FONT style=\"color: #0A2A29\">%s</FONT>",yytext);
			    }
("<")({librarie})("\.h")(">") {printf("%s este librarie\n",yytext);
			       int i;
			       fprintf(out,"<FONT style=\"color: #930\">&lt;",yytext);
			       for(i=1;i<strlen(yytext)-1;i++)
                                fprintf(yyout,"%c",yytext[i]);
	                       fprintf(out,"&gt;</FONT>");
                              }
{cuvant_rezervat}/{space_char} {printf("%s este un cuvant rezervat/instructiune de control a executiei programului)\n",yytext);
				fprintf(out,"<FONT style=\"color: #00F\">%s</FONT>",yytext);
			       }
{variabila} {printf("%s este variabila(identificator)\n",yytext);
	     fprintf(out,"<FONT style=\"color: #09F\">%s</FONT>",yytext);
            }
{declarare_var}({space_char}?","{space_char}?{continuare_declarare})*";" {printf("%s este o declarare de variabile\n",yytext);
								          fprintf(out,"<FONT style=\"BACKGROUND-COLOR: #FC9;\">%s</FONT>",yytext);
								         }		
{instr_control}/{space_char}?"("{space_char}|{instr_control_oprire} {printf("%s este o instructiune de control a executiei programului\n",yytext);
						                     fprintf(out,"<FONT style=\"color: #00F\">%s</FONT>",yytext);
							            }
{instr_control_oprire} {printf("%s este un cuvant rezervat/instructiune de control a executiei programului\n",yytext);
		        fprintf(out,"<FONT style=\"color: #00F\">%s</FONT>",yytext);
		       }
{tipdate}{space_char}{variabila}{space_char}"("{space_char}?({space_char}?{tipdate}{space_char}{variabila}{vector}?({space_char}?","{space_char}?{tipdate}{space_char}{variabila}{vector}?)*{space_char})?");" {printf("%s este o definire de functie\n",yytext);
			       		  fprintf(out,"<FONT style=\"color: #61380B\">%s</FONT>",yytext);
			                 }
{tipdate}{space_char}{variabila}{space_char}"("{space_char}?({space_char}?{tipdate}{space_char}{variabila}{vector}?({space_char}?","{space_char}?{tipdate}{space_char}{variabila}{vector}?)*{space_char})?")"/{space_char}*"{" {printf("%s este o declarare de functie\n",yytext);
			         			  fprintf(out,"<FONT style=\"color: #61380B\">%s</FONT>",yytext);
			                                 }
{variabila}{space_char}?"("{space_char}?(({variabila}|{numar}|({variabila}{vector}))({space_char}?","{space_char}?({variabila}|{numar}|({variabila}{vector})))*)?{space_char}?");" {printf("%s este un apel de functie\n",yytext);fprintf(out,"<FONT style=\"color: #DF0101\">%s</FONT>",yytext);}
{functie}/{space_char}?"(" {printf("%s este un apel de functie\n",yytext);
			    fprintf(out,"<FONT style=\"color: #DF0101\">%s</FONT>",yytext);
			   }
"private"|"public"|"friend" {printf("%s este specifica disponibilitatea datelor dintr-o clasa\n",yytext);fprintf(out,"%s",yytext);}
class/{space_char} {BEGIN cond_start_class;
		    fprintf(out,"<FONT style=\"color: #088A08\">%s",yytext);	
		   }
<cond_start_class>{space_char}{variabila} {BEGIN 0; 
                               printf("%s este o clasa\n",yytext);
 			       fprintf(out,"%s</FONT>",yytext);
                              }
struct/{space_char} {BEGIN cond_start_struct;
		    fprintf(out,"<FONT style=\"color: #DF0174\">%s",yytext);	
		    }
<cond_start_struct>{space_char}{variabila} {BEGIN 0; 
                               		    printf("%s este o structura\n",yytext);
 			       		    fprintf(out,"%s</FONT>",yytext);
                             		   }
do/{space_char}?"{" {BEGIN cond_start_dowhile;
		     fprintf(out,"<FONT style=\"color: #00F\">%s",yytext);	
		    }
<cond_start_dowhile>while/{space_char}?"(" {BEGIN 0; 
                               		    printf("do...%s este o instructiune de control a executiei programului\n",yytext);
 			       		    fprintf(out,"%s</FONT>",yytext);
                             		   }
{operator_relational} {printf("%s este un operator relational\n",yytext);
		       fprintf(out,"<FONT style=\"color: #00FFFF\">%s</FONT>",yytext);
                      }
{operator_aritmetic} {printf("%s este un operator aritmetic\n",yytext);
		      fprintf(out,"<FONT style=\"color: #FFFF00\">%s</FONT>",yytext);
                     }
{comentariu} {printf("%s este un comentariu\n",yytext);
              fprintf(out,"<FONT style=\"color: #FF8000\">%s</FONT>",yytext);
             }
{comentariu_linie}{space_char}?{variabila} {printf("%s este un comentariu de linie\n",yytext);
             	    			    fprintf(out,"<FONT style=\"color: #FF8000\">%s</FONT>",yytext);
                   			   }
{string} {printf("%s este un string\n",yytext);
          fprintf(out,"<FONT style=\"color: #AC58FA\">%s</FONT>",yytext);
         }
("\n")	{fprintf(out,"<br />");}
("\t")  {printf("tab character");}

%%

int main(int argc,char** argv){
if(argc>0)
 yyin=fopen(argv[1],"r");
if(!(out=fopen("index.html","w")))
 fprintf(stderr,"Eroare creare fisier!");
else
  fprintf(out,"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
  fprintf(out,"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
  fprintf(out,"<head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n<title>Syntax Highlight</title>\n</head>\n<body bgcolor=#D8D8D8>\n<p>Codul sursa al fisierului analizat (syntax highlight)</p>\n<hr />\n<p><br /><span style=\"font-style: italic;\">LEGENDA COLORARII</span><br />\n<span style=\"color: #0A2A29\"><br />\nbloc_text - directiva de preprocesare<br />\n<span style=\"color: #930\">bloc_text - librarie</span>\n</span><br />\n<span style=\"color: #00F\">bloc_text - cuvant rezervat/instructiune de control a executiei programului</span>\n</span><br />\n<span style=\"color: #09F\">bloc_text - variabila (identificator)</span>\n</span><br />\n<span style=\"BACKGROUND-COLOR: #FC9;\">bloc_text - declarare variabile</span>\n</span><br />\n<span style=\"color: #61380B\">bloc_text - definire functie</span>\n</span><br />\n<span style=\"color: #61380B\">bloc_text - declarare functie</span>\n</span><br />\n<span style=\"color: #DF0101\">bloc_text - apel de functie</span>\n</span><br />\n<span style=\"color: #088A08\">bloc_text - clasa</span>\n</span><br />\n<span style=\"color: #DF0174\">bloc_text - structura</span>\n</span><br />\n<span style=\"color: #00FFFF\">bloc_text - operator relational</span>\n</span><br />\n<span style=\"color: #FFFF00\">bloc_text - operator aritmetic</span>\n</span><br />\n<span style=\"color: #FF8000\">bloc_text - comentariu</span>\n</span><br />\n<span style=\"color: #AC58FA\">bloc_text - string</span>\n</span><br /><br />");
  yyout=out;
yylex();
fprintf(out,"</p>\n</body>\n</html>");
}
