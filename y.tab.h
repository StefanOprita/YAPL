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
    CONST = 260,                   /* CONST  */
    INTREG = 261,                  /* INTREG  */
    ASSIGN = 262,                  /* ASSIGN  */
    AUX = 263,                     /* AUX  */
    END_OF_FILE = 264,             /* END_OF_FILE  */
    IN = 265,                      /* IN  */
    REAL = 266,                    /* REAL  */
    STRING_CONST = 267,            /* STRING_CONST  */
    CHAR_CONST = 268,              /* CHAR_CONST  */
    FUNCTION = 269,                /* FUNCTION  */
    BGIN_FUNC = 270,               /* BGIN_FUNC  */
    END_FUNC = 271,                /* END_FUNC  */
    BGIN_IF = 272,                 /* BGIN_IF  */
    END_IF = 273,                  /* END_IF  */
    BGIN_ELSE = 274,               /* BGIN_ELSE  */
    BGIN_MEMBRS = 275,             /* BGIN_MEMBRS  */
    END_MEMBRS = 276,              /* END_MEMBRS  */
    BGIN_FUNCS = 277,              /* BGIN_FUNCS  */
    END_FUNCS = 278,               /* END_FUNCS  */
    BGIN_CLASS = 279,              /* BGIN_CLASS  */
    END_CLASS = 280,               /* END_CLASS  */
    CLASS = 281,                   /* CLASS  */
    BGIN_WHILE = 282,              /* BGIN_WHILE  */
    END_WHILE = 283,               /* END_WHILE  */
    BGIN_FOR = 284,                /* BGIN_FOR  */
    END_FOR = 285,                 /* END_FOR  */
    IF = 286,                      /* IF  */
    WHILE = 287,                   /* WHILE  */
    FOR = 288                      /* FOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define TIP 259
#define CONST 260
#define INTREG 261
#define ASSIGN 262
#define AUX 263
#define END_OF_FILE 264
#define IN 265
#define REAL 266
#define STRING_CONST 267
#define CHAR_CONST 268
#define FUNCTION 269
#define BGIN_FUNC 270
#define END_FUNC 271
#define BGIN_IF 272
#define END_IF 273
#define BGIN_ELSE 274
#define BGIN_MEMBRS 275
#define END_MEMBRS 276
#define BGIN_FUNCS 277
#define END_FUNCS 278
#define BGIN_CLASS 279
#define END_CLASS 280
#define CLASS 281
#define BGIN_WHILE 282
#define END_WHILE 283
#define BGIN_FOR 284
#define END_FOR 285
#define IF 286
#define WHILE 287
#define FOR 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "yapl.y"

    char* strval;

#line 136 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
