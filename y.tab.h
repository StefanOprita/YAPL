/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    TIP = 259,                     /* TIP  */
    ASSIGN = 260,                  /* ASSIGN  */
    NR = 261,                      /* NR  */
    AUX = 262,                     /* AUX  */
    END_OF_FILE = 263,             /* END_OF_FILE  */
    CONST = 264,                   /* CONST  */
    IN = 265,                      /* IN  */
    BGIN_FUNC = 266,               /* BGIN_FUNC  */
    END_FUNC = 267,                /* END_FUNC  */
    BGIN_IF = 268,                 /* BGIN_IF  */
    END_IF = 269,                  /* END_IF  */
    BGIN_ELSE = 270,               /* BGIN_ELSE  */
    BGIN_WHILE = 271,              /* BGIN_WHILE  */
    END_WHILE = 272,               /* END_WHILE  */
    BGIN_FOR = 273,                /* BGIN_FOR  */
    END_FOR = 274,                 /* END_FOR  */
    IF = 275,                      /* IF  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277                      /* FOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define TIP 259
#define ASSIGN 260
#define NR 261
#define AUX 262
#define END_OF_FILE 263
#define CONST 264
#define IN 265
#define BGIN_FUNC 266
#define END_FUNC 267
#define BGIN_IF 268
#define END_IF 269
#define BGIN_ELSE 270
#define BGIN_WHILE 271
#define END_WHILE 272
#define BGIN_FOR 273
#define END_FOR 274
#define IF 275
#define WHILE 276
#define FOR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
