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

#line 100 "y.tab.c"

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

#line 254 "y.tab.c"

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
  YYSYMBOL_CHAR_CONST = 9,                 /* CHAR_CONST  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_AUX = 11,                       /* AUX  */
  YYSYMBOL_END_OF_FILE = 12,               /* END_OF_FILE  */
  YYSYMBOL_IN = 13,                        /* IN  */
  YYSYMBOL_SAGETICA = 14,                  /* SAGETICA  */
  YYSYMBOL_EVAL = 15,                      /* EVAL  */
  YYSYMBOL_FUNCTION = 16,                  /* FUNCTION  */
  YYSYMBOL_BGIN_FUNC = 17,                 /* BGIN_FUNC  */
  YYSYMBOL_END_FUNC = 18,                  /* END_FUNC  */
  YYSYMBOL_BGIN_IF = 19,                   /* BGIN_IF  */
  YYSYMBOL_END_IF = 20,                    /* END_IF  */
  YYSYMBOL_BGIN_ELSE = 21,                 /* BGIN_ELSE  */
  YYSYMBOL_BGIN_MEMBRS = 22,               /* BGIN_MEMBRS  */
  YYSYMBOL_END_MEMBRS = 23,                /* END_MEMBRS  */
  YYSYMBOL_BGIN_FUNCS = 24,                /* BGIN_FUNCS  */
  YYSYMBOL_END_FUNCS = 25,                 /* END_FUNCS  */
  YYSYMBOL_BGIN_CLASS = 26,                /* BGIN_CLASS  */
  YYSYMBOL_END_CLASS = 27,                 /* END_CLASS  */
  YYSYMBOL_CLASS = 28,                     /* CLASS  */
  YYSYMBOL_BGIN_WHILE = 29,                /* BGIN_WHILE  */
  YYSYMBOL_END_WHILE = 30,                 /* END_WHILE  */
  YYSYMBOL_BGIN_FOR = 31,                  /* BGIN_FOR  */
  YYSYMBOL_END_FOR = 32,                   /* END_FOR  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_EQ = 40,                        /* EQ  */
  YYSYMBOL_NE = 41,                        /* NE  */
  YYSYMBOL_GT = 42,                        /* GT  */
  YYSYMBOL_LT = 43,                        /* LT  */
  YYSYMBOL_PLUS = 44,                      /* PLUS  */
  YYSYMBOL_MINUS = 45,                     /* MINUS  */
  YYSYMBOL_MULT = 46,                      /* MULT  */
  YYSYMBOL_DIV = 47,                       /* DIV  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '-'  */
  YYSYMBOL_53_ = 53,                       /* '>'  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_declaratii = 58,                /* declaratii  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_declaratie_clasa = 60,          /* declaratie_clasa  */
  YYSYMBOL_membrii_clasa = 61,             /* membrii_clasa  */
  YYSYMBOL_functii_clasa = 62,             /* functii_clasa  */
  YYSYMBOL_instructiune = 63,              /* instructiune  */
  YYSYMBOL_range_for = 64,                 /* range_for  */
  YYSYMBOL_bloc_for = 65,                  /* bloc_for  */
  YYSYMBOL_declaratie_functie = 66,        /* declaratie_functie  */
  YYSYMBOL_declaratie_tip_return = 67,     /* declaratie_tip_return  */
  YYSYMBOL_lista_parametrii = 68,          /* lista_parametrii  */
  YYSYMBOL_declaratie_parametru = 69,      /* declaratie_parametru  */
  YYSYMBOL_declaratie_tip_functie = 70,    /* declaratie_tip_functie  */
  YYSYMBOL_function_call = 71,             /* function_call  */
  YYSYMBOL_lista_parametrii_apel = 72,     /* lista_parametrii_apel  */
  YYSYMBOL_declaratie_variabila = 73,      /* declaratie_variabila  */
  YYSYMBOL_declaratie_ids = 74,            /* declaratie_ids  */
  YYSYMBOL_CONSTANTA = 75,                 /* CONSTANTA  */
  YYSYMBOL_declaratie_tip = 76             /* declaratie_tip  */
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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      49,    50,     2,     2,    51,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    61,    64,    65,    66,    69,    70,    71,
      72,    80,    81,    82,    83,    84,    85,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   110,   112,   112,   114,   114,   117,   120,   123,   124,
     137,   138,   140,   142,   145,   210,   219,   220,   221,   222,
     223,   224,   229,   230,   233,   236,   237,   238,   239,   240,
     241,   244,   248,   265,   271,   281,   284,   285,   296,   321,
     322,   333,   336,   337,   338,   339,   342,   343,   344,   345,
     346,   347
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
  "INTREG", "REAL", "STRING_CONST", "CHAR_CONST", "ASSIGN", "AUX",
  "END_OF_FILE", "IN", "SAGETICA", "EVAL", "FUNCTION", "BGIN_FUNC",
  "END_FUNC", "BGIN_IF", "END_IF", "BGIN_ELSE", "BGIN_MEMBRS",
  "END_MEMBRS", "BGIN_FUNCS", "END_FUNCS", "BGIN_CLASS", "END_CLASS",
  "CLASS", "BGIN_WHILE", "END_WHILE", "BGIN_FOR", "END_FOR", "IF", "WHILE",
  "FOR", "AND", "OR", "GE", "LE", "EQ", "NE", "GT", "LT", "PLUS", "MINUS",
  "MULT", "DIV", "UMINUS", "'('", "')'", "','", "'-'", "'>'", "'['", "']'",
  "$accept", "program", "declaratii", "expr", "declaratie_clasa",
  "membrii_clasa", "functii_clasa", "instructiune", "range_for",
  "bloc_for", "declaratie_functie", "declaratie_tip_return",
  "lista_parametrii", "declaratie_parametru", "declaratie_tip_functie",
  "function_call", "lista_parametrii_apel", "declaratie_variabila",
  "declaratie_ids", "CONSTANTA", "declaratie_tip", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    40,
      41,    44,    45,    62,    91,    93
};
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,    -4,   -39,    17,    -5,    27,    26,    46,    46,    48,
      86,    50,    85,    85,    85,  -143,    85,    84,    46,    19,
     109,  -143,    46,    76,   -19,   123,    78,  -143,  -143,  -143,
    -143,    46,    46,    93,  -143,   124,   128,  -143,  -143,  -143,
    -143,  -143,  -143,    -1,  -143,   182,  -143,   136,    92,    88,
     152,    13,   122,   139,  -143,  -143,   167,    85,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      85,    97,    90,    84,    46,  -143,  -143,  -143,    95,   146,
      62,    99,   -40,  -143,   149,    28,   100,  -143,   134,    64,
      64,    77,    77,    77,    77,    77,    77,    -7,    -7,  -143,
    -143,   126,   151,   153,    22,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,   179,  -143,   132,   197,   148,   201,    32,
    -143,    89,   193,    28,  -143,  -143,  -143,   180,    85,  -143,
      84,   175,   226,  -143,    38,    38,  -143,   181,   209,  -143,
     228,   204,  -143,  -143,   183,   185,   233,   111,   223,   224,
     227,   192,  -143,  -143,   238,  -143,   191,   243,    85,    85,
     222,   227,  -143,   194,   242,  -143,   232,   234,   229,  -143,
    -143,   196,  -143,  -143,  -143,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     8,    40,     7,     0,     0,     0,
       0,    77,     0,     0,    79,     0,    16,    12,    13,    14,
      15,     0,     0,     0,    11,     0,     0,     1,     2,     5,
       6,     4,     3,    69,    65,    39,    62,    64,     0,     0,
       0,     0,     0,     0,    80,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    78,    41,    55,     0,
       0,     0,     0,    53,     0,     0,     0,    30,     0,    28,
      29,    24,    25,    26,    27,    23,    22,    18,    19,    20,
      21,     0,     0,     0,    70,    72,    73,    74,    75,    68,
      71,    66,    63,     0,    56,    58,     0,     0,     0,     0,
      54,     0,     0,    33,    81,    36,    37,     0,     0,    38,
       0,     0,     0,    59,     0,     0,    52,    79,     0,    32,
       0,     0,    67,    57,     0,    46,     0,     0,     0,     0,
       0,     0,    43,    60,     0,    47,    49,     0,     0,     0,
       0,    35,    42,     0,     0,    50,     0,     0,     0,    34,
      48,     0,    45,    44,    31,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   -11,    16,  -143,   130,    94,  -143,  -143,  -143,
    -142,   119,  -143,   138,  -143,     0,   184,   -65,   -69,  -143,
    -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    47,    12,   122,   160,    13,   103,   129,
      14,   148,    82,    83,    84,    34,    48,    16,    44,   110,
      17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    39,    40,    41,   111,    42,    18,    52,   161,    72,
     118,   119,    15,    15,    15,    20,    15,    78,    79,   161,
     123,    21,    26,    33,    35,    27,    28,    29,    30,    24,
      23,    25,     2,     3,    45,    53,    78,    79,    50,    68,
      69,    80,   145,   146,    22,    19,    88,    55,    56,    26,
      73,    36,    27,    28,    29,    30,   121,    15,   123,   101,
      80,   142,    38,    81,    31,   115,   147,   116,    32,    46,
      15,    19,   109,   130,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    37,    43,     1,     2,
       3,    31,   137,   104,    25,    32,   105,   106,   107,   108,
       4,     5,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    57,     6,   156,    49,   157,   141,     7,     8,
       9,    66,    67,    68,    69,    51,    54,    19,    15,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    71,    75,    76,    85,    86,   102,   166,   167,   113,
     114,   117,   120,    70,   125,   124,   126,   127,    15,    15,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   128,   131,   132,    74,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     133,   134,    77,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   135,   138,    87,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     143,   140,   144,   150,   151,    53,   152,   155,   153,   154,
     158,   159,   162,     5,   163,   164,   165,   168,   171,   170,
     172,   175,   173,   139,   149,   169,   174,   136,   112
};

static const yytype_uint8 yycheck[] =
{
       0,    12,    13,    14,    73,    16,    10,    26,   150,    10,
      50,    51,    12,    13,    14,    54,    16,     4,     5,   161,
      85,     4,     3,     7,     8,     6,     7,     8,     9,     3,
       3,     5,     4,     5,    18,    54,     4,     5,    22,    46,
      47,    28,     4,     5,    49,    49,    57,    31,    32,     3,
      51,     3,     6,     7,     8,     9,    28,    57,   123,    70,
      28,   130,    12,    50,    45,     3,    28,     5,    49,    50,
      70,    49,    72,    51,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     3,     3,     4,
       5,    45,     3,     3,     5,    49,     6,     7,     8,     9,
      15,    16,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    19,    28,     3,     6,     5,   128,    33,    34,
      35,    44,    45,    46,    47,    49,     3,    49,   128,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    13,    50,    55,    22,     6,    49,   158,   159,    54,
       4,    52,     3,    29,    20,    55,    30,     6,   158,   159,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    31,     6,    54,    51,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,    53,    50,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    14,    23,    50,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      55,    51,     6,    24,     6,    54,    32,     4,    55,    54,
      17,    17,    50,    16,     6,    54,     3,    25,     6,    55,
      18,    55,    18,   123,   135,   161,    27,   119,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    15,    16,    28,    33,    34,    35,
      57,    58,    60,    63,    66,    71,    73,    76,    10,    49,
      54,     4,    49,     3,     3,     5,     3,     6,     7,     8,
       9,    45,    49,    59,    71,    59,     3,     0,    12,    58,
      58,    58,    58,     3,    74,    59,    50,    59,    72,     6,
      59,    49,    26,    54,     3,    59,    59,    19,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      29,    13,    10,    51,    51,    50,    55,    50,     4,     5,
      28,    50,    68,    69,    70,    22,     6,    50,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    58,    49,    64,     3,     6,     7,     8,     9,    71,
      75,    74,    72,    54,     4,     3,     5,    52,    50,    51,
       3,    28,    61,    73,    55,    20,    30,     6,    31,    65,
      51,     6,    54,     3,    53,    14,    69,     3,    23,    61,
      51,    58,    74,    55,     6,     4,     5,    28,    67,    67,
      24,     6,    32,    55,    54,     4,     3,     5,    17,    17,
      62,    66,    50,     6,    54,     3,    58,    58,    25,    62,
      55,     6,    18,    18,    27,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,    10,     2,     1,     2,     1,     5,     5,     5,     3,
       1,     4,     5,     3,    10,    10,     1,     2,     4,     2,
       3,     5,     3,     1,     2,     1,     2,     4,     2,     3,
       5,     4,     3,     3,     1,     2,     3,     5,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     2,     4,     2,
       3,     5
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
#line 59 "yapl.y"
                                  {parseSyntaxTree((yyvsp[-1].nPtr)) ;spuneCevaFrumos();}
#line 1439 "y.tab.c"
    break;

  case 3: /* declaratii: declaratie_variabila declaratii  */
#line 61 "yapl.y"
                                             {
                (yyval.nPtr) = (yyvsp[0].nPtr);
                printf("declar o variabila\n");}
#line 1447 "y.tab.c"
    break;

  case 4: /* declaratii: declaratie_functie declaratii  */
#line 64 "yapl.y"
                                           {(yyval.nPtr) = (yyvsp[0].nPtr);printf("declar o functie\n");}
#line 1453 "y.tab.c"
    break;

  case 5: /* declaratii: declaratie_clasa declaratii  */
#line 65 "yapl.y"
                                         {printf("declar o clasa\n");}
#line 1459 "y.tab.c"
    break;

  case 6: /* declaratii: instructiune declaratii  */
#line 66 "yapl.y"
                                     {
               (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
            }
#line 1467 "y.tab.c"
    break;

  case 7: /* declaratii: declaratie_variabila  */
#line 69 "yapl.y"
                                  {symbolTable_popScope();}
#line 1473 "y.tab.c"
    break;

  case 8: /* declaratii: declaratie_functie  */
#line 70 "yapl.y"
                                {symbolTable_popScope();}
#line 1479 "y.tab.c"
    break;

  case 9: /* declaratii: declaratie_clasa  */
#line 71 "yapl.y"
                              {symbolTable_popScope();}
#line 1485 "y.tab.c"
    break;

  case 10: /* declaratii: instructiune  */
#line 72 "yapl.y"
                          {
               //struct nodeType * nod = $1;
               //printf("%d <<-- te rog\n", nod->type);
               symbolTable_popScope();
               (yyval.nPtr) = (yyvsp[0].nPtr);
            }
#line 1496 "y.tab.c"
    break;

  case 11: /* expr: function_call  */
#line 80 "yapl.y"
                     { printf("crapa aici");(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1502 "y.tab.c"
    break;

  case 12: /* expr: INTREG  */
#line 81 "yapl.y"
              {int value = atoi((yyvsp[0].strval)); (yyval.nPtr) = Node_ConstantInt(value);}
#line 1508 "y.tab.c"
    break;

  case 13: /* expr: REAL  */
#line 82 "yapl.y"
            {float value = atof((yyvsp[0].strval));printf("the valuea of float is %f\n and the string %s\n", value, (yyvsp[0].strval)); (yyval.nPtr) = Node_ConstantFloat(value);}
#line 1514 "y.tab.c"
    break;

  case 14: /* expr: STRING_CONST  */
#line 83 "yapl.y"
                    {(yyval.nPtr) = Node_ConstantString((yyvsp[0].strval));}
#line 1520 "y.tab.c"
    break;

  case 15: /* expr: CHAR_CONST  */
#line 84 "yapl.y"
                  {(yyval.nPtr) = Node_ConstantString((yyvsp[0].chrval));}
#line 1526 "y.tab.c"
    break;

  case 16: /* expr: ID  */
#line 85 "yapl.y"
          {
         struct symbolTable_nod * p = symbolTable_Lookup((yyvsp[0].strval));
         if(p == NULL)
         {
             handleError(NOT_DEFINED, (yyvsp[0].strval));
         }
         (yyval.nPtr) = Node_IdNode(p, (yyvsp[0].strval));
         }
#line 1539 "y.tab.c"
    break;

  case 17: /* expr: MINUS expr  */
#line 93 "yapl.y"
                               {(yyval.nPtr) = Node_OperatorNode(operatorUMINUS, 1, (yyvsp[0].nPtr)); }
#line 1545 "y.tab.c"
    break;

  case 18: /* expr: expr PLUS expr  */
#line 94 "yapl.y"
                      {struct nodeType* n = Node_OperatorNode(operatorPLUS, 2, (yyvsp[-2].nPtr) , (yyvsp[0].nPtr));;(yyval.nPtr) = n;}
#line 1551 "y.tab.c"
    break;

  case 19: /* expr: expr MINUS expr  */
#line 95 "yapl.y"
                       {(yyval.nPtr) = Node_OperatorNode(operatorMINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1557 "y.tab.c"
    break;

  case 20: /* expr: expr MULT expr  */
#line 96 "yapl.y"
                      { (yyval.nPtr) = Node_OperatorNode(operatorMULT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1563 "y.tab.c"
    break;

  case 21: /* expr: expr DIV expr  */
#line 97 "yapl.y"
                     { (yyval.nPtr) = Node_OperatorNode(operatorDIV, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1569 "y.tab.c"
    break;

  case 22: /* expr: expr LT expr  */
#line 98 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorLT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1575 "y.tab.c"
    break;

  case 23: /* expr: expr GT expr  */
#line 99 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorGT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1581 "y.tab.c"
    break;

  case 24: /* expr: expr GE expr  */
#line 100 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1587 "y.tab.c"
    break;

  case 25: /* expr: expr LE expr  */
#line 101 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorLE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1593 "y.tab.c"
    break;

  case 26: /* expr: expr EQ expr  */
#line 102 "yapl.y"
                    { (yyval.nPtr) = Node_OperatorNode(operatorEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1599 "y.tab.c"
    break;

  case 27: /* expr: expr NE expr  */
#line 103 "yapl.y"
                    {(yyval.nPtr) = Node_OperatorNode(operatorNE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1605 "y.tab.c"
    break;

  case 28: /* expr: expr AND expr  */
#line 104 "yapl.y"
                     {(yyval.nPtr) = Node_OperatorNode(operatorAND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1611 "y.tab.c"
    break;

  case 29: /* expr: expr OR expr  */
#line 105 "yapl.y"
                    {(yyval.nPtr) = Node_OperatorNode(operatorOR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1617 "y.tab.c"
    break;

  case 30: /* expr: '(' expr ')'  */
#line 106 "yapl.y"
                    { (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1623 "y.tab.c"
    break;

  case 31: /* declaratie_clasa: CLASS ID BGIN_CLASS BGIN_MEMBRS membrii_clasa END_MEMBRS BGIN_FUNCS functii_clasa END_FUNCS END_CLASS  */
#line 110 "yapl.y"
                                                                                                                           {symbolTable_popScope();}
#line 1629 "y.tab.c"
    break;

  case 36: /* instructiune: IF expr BGIN_IF declaratii END_IF  */
#line 117 "yapl.y"
                                                 {
                    (yyval.nPtr) = Node_OperatorNode(operatorIF, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                }
#line 1637 "y.tab.c"
    break;

  case 37: /* instructiune: WHILE expr BGIN_WHILE declaratii END_WHILE  */
#line 120 "yapl.y"
                                                          {
                    (yyval.nPtr) = Node_OperatorNode(operatorWHILE, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                }
#line 1645 "y.tab.c"
    break;

  case 38: /* instructiune: FOR ID IN range_for bloc_for  */
#line 123 "yapl.y"
                                            {}
#line 1651 "y.tab.c"
    break;

  case 39: /* instructiune: ID ASSIGN expr  */
#line 124 "yapl.y"
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
#line 1669 "y.tab.c"
    break;

  case 40: /* instructiune: function_call  */
#line 137 "yapl.y"
                             { ;(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1675 "y.tab.c"
    break;

  case 41: /* instructiune: EVAL '(' expr ')'  */
#line 138 "yapl.y"
                               {(yyval.nPtr) = Node_OperatorNode(operatorEVAL, 1, (yyvsp[-1].nPtr));}
#line 1681 "y.tab.c"
    break;

  case 44: /* declaratie_functie: FUNCTION ID '(' lista_parametrii ')' SAGETICA declaratie_tip_return BGIN_FUNC declaratii END_FUNC  */
#line 145 "yapl.y"
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
#line 1751 "y.tab.c"
    break;

  case 45: /* declaratie_functie: FUNCTION ID '(' ')' '-' '>' declaratie_tip_return BGIN_FUNC declaratii END_FUNC  */
#line 210 "yapl.y"
                                                                                                   {
                        char aux[300];
                        char copie[100];
                        strcpy(copie, (yyvsp[-3].strval));
                        sprintf(aux, "void -> %s", copie);
                        symbolTable_InsertMember(aux, (yyvsp[-8].strval));
                    }
#line 1763 "y.tab.c"
    break;

  case 46: /* declaratie_tip_return: TIP  */
#line 219 "yapl.y"
                            {(yyval.strval) = (yyvsp[0].strval);}
#line 1769 "y.tab.c"
    break;

  case 47: /* declaratie_tip_return: CONST TIP  */
#line 220 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1775 "y.tab.c"
    break;

  case 48: /* declaratie_tip_return: TIP '[' INTREG ']'  */
#line 221 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1781 "y.tab.c"
    break;

  case 52: /* lista_parametrii: lista_parametrii ',' declaratie_parametru  */
#line 229 "yapl.y"
                                                                {;char *s = (char*)malloc(1000); sprintf(s,"%s, %s",(yyvsp[-2].strval), (yyvsp[0].strval)); (yyval.strval) = s; stiva_push(&functionParameters, (yyvsp[-2].strval)); printf("magie uau %s\n", (yyvsp[0].strval));}
#line 1787 "y.tab.c"
    break;

  case 53: /* lista_parametrii: declaratie_parametru  */
#line 230 "yapl.y"
                                        {printf("varful scope %s\n",current->name);;strcpy((yyval.strval), (yyvsp[0].strval)); stiva_push(&functionParameters, (yyvsp[0].strval));}
#line 1793 "y.tab.c"
    break;

  case 54: /* declaratie_parametru: declaratie_tip_functie ID  */
#line 233 "yapl.y"
                                                 {char s[100]; sprintf(s,"%s %s", (yyvsp[-1].strval), (yyvsp[0].strval)); (yyval.strval) = s; }
#line 1799 "y.tab.c"
    break;

  case 55: /* declaratie_tip_functie: TIP  */
#line 236 "yapl.y"
                             {(yyval.strval) = (yyvsp[0].strval);}
#line 1805 "y.tab.c"
    break;

  case 56: /* declaratie_tip_functie: CONST TIP  */
#line 237 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1811 "y.tab.c"
    break;

  case 57: /* declaratie_tip_functie: TIP '[' INTREG ']'  */
#line 238 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1817 "y.tab.c"
    break;

  case 61: /* function_call: ID '(' lista_parametrii_apel ')'  */
#line 244 "yapl.y"
                                               {
                    printf("apelam o functie ieeeei\n");
                    (yyval.nPtr) = Node_FunctionCall((yyvsp[-3].strval), (yyvsp[-1].nPtr), yylineno);
                }
#line 1826 "y.tab.c"
    break;

  case 62: /* function_call: ID '(' ')'  */
#line 248 "yapl.y"
                          {
                    char signature[100];
                    char id[100];
                    strcpy(signature,"void");
                    strcpy(id, (yyvsp[-2].strval));
                    if(symbolTable_Function_GetTypeOfMember(signature, id))
                    {
                        printf("Functia exista iei\n");
                    }
                    else
                    {
                        char eroare[100];
                        sprintf(eroare, "%s(%s)", id, signature);
                        handleError(NOT_DEFINED, eroare);
                    }
              }
#line 1847 "y.tab.c"
    break;

  case 63: /* lista_parametrii_apel: expr ',' lista_parametrii_apel  */
#line 265 "yapl.y"
                                                       {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, (yyvsp[-2].nPtr));
                            (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, nodeAssign, (yyvsp[0].nPtr));

                        }
#line 1858 "y.tab.c"
    break;

  case 64: /* lista_parametrii_apel: expr  */
#line 271 "yapl.y"
                             {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, (yyvsp[0].nPtr));
                            (yyval.nPtr) = Node_OperatorNode(operatorSTAT, 2, nodeAssign, NULL);
                          }
#line 1868 "y.tab.c"
    break;

  case 66: /* declaratie_ids: ID ',' declaratie_ids  */
#line 284 "yapl.y"
                                       {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));}
#line 1874 "y.tab.c"
    break;

  case 67: /* declaratie_ids: ID ASSIGN ID ',' declaratie_ids  */
#line 285 "yapl.y"
                                                 {
                   symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-4].strval));
                    if(!symbolTable_Lookup((yyvsp[-2].strval)))
                    {
                        handleError(NOT_DEFINED, (yyvsp[-2].strval));
                    }
                    if(strcmp(symbolTable_GetTypeOfMember((yyvsp[-4].strval)), symbolTable_GetTypeOfMember((yyvsp[-2].strval))) != 0)
                    {
                        handleError(NOT_THE_SAME_TYPE, "?");
                    }
                }
#line 1890 "y.tab.c"
    break;

  case 68: /* declaratie_ids: ID ASSIGN function_call  */
#line 296 "yapl.y"
                                         {
                    symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));
                    char functiaMagica[100];
                    strcpy(functiaMagica, (yyvsp[0].nPtr));
                    char signature[100];
                    char id[100];
                    char *p = strtok(functiaMagica, " ");
                    strcpy(id, p);
                    p = strtok(NULL, " ");
                    strcpy(signature, p);
                    if(!symbolTable_Function_Lookup(signature, id))
                    {
                        handleError(NOT_DEFINED, (yyvsp[0].nPtr));
                    }
                    char tipul1[100], tipul2[100];
                    strcpy(tipul1, symbolTable_GetTypeOfMember((yyvsp[-2].strval)));
                    strcpy(tipul2, symbolTable_Function_GetTypeOfMember(signature, id));
                    //printf("%s\n%s\n", tipul1, tipul2);
                    int comp = strcmp(tipul1 , tipul2);
                    //printf("rezultatul comparatiei : %d\n", comp);
                    if(comp != 0)
                    {
                        handleError(NOT_THE_SAME_TYPE, "?");
                    }
                }
#line 1920 "y.tab.c"
    break;

  case 69: /* declaratie_ids: ID  */
#line 321 "yapl.y"
                    {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[0].strval));}
#line 1926 "y.tab.c"
    break;

  case 70: /* declaratie_ids: ID ASSIGN ID  */
#line 322 "yapl.y"
                              {
                   symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));
                      if(!symbolTable_Lookup((yyvsp[0].strval)))
                    {
                        handleError(NOT_DEFINED, (yyvsp[0].strval));
                    }
                    if(strcmp(symbolTable_GetTypeOfMember((yyvsp[-2].strval)),symbolTable_GetTypeOfMember((yyvsp[0].strval))) != 0)
                    {
                        handleError(NOT_THE_SAME_TYPE, "?");
                    }
                   }
#line 1942 "y.tab.c"
    break;

  case 71: /* declaratie_ids: ID ASSIGN CONSTANTA  */
#line 333 "yapl.y"
                                     {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));}
#line 1948 "y.tab.c"
    break;

  case 73: /* CONSTANTA: REAL  */
#line 337 "yapl.y"
                 {printf("uuuf\n");}
#line 1954 "y.tab.c"
    break;

  case 76: /* declaratie_tip: TIP  */
#line 342 "yapl.y"
                    {char * s= strdup((yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1960 "y.tab.c"
    break;

  case 77: /* declaratie_tip: CONST TIP  */
#line 343 "yapl.y"
                          {char s[100]; sprintf(s,"const %s",(yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1966 "y.tab.c"
    break;

  case 78: /* declaratie_tip: TIP '[' INTREG ']'  */
#line 344 "yapl.y"
                               {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); symbolTable_ChangeCurrentType(s);}
#line 1972 "y.tab.c"
    break;


#line 1976 "y.tab.c"

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

#line 349 "yapl.y"




void yyerror(char * s){
    symbolTable_Print("symbolTable.txt");
    printf("linia : %s\n", yytext);
    printf("eroare: %s la linia:%d\n",s,yylineno);
}
void PrintError(const char *message)
{
    char redMessage[strlen(message) + 15];
    sprintf(redMessage, "%s%s%s\n", RED, message, RESET);
    printf(redMessage);
    fflush(stdout);
}   


int main(int argc,  char** argv)
{
    
    printf("pana acuma e oki doki\n");
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
