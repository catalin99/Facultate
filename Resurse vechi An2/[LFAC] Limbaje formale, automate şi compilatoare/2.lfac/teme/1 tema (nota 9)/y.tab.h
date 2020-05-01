/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    CLASA = 259,
    INCEPUT_CLASA = 260,
    SFARSIT_CLASA = 261,
    PRIVAT = 262,
    PROTEJAT = 263,
    PUBLIC = 264,
    TIP = 265,
    PACHET = 266,
    INCEPUT_FUNCTIE = 267,
    SFARSIT_FUNCTIE = 268,
    DIMENSIUNE = 269,
    RETURNARE = 270,
    OPERATOR = 271,
    CAT_TIMP = 272,
    DACA = 273,
    ATUNCI = 274,
    ALTFEL = 275,
    DECREMENTARE = 276,
    INCREMENTARE = 277,
    ICNUTA = 278,
    RATIONAL = 279,
    SFARSIT = 280,
    INCEPUT = 281,
    LEFTLA = 282,
    PENTRU = 283,
    SIR_CARACTERE = 284,
    INTREG = 285,
    NR = 286,
    CARACTER = 287,
    SAGEATA = 288,
    CONST = 289,
    COMPARATOR_COMPLEX = 290,
    SCADERE = 291
  };
#endif
/* Tokens.  */
#define ID 258
#define CLASA 259
#define INCEPUT_CLASA 260
#define SFARSIT_CLASA 261
#define PRIVAT 262
#define PROTEJAT 263
#define PUBLIC 264
#define TIP 265
#define PACHET 266
#define INCEPUT_FUNCTIE 267
#define SFARSIT_FUNCTIE 268
#define DIMENSIUNE 269
#define RETURNARE 270
#define OPERATOR 271
#define CAT_TIMP 272
#define DACA 273
#define ATUNCI 274
#define ALTFEL 275
#define DECREMENTARE 276
#define INCREMENTARE 277
#define ICNUTA 278
#define RATIONAL 279
#define SFARSIT 280
#define INCEPUT 281
#define LEFTLA 282
#define PENTRU 283
#define SIR_CARACTERE 284
#define INTREG 285
#define NR 286
#define CARACTER 287
#define SAGEATA 288
#define CONST 289
#define COMPARATOR_COMPLEX 290
#define SCADERE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
