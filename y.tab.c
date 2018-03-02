/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler_yacc.y" /* yacc.c:339  */


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define YYSTYPE tnode*
	#define reg_index int

	#include "exprtree.h"
	#include "exprtree.c"

	int yylex(void);
	extern FILE *yyin;
    void yyerror(char const *s);
    struct varList *list = NULL, *node = NULL;
    struct paramList *plist = NULL, *pnode = NULL;


#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    IF = 262,
    THEN = 263,
    ELSE = 264,
    ENDIF = 265,
    WHILE = 266,
    DO = 267,
    ENDWHILE = 268,
    BREAK = 269,
    CONTINUE = 270,
    ID = 271,
    NUM = 272,
    INT = 273,
    STR = 274,
    READ = 275,
    WRITE = 276,
    ASSIGN = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    LT = 282,
    LE = 283,
    GT = 284,
    GE = 285,
    NE = 286,
    EQ = 287
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define IF 262
#define THEN 263
#define ELSE 264
#define ENDIF 265
#define WHILE 266
#define DO 267
#define ENDWHILE 268
#define BREAK 269
#define CONTINUE 270
#define ID 271
#define NUM 272
#define INT 273
#define STR 274
#define READ 275
#define WRITE 276
#define ASSIGN 277
#define PLUS 278
#define MINUS 279
#define MUL 280
#define DIV 281
#define LT 282
#define LE 283
#define GT 284
#define GE 285
#define NE 286
#define EQ 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      33,    34,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    41,    42,    45,    46,    48,    50,    54,
      55,    57,    58,    60,    63,    64,    67,    68,    69,    70,
      73,    74,    76,    77,    80,    82,    83,    86,    87,    88,
      89,    90,    92,    93,    96,    97,    98,   100,   103,   104,
     108,   108,   108,   108,   108,   108,   108,   108,   112,   116,
     120,   124,   125,   129,   133,   137,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   157,   159,   160,   162,   162,   163,   171,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DECL", "ENDDECL", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE",
  "ID", "NUM", "INT", "STR", "READ", "WRITE", "ASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "LT", "LE", "GT", "GE", "NE", "EQ", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'['", "']'", "'&'", "$accept", "program",
  "FDefBlock", "MainBlock", "Fdef", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "instructions", "LDeclBlock", "LDeclList", "LDecl", "LidList",
  "Gid", "Type", "ParamList", "Param", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "E", "CallStmt", "ExprList", "AsgE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    40,    41,   123,   125,    59,    44,    91,
      93,    38
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,    70,    15,    10,   -40,     6,   -40,   -40,    22,    -6,
      50,    51,    55,    -7,    61,    73,    91,    89,   149,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     8,   -40,
     -40,   -40,    38,   -40,    -3,   -40,     6,   -40,   -40,    97,
     -40,    52,   -40,    -3,   -10,   -10,   -40,   -40,   -10,   -10,
      13,   -10,   -40,   -40,   164,   -40,   -40,   -10,   -40,   -40,
      43,   104,    42,   -40,   -40,   -40,    90,   -40,   -40,    60,
     -40,   -40,   -10,   108,   262,   -40,   -40,   274,   310,     9,
     211,    86,    95,   286,   -40,   247,    83,   113,   -40,   -40,
      -3,    83,   -40,    -3,   298,   -40,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   127,   125,   103,   -10,
      99,   105,   110,   -40,   132,    12,   -40,   112,   -40,    14,
     -40,   -40,   318,   318,   217,   217,   235,   235,   235,   235,
     235,   235,   208,   208,   -40,   310,   -10,   -40,   -40,   -40,
     -40,    83,   102,   115,   181,   196,   229,   -40,   137,   155,
     208,   122,   124,   -40,   126,   131,   101,   -40,   -40,   -40,
     -40,   135,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    74,     0,     0,     4,     0,     7,    19,     0,     0,
       0,     0,     0,    75,     0,     0,     0,    74,    74,    39,
      40,    41,    42,    43,    44,    46,    45,    47,     0,    10,
      32,    33,     0,    12,     0,     1,     0,     3,     6,     0,
      21,     0,    23,     0,    74,    74,    54,    55,    74,    74,
      74,    74,    78,    17,    74,    18,    38,    74,     9,    11,
      31,     0,     0,    15,     2,     5,     0,    20,    22,     0,
      26,    68,    74,     0,     0,    56,    70,     0,    73,     0,
       0,    75,     0,     0,    16,     0,    36,     0,    30,    13,
       0,    36,    24,     0,     0,    69,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,     0,     0,     0,    74,
      76,     0,     0,    50,     0,     0,    35,     0,    14,     0,
      25,    67,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    74,    74,    71,    72,    74,    48,    49,    37,
      29,     0,    28,     0,    74,    74,     0,    34,     0,     0,
      74,     0,     0,    77,     0,     0,    74,    52,    53,    27,
       8,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,     0,   140,   -40,   -40,   130,   -40,    24,
     -40,   -40,   136,   -40,   -39,    37,    92,    40,   -14,   -17,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -37,     1,   -40,
      -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    36,     4,    38,     5,    32,    33,    62,     6,
      17,    41,    42,    69,    63,   114,   115,   116,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    74,    75,    79,
      76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    56,    27,    54,    70,    37,    13,    71,    77,     1,
      35,    78,    80,    60,    83,    16,    28,    28,    27,    27,
      85,    29,    61,    72,    30,    31,    48,    44,    40,    81,
      57,    73,    49,    30,    31,    94,    64,    56,    16,    34,
      30,    31,    39,   108,    58,    43,   140,   109,   143,    82,
     141,   118,   141,    28,   120,    27,    30,    31,    67,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    34,
      30,    31,   135,    39,     7,     8,    86,     9,    43,    89,
      90,    10,    87,    45,    11,    12,    13,     1,    46,     2,
      14,    15,    47,    53,    50,    16,     9,    92,    93,   146,
      10,    30,    31,    11,    12,    13,    51,    52,     9,    14,
      15,   161,    10,    66,    16,    11,    12,    13,   144,   145,
      88,    14,    15,    91,    95,    49,    16,    56,    56,   111,
     117,    28,    28,    27,    27,   132,   156,   133,   136,    56,
     134,   148,   137,    28,    28,    27,    27,   138,   139,    28,
     149,    27,   142,    55,   154,    28,     9,    27,     1,   157,
      10,   158,    59,    11,    12,    13,   159,   160,    84,    14,
      15,     9,   162,   155,    16,    10,    65,    68,    11,    12,
      13,   147,     0,   119,    14,    15,     0,     0,     9,    16,
     150,   151,    10,     0,     0,    11,    12,    13,     0,     0,
       0,    14,    15,     9,     0,     0,    16,    10,     0,   152,
      11,    12,    13,     0,     0,     9,    14,    15,     0,    10,
       0,    16,    11,    12,    13,     0,     0,     0,    14,    15,
       0,     0,     0,    16,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   100,   101,   102,   103,   104,   105,
       0,   110,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,     0,   153,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   113,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   107,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     112,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   121,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    98,    99,   100,   101,   102,   103,   104,
     105
};

static const yytype_int16 yycheck[] =
{
       1,    18,     1,    17,    43,     5,    16,    17,    45,     3,
       0,    48,    49,    16,    51,    25,    17,    18,    17,    18,
      57,     6,    25,    33,    18,    19,    33,    33,     6,    16,
      22,    41,    39,    18,    19,    72,    36,    54,    25,     2,
      18,    19,     5,    34,     6,     8,    34,    38,    34,    50,
      38,    90,    38,    54,    93,    54,    18,    19,     6,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    32,
      18,    19,   109,    36,     4,     5,    33,     7,    41,    37,
      38,    11,    39,    33,    14,    15,    16,     3,    37,     5,
      20,    21,    37,     4,    33,    25,     7,    37,    38,   136,
      11,    18,    19,    14,    15,    16,    33,    16,     7,    20,
      21,    10,    11,    16,    25,    14,    15,    16,   132,   133,
      16,    20,    21,    33,    16,    39,    25,   144,   145,    34,
      17,   132,   133,   132,   133,     8,   150,    12,    39,   156,
      37,    39,    37,   144,   145,   144,   145,    37,    16,   150,
      35,   150,    40,     4,    17,   156,     7,   156,     3,    37,
      11,    37,    32,    14,    15,    16,    40,    36,     4,    20,
      21,     7,    37,   149,    25,    11,    36,    41,    14,    15,
      16,   141,    -1,    91,    20,    21,    -1,    -1,     7,    25,
       9,    10,    11,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    21,     7,    -1,    -1,    25,    11,    -1,    13,
      14,    15,    16,    -1,    -1,     7,    20,    21,    -1,    11,
      -1,    25,    14,    15,    16,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    25,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    27,    28,    29,    30,    31,    32,
      -1,    40,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    27,    28,    29,    30,    31,    32,    -1,    40,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    25,    26,    27,    28,    29,    30,    31,
      32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,    43,    45,    47,    51,     4,     5,     7,
      11,    14,    15,    16,    20,    21,    25,    52,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    70,    72,     6,
      18,    19,    48,    49,    57,     0,    44,    45,    46,    57,
       6,    53,    54,    57,    33,    33,    37,    37,    33,    39,
      33,    33,    16,     4,    60,     4,    61,    22,     6,    49,
      16,    25,    50,    56,    45,    46,    16,     6,    54,    55,
      56,    17,    33,    41,    69,    70,    72,    69,    69,    71,
      69,    16,    72,    69,     4,    69,    33,    39,    16,    37,
      38,    33,    37,    38,    69,    16,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    34,    34,    34,    38,
      40,    34,    34,    37,    57,    58,    59,    17,    56,    58,
      56,    34,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,     8,    12,    37,    69,    39,    37,    37,    16,
      34,    38,    40,    34,    60,    60,    69,    59,    39,    35,
       9,    10,    13,    40,    17,    51,    60,    37,    37,    40,
      36,    10,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    46,    47,
      47,    48,    48,    49,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      64,    65,    65,    66,    67,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    71,    72,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     1,     8,     3,
       2,     2,     1,     3,     3,     1,     4,     3,     3,     2,
       3,     2,     2,     1,     3,     3,     1,     7,     4,     4,
       2,     1,     1,     1,     3,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,    10,     8,     8,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     5,     3,     1,     0,     1,     4,     7,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 7:
#line 48 "compiler_yacc.y" /* yacc.c:1646  */
    {exit(1);}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "compiler_yacc.y" /* yacc.c:1646  */
    {functionCheck((yyvsp[-6]), plist, (yyvsp[-7])->type);printLocalTable();plist = NULL;deallocateLocalTable();}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "compiler_yacc.y" /* yacc.c:1646  */
    {printSymbolTable();}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "compiler_yacc.y" /* yacc.c:1646  */
    {}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "compiler_yacc.y" /* yacc.c:1646  */
    {declareVariables((yyvsp[-2])->type, list);node=list=NULL;}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 63 "compiler_yacc.y" /* yacc.c:1646  */
    {if(node)list = appendVariable(list, node);}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "compiler_yacc.y" /* yacc.c:1646  */
    {if(node)list = node;}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 67 "compiler_yacc.y" /* yacc.c:1646  */
    {printf("Ping\n");}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "compiler_yacc.y" /* yacc.c:1646  */
    {print(NULL);}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 69 "compiler_yacc.y" /* yacc.c:1646  */
    {print((yyvsp[-1]));}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 70 "compiler_yacc.y" /* yacc.c:1646  */
    {print(NULL );}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "compiler_yacc.y" /* yacc.c:1646  */
    {}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 74 "compiler_yacc.y" /* yacc.c:1646  */
    {}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "compiler_yacc.y" /* yacc.c:1646  */
    {declareLocalVariables((yyvsp[-2])->type, list);node=list=NULL;}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "compiler_yacc.y" /* yacc.c:1646  */
    {if(node)list = appendVariable(list, node);}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "compiler_yacc.y" /* yacc.c:1646  */
    {if(node)list = node;}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 86 "compiler_yacc.y" /* yacc.c:1646  */
    {int size = (yyvsp[-4])->val;size *= (yyvsp[-1])->val;if(size <= 0)yyerror("Invalid array declaration\n"); node = makeVarList((yyvsp[-6]), size, (yyvsp[-4])->val, 0, NULL);}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 87 "compiler_yacc.y" /* yacc.c:1646  */
    {if((yyvsp[-1])->val <= 0)yyerror("Invalid array declaration\n");node = makeVarList((yyvsp[-3]), (yyvsp[-1])->val, 1, 0, NULL);}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "compiler_yacc.y" /* yacc.c:1646  */
    {node = makeVarList((yyvsp[-3]), -1, 1, 0, plist);}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 89 "compiler_yacc.y" /* yacc.c:1646  */
    {node = makeVarList((yyvsp[-1]), 1, 1, 1, NULL);}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 90 "compiler_yacc.y" /* yacc.c:1646  */
    {node = makeVarList((yyvsp[0]), 1, 1, 0, NULL);}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 92 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_AUX, TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 93 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_AUX, TYPE_STR, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "compiler_yacc.y" /* yacc.c:1646  */
    {plist = appendParam(plist, pnode);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 97 "compiler_yacc.y" /* yacc.c:1646  */
    {plist = pnode;}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 100 "compiler_yacc.y" /* yacc.c:1646  */
    {pnode = makeParamList((yyvsp[0])->varname, (yyvsp[-1])->type);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 103 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_CONN, TYPE_NULL, NULL, (yyvsp[-1]), (yyvsp[0]), NULL, NULL, NULL, NULL);printf("Ping\n");}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 104 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 108 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 112 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_READ, TYPE_NULL, NULL, (yyvsp[-2]), NULL, NULL, NULL, NULL, NULL);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 116 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_WRITE, TYPE_NULL, NULL, (yyvsp[-2]), NULL, NULL, NULL, NULL, NULL);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_ASSIGN, TYPE_AUX, NULL, (yyvsp[-3]), (yyvsp[-1]), NULL, NULL, NULL, NULL);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 124 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_IF, TYPE_NULL, NULL, (yyvsp[-7]), (yyvsp[-4]), (yyvsp[-2]), NULL, NULL, NULL);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 125 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_IF, TYPE_NULL, NULL, (yyvsp[-5]), (yyvsp[-2]), NULL, NULL, NULL, NULL);}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 129 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_WHILE, TYPE_NULL, NULL, (yyvsp[-5]), (yyvsp[-2]), NULL, NULL, NULL, NULL);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 133 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_BREAK, TYPE_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 137 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_CONTINUE, TYPE_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 140 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 141 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_PLUS, TYPE_INT, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 142 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_MINUS, TYPE_INT, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 143 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_MUL, TYPE_INT, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 144 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_DIV, TYPE_INT, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 145 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_LT, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 146 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_LE, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 147 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_GT, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 148 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_GE, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 149 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_NE, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 150 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, NODE_EQ, TYPE_BOOL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, NULL);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 151 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 152 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 153 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(lookup((yyvsp[0])->varname)->binding, NODE_NUM, TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 154 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 157 "compiler_yacc.y" /* yacc.c:1646  */
    {struct Gsymbol *temp = lookup((yyvsp[-4])->varname);(yyval) = createTree(0, NODE_FCALL, temp->type, temp->name, NULL, NULL, NULL, NULL, NULL, (yyvsp[-2])); list = NULL;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 159 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, NODE_CONN, TYPE_NULL, NULL, (yyvsp[-2]), (yyvsp[-1]), NULL, NULL, NULL, NULL);}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 160 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 162 "compiler_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 164 "compiler_yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-1])->type != TYPE_INT)
                yyerror("Invalid array index\n");
            (yyval) = (yyvsp[-3]);
            (yyval)->index1 = (yyvsp[-1]);
            (yyval)->index2 = NULL;
        }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 172 "compiler_yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-4])->type != TYPE_INT || (yyvsp[-1])->type != TYPE_INT)
                yyerror("Invalid array index\n");
            (yyval) = (yyvsp[-6]); 
            (yyval)->index1 = (yyvsp[-4]); 
            (yyval)->index2 = (yyvsp[-1]);
        }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 180 "compiler_yacc.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            (yyval)->nodetype = NODE_PTR;
        }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1835 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 187 "compiler_yacc.y" /* yacc.c:1906  */


void yyerror(char const *s)
{
	printf("yyerror %s\n",s);
    exit(0);
}

int main(int argc, char* argv[])
{
	reg=-1;
	if(argc>1){
		fp=fopen(argv[1], "r");
		if(fp)
			yyin=fp;
	}
	target_file=fopen("test.xsm","w");
	yyparse();
	return 0;
}
