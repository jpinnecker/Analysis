/* A Bison parser, made by GNU Bison 3.6.3.  */

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
#define YYBISON_VERSION "3.6.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

  #include <cstdio>
  #include <string>
  #include <iostream>
  #include <fstream>
  #include <sys/stat.h>
  #include "TokenProcessor.h"
  using namespace std;

  //Enable debugging output
  #define YYDEBUG 1

  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  
  //Instanziierung unseres Token-Prozessors
  TokenProcessor tokenProcessor = TokenProcessor();

  void yyerror(const char *s);

#line 94 "grammar.tab.cpp"

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
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTID = 259,                   /* INTID  */
    LONGID = 260,                  /* LONGID  */
    LONGLONGID = 261,              /* LONGLONGID  */
    LONGDOUBLEID = 262,            /* LONGDOUBLEID  */
    DOUBLEID = 263,                /* DOUBLEID  */
    SHORTID = 264,                 /* SHORTID  */
    CHARID = 265,                  /* CHARID  */
    FLOATID = 266,                 /* FLOATID  */
    INUMBER = 267,                 /* INUMBER  */
    POINTER = 268,                 /* POINTER  */
    VOID = 269,                    /* VOID  */
    ENDL = 270,                    /* ENDL  */
    CSTRING = 271,                 /* CSTRING  */
    RETURN = 272,                  /* RETURN  */
    FNUMBER = 273,                 /* FNUMBER  */
    CHARACTER = 274                /* CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "grammar.y"

    char* string; //remember to free!!!
    int integer;

#line 168 "grammar.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTID = 4,                      /* INTID  */
  YYSYMBOL_LONGID = 5,                     /* LONGID  */
  YYSYMBOL_LONGLONGID = 6,                 /* LONGLONGID  */
  YYSYMBOL_LONGDOUBLEID = 7,               /* LONGDOUBLEID  */
  YYSYMBOL_DOUBLEID = 8,                   /* DOUBLEID  */
  YYSYMBOL_SHORTID = 9,                    /* SHORTID  */
  YYSYMBOL_CHARID = 10,                    /* CHARID  */
  YYSYMBOL_FLOATID = 11,                   /* FLOATID  */
  YYSYMBOL_INUMBER = 12,                   /* INUMBER  */
  YYSYMBOL_POINTER = 13,                   /* POINTER  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_ENDL = 15,                      /* ENDL  */
  YYSYMBOL_CSTRING = 16,                   /* CSTRING  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_FNUMBER = 18,                   /* FNUMBER  */
  YYSYMBOL_CHARACTER = 19,                 /* CHARACTER  */
  YYSYMBOL_20_ = 20,                       /* '['  */
  YYSYMBOL_21_ = 21,                       /* ']'  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '{'  */
  YYSYMBOL_25_ = 25,                       /* '}'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_cfile = 31,                     /* cfile  */
  YYSYMBOL_bodylines = 32,                 /* bodylines  */
  YYSYMBOL_bodyline = 33,                  /* bodyline  */
  YYSYMBOL_params = 34,                    /* params  */
  YYSYMBOL_param = 35,                     /* param  */
  YYSYMBOL_pointer = 36,                   /* pointer  */
  YYSYMBOL_integer = 37,                   /* integer  */
  YYSYMBOL_floating = 38,                  /* floating  */
  YYSYMBOL_double = 39,                    /* double  */
  YYSYMBOL_character = 40,                 /* character  */
  YYSYMBOL_short = 41,                     /* short  */
  YYSYMBOL_long = 42,                      /* long  */
  YYSYMBOL_long_long = 43,                 /* long_long  */
  YYSYMBOL_long_double = 44                /* long_double  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

#define YYMAXUTOK   274


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
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      22,    23,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    48,    49,    56,    59,    62,    65,    68,
      71,    74,    77,    80,    89,    93,    97,   101,   105,   109,
     113,   117,   127,   131,   135,   139,   143,   147,   151,   155,
     159,   169,   176,   180,   184,   188,   192,   195,   200,   203,
     211,   212,   214,   215,   216,   221,   222,   223,   224,   229,
     230,   231,   234,   235,   236,   239,   240,   241,   242,   245,
     246,   247,   250,   251,   252,   255,   256,   257,   260,   261,
     262,   265,   266,   267
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "INTID",
  "LONGID", "LONGLONGID", "LONGDOUBLEID", "DOUBLEID", "SHORTID", "CHARID",
  "FLOATID", "INUMBER", "POINTER", "VOID", "ENDL", "CSTRING", "RETURN",
  "FNUMBER", "CHARACTER", "'['", "']'", "'('", "')'", "'{'", "'}'", "','",
  "';'", "'='", "'&'", "$accept", "cfile", "bodylines", "bodyline",
  "params", "param", "pointer", "integer", "floating", "double",
  "character", "short", "long", "long_long", "long_double", YY_NULLPTR
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
      91,    93,    40,    41,   123,   125,    44,    59,    61,    38
};
#endif

#define YYPACT_NINF (-7)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      27,     2,    -6,    44,    53,    54,    57,    58,    67,    68,
      71,    16,    17,    -7,    -3,    -7,    -7,    -7,    47,     0,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,     9,    39,    -7,    45,    51,    -7,    46,    55,
      -7,    56,    72,    -7,    21,    80,    -7,    43,    82,    -7,
      59,    85,    -7,    -1,    86,    -7,    42,    -7,    40,    48,
      -7,    -7,    -7,    -7,    -7,    60,    74,    81,    -7,    -7,
      83,    -7,    -7,    84,    -7,    -7,    87,    -7,    -7,    88,
      -7,    -7,    -7,    89,    -7,    -7,    90,    -7,    -7,    91,
      -7,    -7,    -7,    -7,    62,    -7,    -7,     9,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    49,    65,    68,    71,    55,    62,    59,
      52,     0,     0,    35,    34,    33,    36,    37,     0,     0,
       4,    13,     5,     8,     6,     9,    12,    10,    11,     7,
      39,    38,    42,     0,    22,     0,     0,    27,     0,     0,
      28,     0,     0,    24,     0,     0,    23,     0,     0,    29,
       0,     0,    26,     0,     0,    25,     0,    45,     0,     0,
      32,     1,     3,    43,    44,     0,    41,     0,    51,    50,
       0,    67,    66,     0,    70,    69,     0,    73,    72,     0,
      58,    56,    57,     0,    64,    63,     0,    61,    60,     0,
      54,    53,    47,    46,     0,    30,    31,    42,    14,    19,
      20,    16,    15,    21,    18,    17,    48,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -7,    -7,    -7,    94,    -7,     4,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    65,    66,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      -2,     1,    87,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    63,    11,    12,    13,    32,    30,    88,    57,
      59,    60,    64,    14,    77,    15,    16,    17,     1,    31,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    78,
      11,    12,    13,    92,    58,    90,    80,    61,    68,    71,
      14,    67,    15,    16,    17,    81,    93,    69,    72,    74,
      91,    82,    84,    70,    33,   106,    34,    73,    75,    94,
      95,    85,    35,    36,    39,    37,    40,    42,    45,    43,
      46,    38,    41,    96,    76,    44,    47,    48,    51,    49,
      52,    54,    79,    55,    83,    50,    53,    86,    89,    56,
      97,   107,    98,     0,    99,   100,     0,     0,   101,   102,
     103,   104,   105,    62
};

static const yytype_int8 yycheck[] =
{
       0,     1,     3,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     3,    13,    14,    15,    22,    15,    19,     3,
       3,    24,    13,    23,     3,    25,    26,    27,     1,    27,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    18,
      13,    14,    15,     3,    28,     3,     3,     0,     3,     3,
      23,    12,    25,    26,    27,    12,    16,    12,    12,     3,
      18,    18,     3,    12,    20,     3,    22,    12,    12,    29,
      22,    12,    28,    20,    20,    22,    22,    20,    20,    22,
      22,    28,    28,    23,    12,    28,    28,    20,    20,    22,
      22,    20,    12,    22,    12,    28,    28,    12,    12,    28,
      26,    97,    21,    -1,    21,    21,    -1,    -1,    21,    21,
      21,    21,    21,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    13,    14,    15,    23,    25,    26,    27,    31,    32,
      33,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      15,    27,    22,    20,    22,    28,    20,    22,    28,    20,
      22,    28,    20,    22,    28,    20,    22,    28,    20,    22,
      28,    20,    22,    28,    20,    22,    28,     3,    28,     3,
      24,     0,    33,     3,    13,    34,    35,    12,     3,    12,
      12,     3,    12,    12,     3,    12,    12,     3,    18,    12,
       3,    12,    18,    12,     3,    12,    12,     3,    19,    12,
       3,    18,     3,    16,    29,    22,    23,    26,    21,    21,
      21,    21,    21,    21,    21,    21,     3,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      34,    34,    35,    35,    35,    36,    36,    36,    36,    37,
      37,    37,    38,    38,    38,    39,    39,    39,    39,    40,
      40,    40,    41,    41,    41,    42,    42,    42,    43,    43,
      43,    44,    44,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     2,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     0,     1,     1,     2,     3,     3,     4,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3
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


/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 45 "grammar.y"
              {
        cout << "Finished Parsing..." << endl;}
#line 1267 "grammar.tab.cpp"
    break;

  case 5:
#line 56 "grammar.y"
            {
        tokenProcessor.processToken(sizeof(int), "Integer found... ");
    }
#line 1275 "grammar.tab.cpp"
    break;

  case 6:
#line 59 "grammar.y"
             {
        tokenProcessor.processToken(sizeof(double), "Double found... ");
    }
#line 1283 "grammar.tab.cpp"
    break;

  case 7:
#line 62 "grammar.y"
                  {
        tokenProcessor.processToken(sizeof(long double), "Long Double found... ");
    }
#line 1291 "grammar.tab.cpp"
    break;

  case 8:
#line 65 "grammar.y"
               {
        tokenProcessor.processToken(sizeof(float), "Float found... ");
    }
#line 1299 "grammar.tab.cpp"
    break;

  case 9:
#line 68 "grammar.y"
                {
        tokenProcessor.processToken(sizeof(char), "Character found... ");
    }
#line 1307 "grammar.tab.cpp"
    break;

  case 10:
#line 71 "grammar.y"
           {
        tokenProcessor.processToken(sizeof(long), "Long found... ");
    }
#line 1315 "grammar.tab.cpp"
    break;

  case 11:
#line 74 "grammar.y"
                {
        tokenProcessor.processToken(sizeof(long long), "Long Long found... ");
    }
#line 1323 "grammar.tab.cpp"
    break;

  case 12:
#line 77 "grammar.y"
            {
        tokenProcessor.processToken(sizeof(short), "Short found... ");
    }
#line 1331 "grammar.tab.cpp"
    break;

  case 13:
#line 80 "grammar.y"
              {
        tokenProcessor.processToken(sizeof(void*), "Pointer found... ");
    }
#line 1339 "grammar.tab.cpp"
    break;

  case 14:
#line 89 "grammar.y"
                            {
        tokenProcessor.processToken(sizeof(int)*(yyvsp[-1].integer)+sizeof(void*), "Integer array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1348 "grammar.tab.cpp"
    break;

  case 15:
#line 93 "grammar.y"
                               {
        tokenProcessor.processToken(sizeof(double)*(yyvsp[-1].integer)+sizeof(void*), "Double array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1357 "grammar.tab.cpp"
    break;

  case 16:
#line 97 "grammar.y"
                                   {
        tokenProcessor.processToken(sizeof(long double)*(yyvsp[-1].integer)+sizeof(void*), "Long Double array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1366 "grammar.tab.cpp"
    break;

  case 17:
#line 101 "grammar.y"
                              {
        tokenProcessor.processToken(sizeof(float)*(yyvsp[-1].integer)+sizeof(void*), "Floating array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1375 "grammar.tab.cpp"
    break;

  case 18:
#line 105 "grammar.y"
                             {
        tokenProcessor.processToken(sizeof(char)*(yyvsp[-1].integer)+sizeof(void*), "Character array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1384 "grammar.tab.cpp"
    break;

  case 19:
#line 109 "grammar.y"
                             {
        tokenProcessor.processToken(sizeof(long)*(yyvsp[-1].integer)+sizeof(void*), "Long array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1393 "grammar.tab.cpp"
    break;

  case 20:
#line 113 "grammar.y"
                                 {
        tokenProcessor.processToken(sizeof(long long)*(yyvsp[-1].integer)+sizeof(void*), "Long Long array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1402 "grammar.tab.cpp"
    break;

  case 21:
#line 117 "grammar.y"
                              {
        tokenProcessor.processToken(sizeof(short)*(yyvsp[-1].integer)+sizeof(void*), "Short array of length " + to_string((yyvsp[-1].integer)) + " found... ");
        free((yyvsp[-3].string));
    }
#line 1411 "grammar.tab.cpp"
    break;

  case 22:
#line 127 "grammar.y"
                {
        tokenProcessor.registerFunction(sizeof(int), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1420 "grammar.tab.cpp"
    break;

  case 23:
#line 131 "grammar.y"
                   {
        tokenProcessor.registerFunction(sizeof(double), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1429 "grammar.tab.cpp"
    break;

  case 24:
#line 135 "grammar.y"
                       {
        tokenProcessor.registerFunction(sizeof(long double), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1438 "grammar.tab.cpp"
    break;

  case 25:
#line 139 "grammar.y"
                  {
        tokenProcessor.registerFunction(sizeof(float), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1447 "grammar.tab.cpp"
    break;

  case 26:
#line 143 "grammar.y"
                 {
        tokenProcessor.registerFunction(sizeof(char), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1456 "grammar.tab.cpp"
    break;

  case 27:
#line 147 "grammar.y"
                 {
        tokenProcessor.registerFunction(sizeof(long), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1465 "grammar.tab.cpp"
    break;

  case 28:
#line 151 "grammar.y"
                     {
        tokenProcessor.registerFunction(sizeof(long long), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1474 "grammar.tab.cpp"
    break;

  case 29:
#line 155 "grammar.y"
                  {
        tokenProcessor.registerFunction(sizeof(short), (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1483 "grammar.tab.cpp"
    break;

  case 30:
#line 159 "grammar.y"
                          {
        tokenProcessor.registerFunction(0, (yyvsp[-1].string));
        free((yyvsp[-1].string));
    }
#line 1492 "grammar.tab.cpp"
    break;

  case 31:
#line 169 "grammar.y"
                                {
        tokenProcessor.processFunction((yyvsp[-3].string));
        free((yyvsp[-3].string));
    }
#line 1501 "grammar.tab.cpp"
    break;

  case 32:
#line 176 "grammar.y"
              {
        ;
    }
#line 1509 "grammar.tab.cpp"
    break;

  case 33:
#line 180 "grammar.y"
          {
        ;
    }
#line 1517 "grammar.tab.cpp"
    break;

  case 34:
#line 184 "grammar.y"
          {
        ;
    }
#line 1525 "grammar.tab.cpp"
    break;

  case 35:
#line 188 "grammar.y"
           {
        tokenProcessor.incrementLine();
    }
#line 1533 "grammar.tab.cpp"
    break;

  case 36:
#line 192 "grammar.y"
          {
        ;
    }
#line 1541 "grammar.tab.cpp"
    break;

  case 37:
#line 195 "grammar.y"
          {
        ;
    }
#line 1549 "grammar.tab.cpp"
    break;

  case 38:
#line 200 "grammar.y"
                {
        cout << "Omitting unknown rule on line " << tokenProcessor.getLine() << endl;
    }
#line 1557 "grammar.tab.cpp"
    break;

  case 39:
#line 203 "grammar.y"
                 {
        cout << "Omitting unknown rule on line " << tokenProcessor.getLine() << endl;
        tokenProcessor.incrementLine();
    }
#line 1566 "grammar.tab.cpp"
    break;

  case 43:
#line 215 "grammar.y"
                 {free((yyvsp[0].string));}
#line 1572 "grammar.tab.cpp"
    break;

  case 45:
#line 221 "grammar.y"
                       {free((yyvsp[0].string));}
#line 1578 "grammar.tab.cpp"
    break;

  case 47:
#line 223 "grammar.y"
                             {free((yyvsp[0].string));}
#line 1584 "grammar.tab.cpp"
    break;

  case 48:
#line 224 "grammar.y"
                                 {free((yyvsp[0].string));}
#line 1590 "grammar.tab.cpp"
    break;

  case 49:
#line 229 "grammar.y"
          {free((yyvsp[0].string));}
#line 1596 "grammar.tab.cpp"
    break;

  case 50:
#line 230 "grammar.y"
                        {free((yyvsp[-2].string));}
#line 1602 "grammar.tab.cpp"
    break;

  case 51:
#line 231 "grammar.y"
                           {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1608 "grammar.tab.cpp"
    break;

  case 52:
#line 234 "grammar.y"
            {free((yyvsp[0].string));}
#line 1614 "grammar.tab.cpp"
    break;

  case 53:
#line 235 "grammar.y"
                          {free((yyvsp[-2].string));}
#line 1620 "grammar.tab.cpp"
    break;

  case 54:
#line 236 "grammar.y"
                             {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1626 "grammar.tab.cpp"
    break;

  case 55:
#line 239 "grammar.y"
             {free((yyvsp[0].string));}
#line 1632 "grammar.tab.cpp"
    break;

  case 56:
#line 240 "grammar.y"
                           {free((yyvsp[-2].string));}
#line 1638 "grammar.tab.cpp"
    break;

  case 57:
#line 241 "grammar.y"
                           {free((yyvsp[-2].string));}
#line 1644 "grammar.tab.cpp"
    break;

  case 58:
#line 242 "grammar.y"
                              {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1650 "grammar.tab.cpp"
    break;

  case 59:
#line 245 "grammar.y"
           {free((yyvsp[0].string));}
#line 1656 "grammar.tab.cpp"
    break;

  case 60:
#line 246 "grammar.y"
                           {free((yyvsp[-2].string));}
#line 1662 "grammar.tab.cpp"
    break;

  case 61:
#line 247 "grammar.y"
                            {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1668 "grammar.tab.cpp"
    break;

  case 62:
#line 250 "grammar.y"
            {free((yyvsp[0].string));}
#line 1674 "grammar.tab.cpp"
    break;

  case 63:
#line 251 "grammar.y"
                          {free((yyvsp[-2].string));}
#line 1680 "grammar.tab.cpp"
    break;

  case 64:
#line 252 "grammar.y"
                             {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1686 "grammar.tab.cpp"
    break;

  case 65:
#line 255 "grammar.y"
           {free((yyvsp[0].string));}
#line 1692 "grammar.tab.cpp"
    break;

  case 66:
#line 256 "grammar.y"
                         {free((yyvsp[-2].string));}
#line 1698 "grammar.tab.cpp"
    break;

  case 67:
#line 257 "grammar.y"
                            {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1704 "grammar.tab.cpp"
    break;

  case 68:
#line 260 "grammar.y"
               {free((yyvsp[0].string));}
#line 1710 "grammar.tab.cpp"
    break;

  case 69:
#line 261 "grammar.y"
                             {free((yyvsp[-2].string));}
#line 1716 "grammar.tab.cpp"
    break;

  case 70:
#line 262 "grammar.y"
                                {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1722 "grammar.tab.cpp"
    break;

  case 71:
#line 265 "grammar.y"
                 {free((yyvsp[0].string));}
#line 1728 "grammar.tab.cpp"
    break;

  case 72:
#line 266 "grammar.y"
                               {free((yyvsp[-2].string));}
#line 1734 "grammar.tab.cpp"
    break;

  case 73:
#line 267 "grammar.y"
                                  {free((yyvsp[-2].string)); free((yyvsp[0].string));}
#line 1740 "grammar.tab.cpp"
    break;


#line 1744 "grammar.tab.cpp"

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
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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

#line 269 "grammar.y"


int main(int argc, char* argv[]) {

  FILE* input;
  string pfad;

  if(argc >= 2){
    input = fopen(argv[1], "r");
  } else {
    // the user give the File-pfad to be analysed  
    cout << "Geben Sie den Datei-Pfad an: ";
    do{
        getline(cin, pfad);
    } while(pfad.empty());

    input = fopen(pfad.c_str(), "r");
  }

  // Make sure it is valid:
  if (!input) {
    cout << "I can't open the file!" << endl;
    return 1;
  }

  cout << "Wenn Sie die Ausgabe in eine Datei speichern wollen, geben Sie jetzt bitte einen Pfad an." << endl
       << ": ";
  getline(cin, pfad);

  ofstream output;
  
  //Überprüfung auf Existenz.
  struct stat buffer;
  if(stat(pfad.c_str(), &buffer) == 0){
    cout << "Datei existiert bereits. Ueberschreiben? [J/N] ";
    char antwort = getchar();
    if(antwort == 'Y' || antwort == 'y' || antwort == 'J' || antwort == 'j'){
        output.open(pfad);
        cout.rdbuf(output.rdbuf());
    }
  } else if(!pfad.empty()) {
    output.open(pfad);
    cout.rdbuf(output.rdbuf());
  }

  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = input;
  
  // Parse through the input:
  yyparse();

  tokenProcessor.printResults();
}

void yyerror(const char *s) {
  cout << "Parse error on line: " << tokenProcessor.getLine() << " - Message: " << s << endl;
}

