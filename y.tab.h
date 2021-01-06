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
    REAL = 262,                    /* REAL  */
    STRING_CONST = 263,            /* STRING_CONST  */
    CHAR_CONST = 264,              /* CHAR_CONST  */
    ASSIGN = 265,                  /* ASSIGN  */
    AUX = 266,                     /* AUX  */
    END_OF_FILE = 267,             /* END_OF_FILE  */
    IN = 268,                      /* IN  */
    SAGETICA = 269,                /* SAGETICA  */
    EVAL = 270,                    /* EVAL  */
    FUNCTION = 271,                /* FUNCTION  */
    BGIN_FUNC = 272,               /* BGIN_FUNC  */
    END_FUNC = 273,                /* END_FUNC  */
    BGIN_IF = 274,                 /* BGIN_IF  */
    END_IF = 275,                  /* END_IF  */
    BGIN_ELSE = 276,               /* BGIN_ELSE  */
    BGIN_MEMBRS = 277,             /* BGIN_MEMBRS  */
    END_MEMBRS = 278,              /* END_MEMBRS  */
    BGIN_FUNCS = 279,              /* BGIN_FUNCS  */
    END_FUNCS = 280,               /* END_FUNCS  */
    BGIN_CLASS = 281,              /* BGIN_CLASS  */
    END_CLASS = 282,               /* END_CLASS  */
    CLASS = 283,                   /* CLASS  */
    BGIN_WHILE = 284,              /* BGIN_WHILE  */
    END_WHILE = 285,               /* END_WHILE  */
    BGIN_FOR = 286,                /* BGIN_FOR  */
    END_FOR = 287,                 /* END_FOR  */
    IF = 288,                      /* IF  */
    WHILE = 289,                   /* WHILE  */
    FOR = 290,                     /* FOR  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    GE = 293,                      /* GE  */
    LE = 294,                      /* LE  */
    EQ = 295,                      /* EQ  */
    NE = 296,                      /* NE  */
    GT = 297,                      /* GT  */
    LT = 298,                      /* LT  */
    PLUS = 299,                    /* PLUS  */
    MINUS = 300,                   /* MINUS  */
    MULT = 301,                    /* MULT  */
    DIV = 302,                     /* DIV  */
    UMINUS = 303                   /* UMINUS  */
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
#define REAL 262
#define STRING_CONST 263
#define CHAR_CONST 264
#define ASSIGN 265
#define AUX 266
#define END_OF_FILE 267
#define IN 268
#define SAGETICA 269
#define EVAL 270
#define FUNCTION 271
#define BGIN_FUNC 272
#define END_FUNC 273
#define BGIN_IF 274
#define END_IF 275
#define BGIN_ELSE 276
#define BGIN_MEMBRS 277
#define END_MEMBRS 278
#define BGIN_FUNCS 279
#define END_FUNCS 280
#define BGIN_CLASS 281
#define END_CLASS 282
#define CLASS 283
#define BGIN_WHILE 284
#define END_WHILE 285
#define BGIN_FOR 286
#define END_FOR 287
#define IF 288
#define WHILE 289
#define FOR 290
#define AND 291
#define OR 292
#define GE 293
#define LE 294
#define EQ 295
#define NE 296
#define GT 297
#define LT 298
#define PLUS 299
#define MINUS 300
#define MULT 301
#define DIV 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "yapl.y"

    char* strval;
    char chrval;
    struct nodeType* nPtr;

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
