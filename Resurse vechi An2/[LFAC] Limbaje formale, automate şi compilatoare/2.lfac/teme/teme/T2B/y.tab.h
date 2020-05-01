/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     TYPE = 259,
     INIT = 260,
     END = 261,
     ASSIGN = 262,
     NO = 263,
     FLOAT_NO = 264,
     INT_NO = 265,
     UNSGN_INT_NO = 266,
     VOID_TYPE = 267,
     INIT_FCN = 268,
     END_FCN = 269,
     RET = 270,
     TYPE_CLASS = 271,
     INIT_CLASS = 272,
     END_CLASS = 273,
     OP_COMP = 274,
     OP_INEG = 275,
     VAL_BOOL = 276,
     IF = 277,
     THEN = 278,
     END_THEN = 279,
     ELSE = 280,
     END_ELSE = 281,
     EXEC = 282,
     WHILE = 283,
     END_WHILE = 284,
     FOR = 285,
     END_FOR = 286,
     CHAR = 287,
     STRING_CHAR = 288,
     BOOL = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define TYPE 259
#define INIT 260
#define END 261
#define ASSIGN 262
#define NO 263
#define FLOAT_NO 264
#define INT_NO 265
#define UNSGN_INT_NO 266
#define VOID_TYPE 267
#define INIT_FCN 268
#define END_FCN 269
#define RET 270
#define TYPE_CLASS 271
#define INIT_CLASS 272
#define END_CLASS 273
#define OP_COMP 274
#define OP_INEG 275
#define VAL_BOOL 276
#define IF 277
#define THEN 278
#define END_THEN 279
#define ELSE 280
#define END_ELSE 281
#define EXEC 282
#define WHILE 283
#define END_WHILE 284
#define FOR 285
#define END_FOR 286
#define CHAR 287
#define STRING_CHAR 288
#define BOOL 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


