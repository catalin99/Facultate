%{
#include <stdio.h>
int d=0;
int l=0;
int d_l=0;
%}
%START d_s l_s
%%
[d] {ECHO;BEGIN d_s;d++;printf("%d",d);}
<d_s>[ \n] {ECHO;BEGIN 0;d=0;}
<d_s>[abce-z] {ECHO;if ((d%2)!=0){d_l=d;l++;BEGIN 0;BEGIN l_s;printf("%s",yytext);} d=0;}
<l_s>[abce-z] {ECHO;if ((d_l%2)!=0){l++;printf("%s",yytext);}}
<l_s>[ \n] {ECHO;printf("\n");BEGIN 0;l=0;d_l=0;}

%%
int main(int argc, char** argv){
FILE *g;
if(argc>0)
 yyin = fopen(argv[1],"r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;

yylex();

}