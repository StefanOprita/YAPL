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
    #include "hashTable.h"
    #include "stiva.h"
    #include "scope.h"
    #include "symbolTable.h"


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

#line 96 "y.tab.c"

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

#line 218 "y.tab.c"

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
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_AUX = 8,                        /* AUX  */
  YYSYMBOL_END_OF_FILE = 9,                /* END_OF_FILE  */
  YYSYMBOL_IN = 10,                        /* IN  */
  YYSYMBOL_REAL = 11,                      /* REAL  */
  YYSYMBOL_STRING_CONST = 12,              /* STRING_CONST  */
  YYSYMBOL_CHAR_CONST = 13,                /* CHAR_CONST  */
  YYSYMBOL_FUNCTION = 14,                  /* FUNCTION  */
  YYSYMBOL_BGIN_FUNC = 15,                 /* BGIN_FUNC  */
  YYSYMBOL_END_FUNC = 16,                  /* END_FUNC  */
  YYSYMBOL_BGIN_IF = 17,                   /* BGIN_IF  */
  YYSYMBOL_END_IF = 18,                    /* END_IF  */
  YYSYMBOL_BGIN_ELSE = 19,                 /* BGIN_ELSE  */
  YYSYMBOL_BGIN_MEMBRS = 20,               /* BGIN_MEMBRS  */
  YYSYMBOL_END_MEMBRS = 21,                /* END_MEMBRS  */
  YYSYMBOL_BGIN_FUNCS = 22,                /* BGIN_FUNCS  */
  YYSYMBOL_END_FUNCS = 23,                 /* END_FUNCS  */
  YYSYMBOL_BGIN_CLASS = 24,                /* BGIN_CLASS  */
  YYSYMBOL_END_CLASS = 25,                 /* END_CLASS  */
  YYSYMBOL_CLASS = 26,                     /* CLASS  */
  YYSYMBOL_BGIN_WHILE = 27,                /* BGIN_WHILE  */
  YYSYMBOL_END_WHILE = 28,                 /* END_WHILE  */
  YYSYMBOL_BGIN_FOR = 29,                  /* BGIN_FOR  */
  YYSYMBOL_END_FOR = 30,                   /* END_FOR  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_34_ = 34,                       /* '@'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_declaratii = 44,                /* declaratii  */
  YYSYMBOL_declaratie_clasa = 45,          /* declaratie_clasa  */
  YYSYMBOL_membrii_clasa = 46,             /* membrii_clasa  */
  YYSYMBOL_functii_clasa = 47,             /* functii_clasa  */
  YYSYMBOL_instructiune = 48,              /* instructiune  */
  YYSYMBOL_conditie_logica = 49,           /* conditie_logica  */
  YYSYMBOL_bloc_if = 50,                   /* bloc_if  */
  YYSYMBOL_bloc_while = 51,                /* bloc_while  */
  YYSYMBOL_range_for = 52,                 /* range_for  */
  YYSYMBOL_bloc_for = 53,                  /* bloc_for  */
  YYSYMBOL_declaratie_functie = 54,        /* declaratie_functie  */
  YYSYMBOL_declaratie_tip_return = 55,     /* declaratie_tip_return  */
  YYSYMBOL_bloc_functie = 56,              /* bloc_functie  */
  YYSYMBOL_lista_parametrii = 57,          /* lista_parametrii  */
  YYSYMBOL_declaratie_parametru = 58,      /* declaratie_parametru  */
  YYSYMBOL_declaratie_tip_functie = 59,    /* declaratie_tip_functie  */
  YYSYMBOL_declaratie_variabila = 60,      /* declaratie_variabila  */
  YYSYMBOL_declaratie_ids = 61,            /* declaratie_ids  */
  YYSYMBOL_CONSTANTA = 62,                 /* CONSTANTA  */
  YYSYMBOL_declaratie_tip = 63             /* declaratie_tip  */
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      35,    37,     2,     2,    36,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    39,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    44,    45,    46,    47,    48,    49,    50,
      51,    54,    56,    56,    58,    58,    61,    62,    63,    64,
      66,    68,    69,    71,    73,    75,    78,   135,   138,   139,
     140,   141,   142,   143,   146,   148,   149,   152,   155,   156,
     157,   158,   159,   160,   165,   167,   168,   169,   170,   171,
     174,   175,   176,   177,   180,   181,   182,   183,   184,   185
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
  "INTREG", "ASSIGN", "AUX", "END_OF_FILE", "IN", "REAL", "STRING_CONST",
  "CHAR_CONST", "FUNCTION", "BGIN_FUNC", "END_FUNC", "BGIN_IF", "END_IF",
  "BGIN_ELSE", "BGIN_MEMBRS", "END_MEMBRS", "BGIN_FUNCS", "END_FUNCS",
  "BGIN_CLASS", "END_CLASS", "CLASS", "BGIN_WHILE", "END_WHILE",
  "BGIN_FOR", "END_FOR", "IF", "WHILE", "FOR", "'@'", "'('", "','", "')'",
  "'-'", "'>'", "'['", "']'", "$accept", "program", "declaratii",
  "declaratie_clasa", "membrii_clasa", "functii_clasa", "instructiune",
  "conditie_logica", "bloc_if", "bloc_while", "range_for", "bloc_for",
  "declaratie_functie", "declaratie_tip_return", "bloc_functie",
  "lista_parametrii", "declaratie_parametru", "declaratie_tip_functie",
  "declaratie_variabila", "declaratie_ids", "CONSTANTA", "declaratie_tip", YY_NULLPTR
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
     285,   286,   287,   288,    64,    40,    44,    41,    45,    62,
      91,    93
};
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,    18,     7,    49,    54,    11,    24,    24,    56,    60,
      52,     4,     4,     4,     4,    59,    61,    57,   -95,    30,
     -12,    63,   -95,    50,    41,    62,   -95,   -95,   -95,   -95,
     -95,   -95,     3,   -95,   -95,    28,     1,    51,    68,   -95,
       4,   -95,     4,   -95,    40,    43,    59,   -95,    36,    73,
      12,    42,    -4,   -95,    75,    15,    38,    33,    53,    76,
      55,    47,   -95,   -95,   -95,   -95,   -95,   -95,    79,   -95,
      46,    84,    58,    17,    64,   -95,    37,    67,    15,   -95,
     -95,     4,   -95,    65,     4,   -95,    59,    48,    85,   -95,
      19,    70,    69,    71,    72,   -95,    74,    87,    66,   -95,
     -95,    77,    80,    86,    45,    83,    19,    81,   -95,    78,
     -95,   -95,    93,   -95,    82,    97,     4,   -95,    83,    89,
      81,   -95,    88,    98,   -95,    91,   -95,    92,   -95,   -95,
      90,   -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     8,     7,     0,     0,     0,    55,     0,
      57,     0,    20,     0,     0,     0,     1,     2,     5,     6,
       4,     3,    47,    44,    19,     0,     0,     0,     0,    58,
       0,    16,     0,    17,     0,     0,     0,    56,    38,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    48,    50,    51,    52,    53,    49,    45,     0,    39,
      41,     0,     0,     0,     0,    37,     0,     0,    13,    59,
      21,     0,    23,     0,     0,    18,     0,     0,     0,    42,
       0,    35,     0,    57,     0,    12,     0,     0,     0,    46,
      40,     0,    28,     0,     0,     0,     0,     0,    22,     0,
      25,    43,     0,    29,    31,     0,     0,    27,     0,     0,
      15,    24,     0,     0,    32,     0,    26,     0,    14,    30,
       0,    34,    11,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -11,   -95,    25,   -10,   -95,   102,   -95,   -95,
     -95,   -95,   -94,     8,    -5,    94,   -95,   -95,   -44,   -42,
     -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    77,   119,    12,    23,    41,    43,
      60,    85,    13,   105,   117,    52,    53,    54,    14,    33,
      66,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    29,    30,    31,    67,    48,    49,     1,     2,     3,
      45,    78,    37,   120,    20,    70,    21,    71,     4,     2,
       3,    48,    49,   102,   103,    16,   120,    50,    38,    57,
       5,    58,    73,    74,    78,     6,     7,     8,    51,    46,
      93,    76,    21,    50,    99,   104,    61,    17,   114,    62,
     115,    80,    81,    18,    63,    64,    65,    19,    22,    25,
      26,    27,    32,    35,    34,    36,    39,    40,    42,    47,
      96,    55,    44,    98,    56,    59,    68,    69,    75,    79,
      72,    82,    83,    86,    84,    87,    88,    89,    94,   100,
     113,   101,   108,   109,   107,     4,   110,    90,   116,   122,
     124,    97,    92,    95,   130,   125,    73,   131,   106,    24,
     128,    38,   127,   126,   118,   121,     0,   132,   111,     0,
     112,     0,   123,     0,     0,     0,     0,     0,     0,   129,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91
};

static const yytype_int8 yycheck[] =
{
      11,    12,    13,    14,    46,     4,     5,     3,     4,     5,
       7,    55,    24,   107,     3,     3,     5,     5,    14,     4,
       5,     4,     5,     4,     5,     7,   120,    26,    40,    40,
      26,    42,    36,    37,    78,    31,    32,    33,    37,    36,
       3,    26,     5,    26,    86,    26,     3,    40,     3,     6,
       5,    18,    19,     4,    11,    12,    13,     3,    34,     3,
       0,     9,     3,     6,     3,    35,     3,    17,    27,    41,
      81,    20,    10,    84,     6,    35,    40,     4,     3,    41,
      38,    28,     6,    36,    29,     6,    40,     3,    21,    41,
       4,     6,    18,     6,    22,    14,    30,    39,    15,     6,
       3,    36,    38,    78,     6,   116,    36,    16,    39,     7,
     120,    40,    23,   118,   106,    37,    -1,    25,    41,    -1,
      40,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    14,    26,    31,    32,    33,    43,
      44,    45,    48,    54,    60,    63,     7,    40,     4,     3,
       3,     5,    34,    49,    49,     3,     0,     9,    44,    44,
      44,    44,     3,    61,     3,     6,    35,    24,    40,     3,
      17,    50,    27,    51,    10,     7,    36,    41,     4,     5,
      26,    37,    57,    58,    59,    20,     6,    44,    44,    35,
      52,     3,     6,    11,    12,    13,    62,    61,    40,     4,
       3,     5,    38,    36,    37,     3,    26,    46,    60,    41,
      18,    19,    28,     6,    29,    53,    36,     6,    40,     3,
      39,    57,    38,     3,    21,    46,    44,    36,    44,    61,
      41,     6,     4,     5,    26,    55,    39,    22,    18,     6,
      30,    41,    40,     4,     3,     5,    15,    56,    55,    47,
      54,    37,     6,    40,     3,    44,    56,    23,    47,    41,
       6,    16,    25,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      49,    50,    50,    51,    52,    53,    54,    54,    55,    55,
      55,    55,    55,    55,    56,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    60,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,    10,     2,     1,     2,     1,     3,     3,     5,     3,
       1,     3,     5,     3,     5,     3,     9,     8,     1,     2,
       4,     2,     3,     5,     3,     3,     1,     2,     1,     2,
       4,     2,     3,     5,     2,     3,     5,     1,     3,     3,
       1,     1,     1,     1,     1,     2,     4,     2,     3,     5
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
#line 42 "yapl.y"
                                  {spuneCevaFrumos();}
#line 1346 "y.tab.c"
    break;

  case 3: /* declaratii: declaratie_variabila declaratii  */
#line 44 "yapl.y"
                                             {printf("declar o variabila\n");}
#line 1352 "y.tab.c"
    break;

  case 4: /* declaratii: declaratie_functie declaratii  */
#line 45 "yapl.y"
                                           {printf("declar o functie\n");}
#line 1358 "y.tab.c"
    break;

  case 5: /* declaratii: declaratie_clasa declaratii  */
#line 46 "yapl.y"
                                         {printf("declar o clasa\n");}
#line 1364 "y.tab.c"
    break;

  case 7: /* declaratii: declaratie_variabila  */
#line 48 "yapl.y"
                                  {symbolTable_popScope();}
#line 1370 "y.tab.c"
    break;

  case 8: /* declaratii: declaratie_functie  */
#line 49 "yapl.y"
                                {symbolTable_popScope();}
#line 1376 "y.tab.c"
    break;

  case 9: /* declaratii: declaratie_clasa  */
#line 50 "yapl.y"
                              {symbolTable_popScope();}
#line 1382 "y.tab.c"
    break;

  case 10: /* declaratii: instructiune  */
#line 51 "yapl.y"
                          {symbolTable_popScope();}
#line 1388 "y.tab.c"
    break;

  case 11: /* declaratie_clasa: CLASS ID BGIN_CLASS BGIN_MEMBRS membrii_clasa END_MEMBRS BGIN_FUNCS functii_clasa END_FUNCS END_CLASS  */
#line 54 "yapl.y"
                                                                                                                           {symbolTable_popScope();}
#line 1394 "y.tab.c"
    break;

  case 16: /* instructiune: IF conditie_logica bloc_if  */
#line 61 "yapl.y"
                                          {}
#line 1400 "y.tab.c"
    break;

  case 17: /* instructiune: WHILE conditie_logica bloc_while  */
#line 62 "yapl.y"
                                                {}
#line 1406 "y.tab.c"
    break;

  case 18: /* instructiune: FOR ID IN range_for bloc_for  */
#line 63 "yapl.y"
                                            {}
#line 1412 "y.tab.c"
    break;

  case 19: /* instructiune: ID ASSIGN ID  */
#line 64 "yapl.y"
                            {}
#line 1418 "y.tab.c"
    break;

  case 26: /* declaratie_functie: FUNCTION ID '(' lista_parametrii ')' '-' '>' declaratie_tip_return bloc_functie  */
#line 78 "yapl.y"
                                                                                                 {
                        //printf("functie magica\n");
                        //printf("Pam %s si pam %s", $4, $8);
                        char s1[3000], s[3000];
                        //sprintf(s, "%s %s", $4, $8);
                        char copieMagica[3000];
                        strcpy(s1, (yyvsp[-1].strval));
                        strcpy(s, (yyvsp[-5].strval));
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
                        strcat(aux, " -> ");
                        strcat(aux, s1);

                       // printf("Ce e in varf? %s\n", top->info);
                        symbolTable_InsertMember(aux, (yyvsp[-7].strval));
                   
                       
                        
                        //char type[300];
                        //sprintf(type, "function (%s) -> %s", $4, $8);
                        //symbolTable_InsertMember(type, $2);
                    }
#line 1480 "y.tab.c"
    break;

  case 28: /* declaratie_tip_return: TIP  */
#line 138 "yapl.y"
                            {(yyval.strval) = (yyvsp[0].strval);}
#line 1486 "y.tab.c"
    break;

  case 29: /* declaratie_tip_return: CONST TIP  */
#line 139 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1492 "y.tab.c"
    break;

  case 30: /* declaratie_tip_return: TIP '[' INTREG ']'  */
#line 140 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1498 "y.tab.c"
    break;

  case 35: /* lista_parametrii: lista_parametrii ',' lista_parametrii  */
#line 148 "yapl.y"
                                                           {char *s = (char*)malloc(1000); sprintf(s,"%s, %s",(yyvsp[-2].strval), (yyvsp[0].strval)); (yyval.strval) = s; /*printf("magie uau %s\n",$$)*/;}
#line 1504 "y.tab.c"
    break;

  case 36: /* lista_parametrii: declaratie_parametru  */
#line 149 "yapl.y"
                                        {(yyval.strval) = strdup((yyvsp[0].strval));}
#line 1510 "y.tab.c"
    break;

  case 37: /* declaratie_parametru: declaratie_tip_functie ID  */
#line 152 "yapl.y"
                                                 {char s[100]; sprintf(s,"%s %s", (yyvsp[-1].strval), (yyvsp[0].strval)); (yyval.strval) = s; symbolTable_InsertMember((yyvsp[-1].strval), (yyvsp[0].strval));}
#line 1516 "y.tab.c"
    break;

  case 38: /* declaratie_tip_functie: TIP  */
#line 155 "yapl.y"
                             {(yyval.strval) = (yyvsp[0].strval);}
#line 1522 "y.tab.c"
    break;

  case 39: /* declaratie_tip_functie: CONST TIP  */
#line 156 "yapl.y"
                                {char s[100]; sprintf(s,"const %s", (yyvsp[0].strval)); (yyval.strval) = s;}
#line 1528 "y.tab.c"
    break;

  case 40: /* declaratie_tip_functie: TIP '[' INTREG ']'  */
#line 157 "yapl.y"
                                     {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); (yyval.strval) = s;}
#line 1534 "y.tab.c"
    break;

  case 45: /* declaratie_ids: ID ',' declaratie_ids  */
#line 167 "yapl.y"
                                       {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));}
#line 1540 "y.tab.c"
    break;

  case 46: /* declaratie_ids: ID ASSIGN ID ',' declaratie_ids  */
#line 168 "yapl.y"
                                                 {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-4].strval));}
#line 1546 "y.tab.c"
    break;

  case 47: /* declaratie_ids: ID  */
#line 169 "yapl.y"
                    {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[0].strval));}
#line 1552 "y.tab.c"
    break;

  case 48: /* declaratie_ids: ID ASSIGN ID  */
#line 170 "yapl.y"
                              {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));}
#line 1558 "y.tab.c"
    break;

  case 49: /* declaratie_ids: ID ASSIGN CONSTANTA  */
#line 171 "yapl.y"
                                     {symbolTable_InsertMember(currentTypeDeclared, (yyvsp[-2].strval));}
#line 1564 "y.tab.c"
    break;

  case 51: /* CONSTANTA: REAL  */
#line 175 "yapl.y"
                 {printf("uuuf\n");}
#line 1570 "y.tab.c"
    break;

  case 54: /* declaratie_tip: TIP  */
#line 180 "yapl.y"
                    {char * s= strdup((yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1576 "y.tab.c"
    break;

  case 55: /* declaratie_tip: CONST TIP  */
#line 181 "yapl.y"
                          {char s[100]; sprintf(s,"const %s",(yyvsp[0].strval)); symbolTable_ChangeCurrentType(s);}
#line 1582 "y.tab.c"
    break;

  case 56: /* declaratie_tip: TIP '[' INTREG ']'  */
#line 182 "yapl.y"
                               {char s[100]; sprintf(s,"%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].strval)); symbolTable_ChangeCurrentType(s);}
#line 1588 "y.tab.c"
    break;


#line 1592 "y.tab.c"

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

#line 187 "yapl.y"

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
 
    
    if(argc < 2)
    {
        PrintError("Nu-i bini, trebuie macar un argument");       
    }
    yyin = fopen(argv[1], "r");

    top = stiva_createNode("global");
    functionParameters = stiva_createNode("bottom");
    current = symbolTable_CreateNode();
    currentTypeDeclared = (char*)malloc(30);
    current->name = Scope_GetInfo();
    radacina = current;
    yyparse();
    symbolTable_Print("symbolTable.txt");
}
