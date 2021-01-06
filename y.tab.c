/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yapl.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "hashTable.h"
    #include "stiva.h"
    #include "scope.h"
    #include "symbolTable.h"
    #include "errorHandling.h"
    #include "syntaxTree.h"
    #include "parseSyntaxTree.h"


    #define RED   "\x1B[31m"
    #define GRN   "\x1B[32m"
    #define YEL   "\x1B[33m"
    #define BLU   "\x1B[34m"
    #define MAG   "\x1B[35m"
    #define CYN   "\x1B[36m"
    #define WHT   "\x1B[37m"
    #define RESET "\x1B[0m"

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 
    extern struct stiva_nod *top;
    extern char * currentTypeDeclared;
    int shouldParse = 1;

#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CLASS = 264,                   /* CLASS  */
    CHAR_CONST = 265,              /* CHAR_CONST  */
    ASSIGN = 266,                  /* ASSIGN  */
    AUX = 267,                     /* AUX  */
    END_OF_FILE = 268,             /* END_OF_FILE  */
    IN = 269,                      /* IN  */
    SAGETICA = 270,                /* SAGETICA  */
    EVAL = 271,                    /* EVAL  */
    FUNCTION = 272,                /* FUNCTION  */
    BGIN_FUNC = 273,               /* BGIN_FUNC  */
    END_FUNC = 274,                /* END_FUNC  */
    BGIN_IF = 275,                 /* BGIN_IF  */
    END_IF = 276,                  /* END_IF  */
    BGIN_ELSE = 277,               /* BGIN_ELSE  */
    BGIN_MEMBRS = 278,             /* BGIN_MEMBRS  */
    END_MEMBRS = 279,              /* END_MEMBRS  */
    BGIN_FUNCS = 280,              /* BGIN_FUNCS  */
    END_FUNCS = 281,               /* END_FUNCS  */
    BGIN_CLASS = 282,              /* BGIN_CLASS  */
    END_CLASS = 283,               /* END_CLASS  */
    BGIN_WHILE = 284,              /* BGIN_WHILE  */
    END_WHILE = 285,               /* END_WHILE  */
    BGIN_FOR = 286,                /* BGIN_FOR  */
    END_FOR = 287,                 /* END_FOR  */
    IF = 288,                      /* IF  */
    WHILE = 289,                   /* WHILE  */
    FOR = 290,                     /* FOR  */
    NOT = 291,                     /* NOT  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    GE = 294,                      /* GE  */
    LE = 295,                      /* LE  */
    EQ = 296,                      /* EQ  */
    NE = 297,                      /* NE  */
    GT = 298,                      /* GT  */
    LT = 299,                      /* LT  */
    PLUS = 300,                    /* PLUS  */
    MINUS = 301,                   /* MINUS  */
    MULT = 302,                    /* MULT  */
    DIV = 303,                     /* DIV  */
    UMINUS = 304                   /* UMINUS  */
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
#define CLASS 264
#define CHAR_CONST 265
#define ASSIGN 266
#define AUX 267
#define END_OF_FILE 268
#define IN 269
#define SAGETICA 270
#define EVAL 271
#define FUNCTION 272
#define BGIN_FUNC 273
#define END_FUNC 274
#define BGIN_IF 275
#define END_IF 276
#define BGIN_ELSE 277
#define BGIN_MEMBRS 278
#define END_MEMBRS 279
#define BGIN_FUNCS 280
#define END_FUNCS 281
#define BGIN_CLASS 282
#define END_CLASS 283
#define BGIN_WHILE 284
#define END_WHILE 285
#define BGIN_FOR 286
#define END_FOR 287
#define IF 288
#define WHILE 289
#define FOR 290
#define NOT 291
#define AND 292
#define OR 293
#define GE 294
#define LE 295
#define EQ 296
#define NE 297
#define GT 298
#define LT 299
#define PLUS 300
#define MINUS 301
#define MULT 302
#define DIV 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "yapl.y"

    char* strval;
    char chrval;
    struct nodeType* nPtr;

#line 257 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_TIP = 4,                        /* TIP  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_INTREG = 6,                     /* INTREG  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_STRING_CONST = 8,               /* STRING_CONST  */
  YYSYMBOL_CLASS = 9,                      /* CLASS  */
  YYSYMBOL_CHAR_CONST = 10,                /* CHAR_CONST  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_AUX = 12,                       /* AUX  */
  YYSYMBOL_END_OF_FILE = 13,               /* END_OF_FILE  */
  YYSYMBOL_IN = 14,                        /* IN  */
  YYSYMBOL_SAGETICA = 15,                  /* SAGETICA  */
  YYSYMBOL_EVAL = 16,                      /* EVAL  */
  YYSYMBOL_FUNCTION = 17,                  /* FUNCTION  */
  YYSYMBOL_BGIN_FUNC = 18,                 /* BGIN_FUNC  */
  YYSYMBOL_END_FUNC = 19,                  /* END_FUNC  */
  YYSYMBOL_BGIN_IF = 20,                   /* BGIN_IF  */
  YYSYMBOL_END_IF = 21,                    /* END_IF  */
  YYSYMBOL_BGIN_ELSE = 22,                 /* BGIN_ELSE  */
  YYSYMBOL_BGIN_MEMBRS = 23,               /* BGIN_MEMBRS  */
  YYSYMBOL_END_MEMBRS = 24,                /* END_MEMBRS  */
  YYSYMBOL_BGIN_FUNCS = 25,                /* BGIN_FUNCS  */
  YYSYMBOL_END_FUNCS = 26,                 /* END_FUNCS  */
  YYSYMBOL_BGIN_CLASS = 27,                /* BGIN_CLASS  */
  YYSYMBOL_END_CLASS = 28,                 /* END_CLASS  */
  YYSYMBOL_BGIN_WHILE = 29,                /* BGIN_WHILE  */
  YYSYMBOL_END_WHILE = 30,                 /* END_WHILE  */
  YYSYMBOL_BGIN_FOR = 31,                  /* BGIN_FOR  */
  YYSYMBOL_END_FOR = 32,                   /* END_FOR  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_GE = 39,                        /* GE  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_NE = 42,                        /* NE  */
  YYSYMBOL_GT = 43,                        /* GT  */
  YYSYMBOL_LT = 44,                        /* LT  */
  YYSYMBOL_PLUS = 45,                      /* PLUS  */
  YYSYMBOL_MINUS = 46,                     /* MINUS  */
  YYSYMBOL_MULT = 47,                      /* MULT  */
  YYSYMBOL_DIV = 48,                       /* DIV  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_declaratii = 57,                /* declaratii  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_declaratie_clasa = 59,          /* declaratie_clasa  */
  YYSYMBOL_membrii_clasa = 60,             /* membrii_clasa  */
  YYSYMBOL_functii_clasa = 61,             /* functii_clasa  */
  YYSYMBOL_instructiune = 62,              /* instructiune  */
  YYSYMBOL_range_for = 63,                 /* range_for  */
  YYSYMBOL_bloc_for = 64,                  /* bloc_for  */
  YYSYMBOL_declaratie_functie = 65,        /* declaratie_functie  */
  YYSYMBOL_declaratie_tip_return = 66,     /* declaratie_tip_return  */
  YYSYMBOL_lista_parametrii = 67,          /* lista_parametrii  */
  YYSYMBOL_declaratie_parametru = 68,      /* declaratie_parametru  */
  YYSYMBOL_declaratie_tip_functie = 69,    /* declaratie_tip_functie  */
  YYSYMBOL_function_call = 70,             /* function_call  */
  YYSYMBOL_lista_parametrii_apel = 71,     /* lista_parametrii_apel  */
  YYSYMBOL_declaratie_variabila = 72,      /* declaratie_variabila  */
  YYSYMBOL_declaratie_ids = 73,            /* declaratie_ids  */
  YYSYMBOL_declaratie_tip = 74             /* declaratie_tip  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    66,    69,    70,    71,    74,    78,    79,
      80,    88,    98,    99,   100,   101,   102,   103,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   129,   131,   131,   133,   133,   136,   139,
     142,   143,   156,   166,   167,   169,   171,   174,   239,   252,
     253,   254,   255,   256,   257,   262,   263,   266,   269,   270,
     271,   272,   273,   274,   277,   281,   285,   291,   301,   304,
     312,   319,   325,   335,   336,   337,   338,   339,   340
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "TIP", "CONST",
  "INTREG", "REAL", "STRING_CONST", "CLASS", "CHAR_CONST", "ASSIGN", "AUX",
  "END_OF_FILE", "IN", "SAGETICA", "EVAL", "FUNCTION", "BGIN_FUNC",
  "END_FUNC", "BGIN_IF", "END_IF", "BGIN_ELSE", "BGIN_MEMBRS",
  "END_MEMBRS", "BGIN_FUNCS", "END_FUNCS", "BGIN_CLASS", "END_CLASS",
  "BGIN_WHILE", "END_WHILE", "BGIN_FOR", "END_FOR", "IF", "WHILE", "FOR",
  "NOT", "AND", "OR", "GE", "LE", "EQ", "NE", "GT", "LT", "PLUS", "MINUS",
  "MULT", "DIV", "UMINUS", "'['", "']'", "'('", "')'", "','", "$accept",
  "program", "declaratii", "expr", "declaratie_clasa", "membrii_clasa",
  "functii_clasa", "instructiune", "range_for", "bloc_for",
  "declaratie_functie", "declaratie_tip_return", "lista_parametrii",
  "declaratie_parametru", "declaratie_tip_functie", "function_call",
  "lista_parametrii_apel", "declaratie_variabila", "declaratie_ids",
  "declaratie_tip", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      91,    93,    40,    41,    44
};
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,     8,   -33,    18,    37,   -19,    40,    91,    91,    41,
      50,    38,    20,    20,    20,  -133,    20,    54,    91,    91,
      60,    55,  -133,    -1,    61,    91,    17,    22,  -133,  -133,
    -133,  -133,    91,    91,    91,   132,  -133,   152,    59,  -133,
    -133,  -133,  -133,  -133,  -133,    -6,  -133,   264,   234,  -133,
     164,    39,    44,    68,    94,  -133,   200,     6,    91,   264,
    -133,   217,    20,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    20,    52,    91,    54,   108,
      91,  -133,  -133,    30,    71,  -133,    73,   101,   111,   109,
     -45,  -133,   122,   249,  -133,   107,   274,   274,    63,    63,
      63,    63,    63,    63,   -20,   -20,  -133,  -133,    99,   124,
     102,   182,  -133,    91,  -133,   112,   110,    30,  -133,   126,
    -133,    85,   133,    84,   123,    98,  -133,  -133,  -133,  -133,
      86,    20,  -133,    54,   264,    89,   116,  -133,    93,   136,
    -133,    95,   142,   115,   130,    84,  -133,   143,   118,  -133,
     134,  -133,   103,   147,  -133,   105,   153,    20,   141,   113,
    -133,   135,   134,  -133,   114,   154,  -133,   144,    20,  -133,
     139,  -133,  -133,   131,  -133,   145,  -133,  -133,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     8,    43,     7,     0,     0,     0,
       0,     0,    74,    76,     0,     0,     0,    17,    13,    14,
      15,    16,     0,     0,     0,     0,    12,     0,     0,     1,
       2,     5,     6,     4,     3,    72,    68,    41,     0,    65,
      67,     0,     0,     0,     0,    77,     0,     0,     0,    32,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    75,     0,     0,    44,    58,     0,     0,     0,
       0,    56,     0,     0,    31,     0,    29,    30,    25,    26,
      27,    28,    24,    23,    19,    20,    21,    22,     0,     0,
       0,    71,    69,     0,    66,     0,     0,    35,    78,     0,
      59,    61,     0,     0,     0,     0,    57,    11,    38,    39,
       0,     0,    40,     0,    42,    76,     0,    34,     0,     0,
      62,    49,     0,     0,     0,     0,    55,     0,     0,    70,
       0,    60,     0,     0,    50,    52,     0,     0,     0,     0,
      46,     0,    37,    63,     0,     0,    53,     0,     0,    45,
       0,    36,    51,     0,    48,     0,    33,    54,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   -10,    13,  -133,    45,    21,  -133,  -133,  -133,
    -132,    42,  -133,    88,  -133,     0,   104,   -76,   -77,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    50,    12,   116,   161,    13,   110,   132,
      14,   144,    90,    91,    92,    36,    51,    16,    46,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,   112,    41,    42,    43,    77,    44,   117,   124,   125,
      86,    87,    15,    15,    15,    88,    15,    21,   162,    18,
      35,    37,    22,     1,     2,     3,    53,    73,    74,     4,
     162,    47,    48,    25,     2,     3,     5,     6,    56,   115,
      23,   117,    24,    26,    38,    59,    60,    61,    78,    54,
      39,    40,    95,     7,     8,     9,   149,    45,    19,    89,
      20,    52,    15,    27,    55,   108,    28,    29,    30,    57,
      31,    93,    58,    76,    20,    15,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   141,   142,
     111,    83,    81,   143,    27,    82,    32,    28,    29,    30,
      84,    31,    86,    87,   109,   120,    33,    88,    71,    72,
      73,    74,    34,    49,   121,   135,   122,    24,   155,   113,
     156,   148,   118,   119,   123,   126,   134,    32,   128,   129,
     130,    15,   138,   131,   136,   139,   140,    33,   145,    54,
     147,   150,   152,    34,   151,   153,   154,   167,   157,   159,
     160,     6,    62,   164,   163,   165,   166,    15,   175,   168,
     173,   170,   137,   174,   178,   172,   169,   176,    15,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   177,   171,   114,     0,     0,   158,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   146,     0,     0,     0,     0,    80,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,   133,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,     0,    85,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
      94,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    79,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
     127,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74
};

static const yytype_int16 yycheck[] =
{
       0,    78,    12,    13,    14,    11,    16,    83,    53,    54,
       4,     5,    12,    13,    14,     9,    16,    50,   150,    11,
       7,     8,     4,     3,     4,     5,    27,    47,    48,     9,
     162,    18,    19,    52,     4,     5,    16,    17,    25,     9,
       3,   117,     5,     3,     3,    32,    33,    34,    54,    50,
       0,    13,    62,    33,    34,    35,   133,     3,    50,    53,
      52,     6,    62,     3,     3,    75,     6,     7,     8,    52,
      10,    58,    50,    14,    52,    75,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     4,     5,
      77,    23,    53,     9,     3,    51,    36,     6,     7,     8,
       6,    10,     4,     5,    52,     4,    46,     9,    45,    46,
      47,    48,    52,    53,     3,     3,     5,     5,     3,    11,
       5,   131,    51,    50,    15,     3,   113,    36,    21,    30,
       6,   131,     6,    31,    24,    50,     3,    46,    15,    50,
      54,    25,     6,    52,    51,    50,     4,   157,    18,     6,
      32,    17,    20,     6,    51,    50,     3,   157,   168,    18,
       6,    26,   117,    19,    19,    51,    53,    28,   168,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    29,    51,   162,    80,    -1,    -1,   145,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   125,    -1,    -1,    -1,    -1,    54,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    54,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    51,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     9,    16,    17,    33,    34,    35,
      56,    57,    59,    62,    65,    70,    72,    74,    11,    50,
      52,    50,     4,     3,     5,    52,     3,     3,     6,     7,
       8,    10,    36,    46,    52,    58,    70,    58,     3,     0,
      13,    57,    57,    57,    57,     3,    73,    58,    58,    53,
      58,    71,     6,    27,    50,     3,    58,    52,    50,    58,
      58,    58,    20,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    29,    14,    11,    54,    51,
      54,    53,    51,    23,     6,    53,     4,     5,     9,    53,
      67,    68,    69,    58,    53,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    57,    52,
      63,    58,    73,    11,    71,     9,    60,    72,    51,    50,
       4,     3,     5,    15,    53,    54,     3,    51,    21,    30,
       6,    31,    64,    54,    58,     3,    24,    60,     6,    50,
       3,     4,     5,     9,    66,    15,    68,    54,    57,    73,
      25,    51,     6,    50,     4,     3,     5,    18,    66,     6,
      32,    61,    65,    51,     6,    50,     3,    57,    18,    53,
      26,    61,    51,     6,    19,    57,    28,    51,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    63,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,    10,     2,     1,     2,     1,     5,     5,
       5,     3,     6,     1,     4,     5,     3,    10,     9,     1,
       2,     4,     2,     3,     5,     3,     1,     2,     1,     2,
       4,     2,     3,     5,     4,     3,     3,     1,     2,     3,
       5,     3,     1,     1,     2,     4,     2,     3,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaratii END_OF_FILE  */
#line 60 "yapl.y"
                                  {
            if(shouldParse)
                parseSyntaxTree((yyvsp[-1].nPtr)) ;
            spuneCevaFrumos();
            }
#line 1453 "y.tab.c"
    break;

  case 3: /* declaratii: declaratie_variabila declaratii  */
#line 66 "yapl.y"
                                             {
                (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
                printf("declar o variabila\n");}
#line 1461 "y.tab.c"
    break;

  case 4: /* declaratii: declaratie_functie declaratii  */
#line 69 "yapl.y"
                                           {(yyval.nPtr) = (yyvsp[0].nPtr);printf("declar o functie\n");}
#line 1467 "y.tab.c"
    break;

  case 5: /* declaratii: declaratie_clasa declaratii  */
#line 70 "yapl.y"
                                         {(yyval.nPtr) = (yyvsp[0].nPtr);printf("declar o clasa\n");}
#line 1473 "y.tab.c"
    break;

  case 6: /* declaratii: instructiune declaratii  */
#line 71 "yapl.y"
                                     {
               (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
            }
#line 1481 "y.tab.c"
    break;

  case 7: /* declaratii: declaratie_variabila  */
#line 74 "yapl.y"
                                  {
               (yyval.nPtr) = (yyvsp[0].nPtr);
               symbolTable_popScope();
               }
#line 1490 "y.tab.c"
    break;

  case 8: /* declaratii: declaratie_functie  */
#line 78 "yapl.y"
                                {symbolTable_popScope();}
#line 1496 "y.tab.c"
    break;

  case 9: /* declaratii: declaratie_clasa  */
#line 79 "yapl.y"
                              {symbolTable_popScope();}
#line 1502 "y.tab.c"
    break;

  case 10: /* declaratii: instructiune  */
#line 80 "yapl.y"
                          {
               //struct nodeType * nod = $1;
               //printf("%d <<-- te rog\n", nod->type);
               symbolTable_popScope();
               (yyval.nPtr) = (yyvsp[0].nPtr);
            }
#line 1513 "y.tab.c"
    break;

  case 11: /* expr: ID '[' expr ']'  */
#line 88 "yapl.y"
                     {
            struct symbolTable_nod * p = symbolTable_Lookup((yyvsp[-3].strval));
            if(p == NULL)
            {
                handleError(NOT_DEFINED, (yyvsp[-3].strval));
            }
            struct nodeType * idNode = Node_IdNode(p, (yyvsp[-3].strval));
            struct nodeType *  accesNode = Node_OperatorNode(operatorACCESARRAY, 2 , idNode, (yyvsp[-1].nPtr));
            (yyval.nPtr) = accesNode;
        }
#line 1528 "y.tab.c"
    break;

  case 12: /* expr: function_call  */
#line 98 "yapl.y"
                     {;(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1534 "y.tab.c"
    break;

  case 13: /* expr: INTREG  */
#line 99 "yapl.y"
              {int value = atoi((yyvsp[0].strval)); (yyval.nPtr) = Node_ConstantInt(value);}
#line 1540 "y.tab.c"
    break;

  case 14: /* expr: REAL  */
#line 100 "yapl.y"
            {float value = atof((yyvsp[0].strval));printf("the valuea of float is %f\n and the string %s\n", value, (yyvsp[0].strval)); (yyval.nPtr) = Node_ConstantFloat(value);}
#line 1546 "y.tab.c"
    break;

  case 15: /* expr: STRING_CONST  */
#line 101 "yapl.y"
                    {(yyval.nPtr) = Node_ConstantString((yyvsp[0].strval));}
#line 1552 "y.tab.c"
    break;

  case 16: /* expr: CHAR_CONST  */
#line 102 "yapl.y"
                  {(yyval.nPtr) = Node_ConstantChar((yyvsp[0].chrval));}
#line 1558 "y.tab.c"
    break;

  case 17: /* expr: ID  */
#line 103 "yapl.y"
          {
         struct symbolTable_nod * p = symbolTable_Lookup((yyvsp[0].strval));
         if(p == NULL)
         {
             handleError(NOT_DEFINED, (yyvsp[0].strval));
         }
         (yyval.nPtr) = Node_IdNode(p, (yyvsp[0].strval));
         }
#line 1571 "y.tab.c"
    break;

  case 18: /* expr: MINUS expr  */
#line 111 "yapl.y"
                               {(yyval.nPtr) = Node_OperatorNode(operatorUMINUS, 1, (yyvsp[0].nPtr)); }
#line 1577 "y.tab.c"
    break;

  case 19: /* expr: expr PLUS expr  */
#line 112 "yapl.y"
                      {struct nodeType* n = Node_OperatorNode(operatorPLUS, 2, (yyvsp[-2].nPtr) , (yyvsp[0].nPtr));;(yyval.nPtr) = n;}
#line 1583 "y.tab.c"
    break;

  case 20: /* expr: expr MINUS expr  */
#line 113 "yapl.y"
                       {(yyval.nPtr) = Node_OperatorNode(operatorMINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1589 "y.tab.c"
    break;

  case 21: /* expr: expr MULT expr  */
#line 114 "yapl.y"
                      { (yyval.nPtr) = Node_OperatorNode(operatorMULT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1595 "y.tab.c"
    break;

  case 22: /* expr: expr DIV expr  */
#line 115 "yapl.y"
                     { (yyval.nPtr) = Node_OperatorNode(operatorDIV, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1601 "y.tab.c"
    break;

  case 23: /* expr: expr LT expr  */
#line 116 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorLT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1607 "y.tab.c"
    break;

  case 24: /* expr: expr GT expr  */
#line 117 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorGT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1613 "y.tab.c"
    break;

  case 25: /* expr: expr GE expr  */
#line 118 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1619 "y.tab.c"
    break;

  case 26: /* expr: expr LE expr  */
#line 119 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorLE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1625 "y.tab.c"
    break;

  case 27: /* expr: expr EQ expr  */
#line 120 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1631 "y.tab.c"
    break;

  case 28: /* expr: expr NE expr  */
#line 121 "yapl.y"
                    {(yyval.nPtr) = Node_OperatorNode(operatorNE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1637 "y.tab.c"
    break;

  case 29: /* expr: expr AND expr  */
#line 122 "yapl.y"
                     {(yyval.nPtr) = Node_OperatorNode(operatorAND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1643 "y.tab.c"
    break;

  case 30: /* expr: expr OR expr  */
#line 123 "yapl.y"
                    {(yyval.nPtr) = Node_OperatorNode(operatorOR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1649 "y.tab.c"
    break;

  case 31: /* expr: '(' expr ')'  */
#line 124 "yapl.y"
                    { (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1655 "y.tab.c"
    break;

  case 32: /* expr: NOT expr  */
#line 125 "yapl.y"
                {(yyval.nPtr) = Node_OperatorNode(operatorNOT, 1, (yyvsp[0].nPtr));}
#line 1661 "y.tab.c"
    break;

  case 33: /* declaratie_clasa: CLASS ID BGIN_CLASS BGIN_MEMBRS membrii_clasa END_MEMBRS BGIN_FUNCS functii_clasa END_FUNCS END_CLASS  */
#line 129 "yapl.y"
                                                                                                                           {symbolTable_popScope(); shouldParse = 0;}
#line 1667 "y.tab.c"
    break;

  case 38: /* instructiune: IF expr BGIN_IF declaratii END_IF  */
#line 136 "yapl.y"
                                                 {
                    (yyval.nPtr) = Node_OperatorNode(operatorIF, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                }
#line 1675 "y.tab.c"
    break;

  case 39: /* instructiune: WHILE expr BGIN_WHILE declaratii END_WHILE  */
#line 139 "yapl.y"
                                                          {
                    (yyval.nPtr) = Node_OperatorNode(operatorWHILE, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                }
#line 1683 "y.tab.c"
    break;

  case 40: /* instructiune: FOR ID IN range_for bloc_for  */
#line 142 "yapl.y"
                                            {}
#line 1689 "y.tab.c"
    break;

  case 41: /* instructiune: ID ASSIGN expr  */
#line 143 "yapl.y"
                              {
                 struct nodeType* node1 = (yyvsp[0].nPtr);
                struct symbolTable_nod * p = symbolTable_Lookup((yyvsp[-2].strval));
                if(p == NULL)
                {
                    handleError(NOT_DEFINED, (yyvsp[-2].strval));
                }
                 struct nodeType* node = Node_IdNode(p, (yyvsp[-2].strval));
                 printf("tipuuuul %d %d\n", node->type, typeId);
                 struct nodeType* node2 =  Node_OperatorNode(operatorASSIGN, 2, node, node1);
                 (yyval.nPtr) = node2;
                 //parseSyntaxTree($$);
               }
#line 1707 "y.tab.c"
    break;

  case 42: /* instructiune: ID '[' expr ']' ASSIGN expr  */
#line 156 "yapl.y"
                                        {
                    struct symbolTable_nod * p = symbolTable_Lookup((yyvsp[-5].strval));
                    if(p == NULL)
                    {
                        handleError(NOT_DEFINED, (yyvsp[-5].strval));
                    }
                    struct nodeType * idNode = Node_IdNode(p, (yyvsp[-5].strval));
                    struct nodeType *  accesNode = Node_OperatorNode(operatorACCESARRAY, 2 , idNode, (yyvsp[-3].nPtr));
                    (yyval.nPtr) = Node_OperatorNode(operatorASSIGN, 2 , accesNode, (yyvsp[0].nPtr));
                }
#line 1722 "y.tab.c"
    break;

  case 43: /* instructiune: function_call  */
#line 166 "yapl.y"
                             { ;(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1728 "y.tab.c"
    break;

  case 44: /* instructiune: EVAL '(' expr ')'  */
#line 167 "yapl.y"
                               {(yyval.nPtr) = Node_OperatorNode(operatorEVAL, 1, (yyvsp[-1].nPtr));}
#line 1734 "y.tab.c"
    break;

  case 47: /* declaratie_functie: FUNCTION ID '(' lista_parametrii ')' SAGETICA declaratie_tip_return BGIN_FUNC declaratii END_FUNC  */
#line 174 "yapl.y"
                                                                                                                    {
                        //printf("functie magica\n");
                        //printf("Pam %s si pam %s", $4, $8);
                        char s1[3000], s[3000];
                        //sprintf(s, "%s %s", $4, $8);
                        char copieMagica[3000];
                        strcpy(s1, (yyvsp[-3].strval));
                        strcpy(s, (yyvsp[-6].strval));
                        strcpy(copieMagica, s);
                        char aux[10000];
                        int scris = 0;
                        int lungime = strlen(s);
                        for(int i = 0 ; i < strlen(s); ++i)
                        {
                            if(s[i] == ' ') --lungime;
                        }
                        int auxLungime = 0;
                        char *p = strtok(s, " ");
                        while(p)
                        {
                            auxLungime += strlen(p);
                            if(p[strlen(p) - 1] == ',')
                            {
                                strcat(aux,",");
                            }
                            else
                            {
                                //printf("token:%s\n", p);
                                if(!scris){
                                    strcpy(aux, p);
                                    scris = 1;
                                }
                                else
                                {
                                    if(auxLungime != lungime)
                                        strcat(aux,p);
                                    
                                }
                                   

                            }
                            p = strtok(NULL, " ");
                        }
                        //strcpy(s, aux);
                       // printf("uite asta a iesit: %s\n", aux);
                        char copyOfAux[100];
                        strcpy(copyOfAux, aux);
                        strcat(aux, " -> ");
                        strcat(aux, s1);

                       // printf("Ce e in varf? %s\n", top->info);
                    
                        struct symbolTable_nod * nod = symbolTable_InsertMember(aux, (yyvsp[-8].strval));
                        char trueSignature[1000];
                        

                        sprintf(trueSignature, "%s(%s)", (yyvsp[-8].strval), copyOfAux);

                        AddFunction(trueSignature, nod, (yyvsp[-1].nPtr), yylineno);
                   
                        
                        //char type[300];
                        //sprintf(type, "function (%s) -> %s", $4, $8);
                        //symbolTable_InsertMember(type, $2);
                    }
#line 1804 "y.tab.c"
    break;

  case 48: /* declaratie_functie: FUNCTION ID '(' ')' SAGETICA declaratie_tip_return BGIN_FUNC declaratii END_FUNC  */
#line 239 "yapl.y"
                                                                                                     {
                        char aux[300];
                        char copie[100];
                        strcpy(copie, (yyvsp[-3].strval));
                        sprintf(aux, "void -> %s", copie);
                        struct symbolTable_nod * nod = symbolTable_InsertMember(aux, (yyvsp[-7].strval));
                        char trueSignature[1000];
                        sprintf(trueSignature, "%s(void)", (yyvsp[-7].strval));

                        AddFunction(trueSignature, nod, (yyvsp[-1].nPtr), yylineno);
                    }
#line 1820 "y.tab.c"
    break;

  case 49: /* declaratie_tip_return: TIP  */
#line 252 "yapl.y"
                            {(yyval.strval) = (yyvsp[0].strval);}
#line 1826 "y.tab.c"
    break;

  case 50: /* declaratie_tip_return: CONST TIP  */
#line 253 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1832 "y.tab.c"
    break;

  case 51: /* declaratie_tip_return: TIP '[' INTREG ']'  */
#line 254 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1838 "y.tab.c"
    break;

  case 55: /* lista_parametrii: lista_parametrii ',' declaratie_parametru  */
#line 262 "yapl.y"
                                                                {;char *s = (char*)malloc(1000); sprintf(s,"%s, %s",(yyvsp[-2].strval), (yyvsp[0].strval)); (yyval.strval) = s; stiva_push(&functionParameters, (yyvsp[-2].strval)); printf("magie uau %s\n", (yyvsp[0].strval));}
#line 1844 "y.tab.c"
    break;

  case 56: /* lista_parametrii: declaratie_parametru  */
#line 263 "yapl.y"
                                        {printf("varful scope %s\n",current->name);;strcpy((yyval.strval), (yyvsp[0].strval)); stiva_push(&functionParameters, (yyvsp[0].strval));}
#line 1850 "y.tab.c"
    break;

  case 57: /* declaratie_parametru: declaratie_tip_functie ID  */
#line 266 "yapl.y"
                                                 {char s[100]; sprintf(s,"%s %s", (yyvsp[-1].strval), (yyvsp[0].strval)); (yyval.strval) = s; }
#line 1856 "y.tab.c"
    break;

  case 58: /* declaratie_tip_functie: TIP  */
#line 269 "yapl.y"
                             {(yyval.strval) = (yyvsp[0].strval);}
#line 1862 "y.tab.c"
    break;

  case 59: /* declaratie_tip_functie: CONST TIP  */
#line 270 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1868 "y.tab.c"
    break;

  case 60: /* declaratie_tip_functie: TIP '[' INTREG ']'  */
#line 271 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1874 "y.tab.c"
    break;

  case 64: /* function_call: ID '(' lista_parametrii_apel ')'  */
#line 277 "yapl.y"
                                               {
                    printf("apelam o functie ieeeei\n");
                    (yyval.nPtr) = Node_FunctionCall((yyvsp[-3].strval), (yyvsp[-1].nPtr), yylineno);
                }
#line 1883 "y.tab.c"
    break;

  case 65: /* function_call: ID '(' ')'  */
#line 281 "yapl.y"
                          {
                    (yyval.nPtr) = Node_FunctionCall((yyvsp[-2].strval), NULL , yylineno);
              }
#line 1891 "y.tab.c"
    break;

  case 66: /* lista_parametrii_apel: expr ',' lista_parametrii_apel  */
#line 285 "yapl.y"
                                                       {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, (yyvsp[-2].nPtr));
                            (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, nodeAssign, (yyvsp[0].nPtr));

                        }
#line 1902 "y.tab.c"
    break;

  case 67: /* lista_parametrii_apel: expr  */
#line 291 "yapl.y"
                             {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, (yyvsp[0].nPtr));
                            (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, nodeAssign, NULL);
                          }
#line 1912 "y.tab.c"
    break;

  case 68: /* declaratie_variabila: declaratie_tip declaratie_ids  */
#line 301 "yapl.y"
                                                     {(yyval.nPtr)  = (yyvsp[0].nPtr);}
#line 1918 "y.tab.c"
    break;

  case 69: /* declaratie_ids: ID ',' declaratie_ids  */
#line 304 "yapl.y"
                                       {
                    if(strstr(currentTypeDeclared, "const") != NULL)
                    {
                        handleError(JUST_SAY_WHAT_I_SAY, "An constant value must be initialized!\n");
                    }
                    symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));
                    (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, NULL, (yyvsp[0].nPtr));
                }
#line 1931 "y.tab.c"
    break;

  case 70: /* declaratie_ids: ID ASSIGN expr ',' declaratie_ids  */
#line 312 "yapl.y"
                                                   {
                   symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-4].strval));
                   struct nodeType * idNode = Node_IdNode(current, (yyvsp[-4].strval));
                   struct nodeType * assignNode = Node_OperatorNode(operatorASSIGN, 2, idNode, (yyvsp[-2].nPtr));
                   (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, assignNode, (yyvsp[0].nPtr));
                   
                }
#line 1943 "y.tab.c"
    break;

  case 71: /* declaratie_ids: ID ASSIGN expr  */
#line 319 "yapl.y"
                                {
                   symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));
                   struct nodeType * idNode = Node_IdNode(current, (yyvsp[-2].strval));
                   struct nodeType * assignNode = Node_OperatorNode(operatorASSIGN, 2, idNode, (yyvsp[0].nPtr));
                   (yyval.nPtr) = assignNode;
                }
#line 1954 "y.tab.c"
    break;

  case 72: /* declaratie_ids: ID  */
#line 325 "yapl.y"
                    {
                    if(strstr(currentTypeDeclared, "const") != NULL)
                    {
                        handleError(JUST_SAY_WHAT_I_SAY, "An constant value must be initialized!\n");
                    }
                   symbolTable_InsertMember(currentTypeDeclared, (yyvsp[0].strval));

                   }
#line 1967 "y.tab.c"
    break;

  case 73: /* declaratie_tip: TIP  */
#line 335 "yapl.y"
                    {char * s= strdup((yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1973 "y.tab.c"
    break;

  case 74: /* declaratie_tip: CONST TIP  */
#line 336 "yapl.y"
                          {char s[100]; sprintf(s,"const %s",(yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1979 "y.tab.c"
    break;

  case 75: /* declaratie_tip: TIP '[' INTREG ']'  */
#line 337 "yapl.y"
                               {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); symbolTable_ChangeCurrentType(s);}
#line 1985 "y.tab.c"
    break;


#line 1989 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 342 "yapl.y"




void yyerror(char * s){
    symbolTable_Print("symbolTable.txt");
    printf("linia : %s\n", yytext);
    printf("eroare: %s la linia:%d\n",s,yylineno);
}
void PrintError(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}   


int main(int argc,  char** argv)
{
    if(argc < 2)
    {
        PrintError("Nu-i bini, trebuie macar un argument");       
    }
    yyin = fopen(argv[1], "r");
    EvalStack = stiva_createNode("");
    top = stiva_createNode("global");
    functionParameters = stiva_createNode("bottom");
    current = symbolTable_CreateNode();
    currentTypeDeclared = (char*)malloc(30);
    current->name = Scope_GetInfo();
    radacina = current;
    yyparse();
    symbolTable_Print("symbolTable.txt");
    EvalPrint(EvalStack);
}
