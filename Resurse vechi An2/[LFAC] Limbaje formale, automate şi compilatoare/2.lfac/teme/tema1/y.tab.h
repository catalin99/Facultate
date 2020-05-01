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
    LOAD = 258,
    ID = 259,
    NUMAR = 260,
    TIP_DATE = 261,
    STRING = 262,
    OP_ARITMETIC = 263,
    OP_PTR = 264,
    OP_LOGIC = 265,
    BGIN = 266,
    END = 267,
    ASSIGN = 268,
    IF = 269,
    FI = 270,
    WHILE = 271,
    EOW = 272,
    FOR = 273,
    EOFF = 274,
    STOC_DATE = 275,
    INIT_FUNC = 276,
    DEFINE_FUNC = 277,
    INC = 278,
    DEC = 279,
    READ = 280,
    WRITE = 281,
    ELSE = 282,
    RUN_FUNCTION = 283,
    HAVING_PARAMS = 284
  };
#endif
/* Tokens.  */
#define LOAD 258
#define ID 259
#define NUMAR 260
#define TIP_DATE 261
#define STRING 262
#define OP_ARITMETIC 263
#define OP_PTR 264
#define OP_LOGIC 265
#define BGIN 266
#define END 267
#define ASSIGN 268
#define IF 269
#define FI 270
#define WHILE 271
#define EOW 272
#define FOR 273
#define EOFF 274
#define STOC_DATE 275
#define INIT_FUNC 276
#define DEFINE_FUNC 277
#define INC 278
#define DEC 279
#define READ 280
#define WRITE 281
#define ELSE 282
#define RUN_FUNCTION 283
#define HAVING_PARAMS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
