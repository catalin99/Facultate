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
    IMPORT = 258,
    DECL = 259,
    IMPL = 260,
    TYPE = 261,
    START_INSTR = 262,
    END_INSTR = 263,
    END_PROGRAM = 264,
    FUNCTION = 265,
    PROCEDURE = 266,
    DATA_STRUCTURE = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    UNTIL = 272,
    ARRAY = 273,
    STRUCT = 274,
    CLASS_SPECIFIER = 275,
    MATH_OP = 276,
    BOOL_OP = 277,
    CMP_OP = 278,
    ASSIGN = 279,
    NR = 280,
    ID = 281,
    CHR = 282,
    RETURNED = 283,
    CONST = 284,
    NOT_BOOL_OP = 285,
    CREATE = 286
  };
#endif
/* Tokens.  */
#define IMPORT 258
#define DECL 259
#define IMPL 260
#define TYPE 261
#define START_INSTR 262
#define END_INSTR 263
#define END_PROGRAM 264
#define FUNCTION 265
#define PROCEDURE 266
#define DATA_STRUCTURE 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define UNTIL 272
#define ARRAY 273
#define STRUCT 274
#define CLASS_SPECIFIER 275
#define MATH_OP 276
#define BOOL_OP 277
#define CMP_OP 278
#define ASSIGN 279
#define NR 280
#define ID 281
#define CHR 282
#define RETURNED 283
#define CONST 284
#define NOT_BOOL_OP 285
#define CREATE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
