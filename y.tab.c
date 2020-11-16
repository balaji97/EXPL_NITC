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
#line 1 "exprtree.y" /* yacc.c:339  */


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define YYSTYPE tnode*

	#include "exprtree.h"
	#include "exprtree.c"

	int yylex(void);
	void yyerror(char const *s);
	extern FILE *yyin;
	

#line 83 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    NUM = 259,
    STRVAL = 260,
    START = 261,
    END = 262,
    READ = 263,
    WRITE = 264,
    ASSIGN = 265,
    DECL = 266,
    ENDDECL = 267,
    INT = 268,
    STR = 269,
    BRKP = 270,
    MAIN = 271,
    RETURN = 272,
    TYPE = 273,
    ENDTYPE = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ENDIF = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    BREAK = 282,
    CONTINUE = 283,
    REPEAT = 284,
    UNTIL = 285,
    PLUS = 286,
    MINUS = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    LT = 291,
    GT = 292,
    LE = 293,
    GE = 294,
    NE = 295,
    EQ = 296,
    AND = 297,
    OR = 298,
    NOT = 299,
    NULLSTMT = 300
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define STRVAL 260
#define START 261
#define END 262
#define READ 263
#define WRITE 264
#define ASSIGN 265
#define DECL 266
#define ENDDECL 267
#define INT 268
#define STR 269
#define BRKP 270
#define MAIN 271
#define RETURN 272
#define TYPE 273
#define ENDTYPE 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define BREAK 282
#define CONTINUE 283
#define REPEAT 284
#define UNTIL 285
#define PLUS 286
#define MINUS 287
#define MUL 288
#define DIV 289
#define MOD 290
#define LT 291
#define GT 292
#define LE 293
#define GE 294
#define NE 295
#define EQ 296
#define AND 297
#define OR 298
#define NOT 299
#define NULLSTMT 300

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

#line 224 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      52,    53,     2,     2,    49,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    32,    33,    34,    35,    36,    37,    38,
      41,    44,    45,    48,    51,    52,    55,    59,    63,    69,
      70,    73,    77,    78,    79,    90,    91,    92,   104,   105,
     108,   109,   110,   111,   112,   116,   120,   121,   124,   125,
     128,   186,   231,   289,   335,   336,   339,   348,   359,   360,
     363,   364,   367,   368,   371,   374,   375,   376,   377,   380,
     419,   420,   423,   424,   427,   427,   427,   427,   427,   428,
     429,   430,   433,   437,   442,   447,   451,   457,   460,   465,
     471,   477,   482,   489,   490,   493,   494,   495,   498,   502,
     506,   510,   514,   518,   522,   526,   530,   534,   538,   542,
     546,   550,   554,   558,   559,   560,   561,   562,   563,   567,
     572,   577,   581,   582,   587,   592,   599,   612,   620,   645,
     646,   649
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "STRVAL", "START", "END",
  "READ", "WRITE", "ASSIGN", "DECL", "ENDDECL", "INT", "STR", "BRKP",
  "MAIN", "RETURN", "TYPE", "ENDTYPE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "NE", "EQ",
  "AND", "OR", "NOT", "NULLSTMT", "'{'", "'}'", "';'", "','", "'['", "']'",
  "'('", "')'", "'&'", "'.'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "FieldDeclList", "FieldDecl", "GDeclBlock",
  "GDeclList", "GDecl", "TypeName", "Type", "GidList", "Gid", "FDefBlock",
  "FDef", "ParamList", "Param", "PType", "LDeclBlock", "LDeclList",
  "LDecl", "IdList", "MainBlock", "Body", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "Expr", "Field",
  "ArgList", "RetStmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   123,   125,    59,    44,
      91,    93,    40,    41,    38,    46
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     181,  -127,   147,    -1,  -127,    33,    47,   172,   265,     6,
     265,  -127,  -127,  -127,  -127,   220,  -127,    27,    16,    46,
      15,  -127,  -127,   265,   265,  -127,   265,  -127,    97,   148,
    -127,  -127,  -127,  -127,   -29,   160,    10,  -127,    80,   288,
    -127,  -127,   265,  -127,  -127,  -127,   -10,   102,   161,    -3,
     116,  -127,    27,   155,  -127,  -127,  -127,   109,  -127,   190,
    -127,  -127,  -127,   159,   127,  -127,    30,     3,   156,  -127,
     128,    64,  -127,   198,  -127,  -127,   170,   198,    87,   176,
    -127,   221,   179,   129,   177,  -127,  -127,   149,   238,   223,
    -127,   223,  -127,   198,  -127,   198,   184,   241,  -127,  -127,
      62,   243,  -127,   211,   200,   201,   223,   223,   198,   202,
    -127,   266,    60,  -127,  -127,    -4,   218,   219,   225,    66,
     222,   224,   307,   227,   232,   307,   285,   211,  -127,  -127,
    -127,  -127,  -127,  -127,    -2,   282,  -127,  -127,   247,   248,
     223,  -127,  -127,  -127,    91,    66,    66,   293,    93,    66,
    -127,    52,  -127,  -127,    66,   294,    66,  -127,    66,   295,
     639,   245,    66,    66,   330,  -127,  -127,   234,   296,  -127,
     298,    66,   300,  -127,  -127,  -127,   267,  -127,   315,   657,
     471,  -127,    89,   316,    61,   333,    66,    22,   344,  -127,
     364,   356,   270,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,  -127,   379,   402,   269,
     271,    66,  -127,   675,  -127,  -127,  -127,  -127,     2,    66,
     276,   272,   278,   280,   492,  -127,   747,   151,  -127,    66,
     344,   344,   364,   364,   364,   387,   387,   387,   387,   387,
     387,   772,   760,   308,   305,    66,    66,   693,  -127,    66,
      66,   513,  -127,   289,  -127,  -127,   291,    66,  -127,   534,
     307,   307,   425,   448,  -127,   711,   555,    75,  -127,    66,
     747,   292,   188,   257,   -11,   299,  -127,   334,    66,   301,
     576,    66,   307,   303,   304,  -127,  -127,    66,   597,  -127,
    -127,   618,   284,  -127,  -127,   729,   290,  -127,   312,  -127,
     313,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,     0,    25,    26,     0,     0,     0,     0,     0,
       0,    39,     9,    18,    25,     0,    20,     0,     0,     0,
       0,    12,     1,     0,     0,     7,     0,     6,     0,     0,
      38,     8,    17,    19,    30,     0,     0,    29,     0,     0,
      10,    11,     0,     5,     4,     3,     0,     0,     0,     0,
      33,    21,     0,     0,    24,    22,    23,     0,    15,     0,
       2,    48,    49,     0,     0,    45,     0,     0,     0,    36,
       0,     0,    28,     0,    13,    14,     0,     0,     0,     0,
      46,     0,     0,     0,    31,    34,    37,     0,     0,     0,
      16,     0,    44,     0,    47,     0,     0,     0,    35,    51,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,    50,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,     0,     0,    59,    41,     0,     0,
       0,    32,    58,    54,     0,     0,     0,     0,     0,     0,
      71,   108,   106,   107,     0,     0,     0,   105,     0,     0,
       0,   104,     0,     0,     0,    69,    70,     0,     0,    62,
       0,     0,     0,    61,    40,    43,     0,    55,     0,     0,
       0,   118,     0,     0,     0,     0,     0,     0,   102,   111,
     101,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
       0,     0,    60,     0,   117,    42,    56,    78,     0,     0,
       0,     0,     0,     0,     0,   116,   120,     0,   103,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,    82,     0,
       0,     0,    72,     0,    76,    77,   109,     0,   115,     0,
       0,     0,     0,     0,    81,     0,     0,     0,    75,     0,
     119,   113,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,    73,
     110,     0,     0,    84,    85,     0,     0,   114,     0,    80,
       0,    83,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,   326,  -127,   349,   341,  -127,   338,
    -127,     5,  -127,   310,   130,   103,    81,   329,  -127,    26,
    -127,   255,  -127,   164,   -78,  -120,  -126,  -127,  -127,  -127,
    -127,  -127,  -114,  -103,  -127,   281
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    20,    21,    57,    58,     8,    15,    16,
      59,     9,    36,    37,    10,    11,    64,    65,    66,    89,
     101,   102,   112,    12,   104,   127,   128,   129,   130,   131,
     132,   133,   160,   161,   227,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   169,   164,    61,    62,   167,   145,    17,   171,    28,
      61,    62,   249,   105,   261,    18,    61,    62,    19,   134,
      17,    48,   134,    49,   134,   151,   152,   153,   138,   139,
      34,   179,   180,    80,    40,   185,    19,   285,   169,    29,
     188,   169,   190,    63,   191,   184,   146,    22,   207,   208,
      69,   147,   250,   172,   154,   155,    82,   213,    51,    52,
      35,   134,   176,    81,   134,   110,   156,   157,    38,   151,
     152,   153,   224,   226,   158,   225,   159,    61,    62,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    39,   100,   177,   111,   182,   247,   154,   155,
      61,    62,   186,    91,   187,   251,   100,   147,   143,   144,
     156,   157,    54,    30,   222,   259,   172,    86,   158,   106,
     159,   107,    55,    56,   178,   278,   183,    30,   279,    30,
      70,   262,   263,    53,   140,   265,   266,    24,    26,   219,
     272,   273,   220,   270,   147,    30,   169,   169,    83,    46,
       1,    47,    87,    42,    67,   280,    74,   134,   134,    13,
      14,     4,   292,    50,   288,    68,   169,   291,    71,   134,
     134,    25,    27,   295,    31,     1,    78,    78,    78,   134,
      79,    85,    96,     2,     1,     3,     4,    43,    44,   134,
      45,   115,     2,    76,     3,     4,   116,   117,    78,     5,
     257,    73,    98,   118,   258,    77,    60,    84,   120,    88,
     282,   283,   121,   122,   115,   123,   124,   125,    90,   116,
     117,   126,    93,     1,    94,    95,   118,    97,   119,   103,
     108,   120,    32,    14,     4,   121,   122,   115,   123,   124,
     125,     1,   116,   117,   126,   109,     1,   136,   137,   118,
      99,    14,     4,   141,   120,   113,    14,     4,   121,   122,
     115,   123,   124,   125,   210,   116,   117,   126,     1,   142,
     148,   149,   118,   150,   162,   165,   163,   120,     3,     4,
     166,   121,   122,   284,   123,   124,   125,   115,   168,   173,
     126,    54,   116,   117,   174,   175,   181,   189,   192,   118,
     172,    55,    56,   214,   120,   212,   211,   298,   121,   122,
     115,   123,   124,   125,   215,   116,   117,   126,   216,   221,
     229,   245,   118,   246,   252,   253,   254,   120,   255,   260,
     261,   121,   122,   115,   123,   124,   125,   268,   116,   117,
     126,   269,   281,   300,   287,   118,    41,   286,    23,   289,
     120,   293,   294,    33,   209,   122,   114,   123,   124,   125,
     301,   302,    72,   126,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   223,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     198,   199,   200,   201,   202,   203,    75,    92,   170,   228,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       0,     0,   243,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,     0,     0,     0,     0,     0,
       0,     0,   218,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,   256,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,     0,     0,     0,
       0,     0,     0,     0,   267,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,     0,     0,
       0,     0,     0,     0,     0,   271,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     0,
       0,     0,     0,     0,     0,     0,   277,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,   290,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     0,     0,     0,     0,     0,     0,     0,   296,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,     0,     0,     0,     0,     0,   297,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,     0,     0,   206,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     0,     0,     0,     0,   217,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     0,
       0,     0,     0,   248,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,     0,     0,     0,
       0,   264,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,     0,     0,     0,     0,   276,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,     0,     0,   299,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203
};

static const yytype_int16 yycheck[] =
{
     103,   127,   122,    13,    14,   125,    10,     2,    10,     3,
      13,    14,    10,    91,    25,    16,    13,    14,     3,   122,
      15,    50,   125,    52,   127,     3,     4,     5,   106,   107,
       3,   145,   146,     3,    19,   149,     3,    48,   164,    33,
     154,   167,   156,    53,   158,   148,    50,     0,   162,   163,
      53,    55,    50,    55,    32,    33,    53,   171,    48,    49,
      33,   164,   140,    33,   167,     3,    44,    45,    52,     3,
       4,     5,   186,   187,    52,    53,    54,    13,    14,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    46,    88,     3,    33,     3,   211,    32,    33,
      13,    14,    50,    77,    52,   219,   101,    55,    48,    49,
      44,    45,     3,    10,    53,   229,    55,    53,    52,    93,
      54,    95,    13,    14,    33,    50,    33,    24,    53,    26,
      49,   245,   246,    53,   108,   249,   250,     7,     8,    50,
     260,   261,    53,   257,    55,    42,   272,   273,    67,    52,
       3,     3,    71,    23,    52,   269,    47,   260,   261,    12,
      13,    14,   282,     3,   278,     4,   292,   281,    52,   272,
     273,     7,     8,   287,    10,     3,    49,    49,    49,   282,
      53,    53,    53,    11,     3,    13,    14,    23,    24,   292,
      26,     3,    11,     3,    13,    14,     8,     9,    49,    18,
      49,    46,    53,    15,    53,    46,    42,    51,    20,    11,
      22,    23,    24,    25,     3,    27,    28,    29,    48,     8,
       9,    33,    46,     3,     3,    46,    15,    50,    17,     6,
      46,    20,    12,    13,    14,    24,    25,     3,    27,    28,
      29,     3,     8,     9,    33,     4,     3,    47,    47,    15,
      12,    13,    14,    51,    20,    12,    13,    14,    24,    25,
       3,    27,    28,    29,    30,     8,     9,    33,     3,     3,
      52,    52,    15,    48,    52,    48,    52,    20,    13,    14,
      48,    24,    25,    26,    27,    28,    29,     3,     3,     7,
      33,     3,     8,     9,    47,    47,     3,     3,     3,    15,
      55,    13,    14,     3,    20,     7,    10,    23,    24,    25,
       3,    27,    28,    29,    47,     8,     9,    33,     3,     3,
      50,    52,    15,    52,    48,    53,    48,    20,    48,    21,
      25,    24,    25,     3,    27,    28,    29,    48,     8,     9,
      33,    50,    50,    53,    10,    15,    20,    48,     7,    48,
      20,    48,    48,    15,    24,    25,   101,    27,    28,    29,
      48,    48,    52,    33,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    53,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      36,    37,    38,    39,    40,    41,    57,    78,   127,    53,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    53,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    48,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    13,    14,    18,    57,    58,    63,    67,
      70,    71,    79,    12,    13,    64,    65,    67,    16,     3,
      59,    60,     0,    63,    70,    79,    70,    79,     3,    33,
      71,    79,    12,    65,     3,    33,    68,    69,    52,    46,
      19,    60,    70,    79,    79,    79,    52,     3,    50,    52,
       3,    48,    49,    53,     3,    13,    14,    61,    62,    66,
      79,    13,    14,    53,    72,    73,    74,    52,     4,    53,
      72,    52,    69,    46,    47,    62,     3,    46,    49,    53,
       3,    33,    53,    72,    51,    53,    53,    72,    11,    75,
      48,    75,    73,    46,     3,    46,    53,    50,    53,    12,
      67,    76,    77,     6,    80,    80,    75,    75,    46,     4,
       3,    33,    78,    12,    77,     3,     8,     9,    15,    17,
      20,    24,    25,    27,    28,    29,    33,    81,    82,    83,
      84,    85,    86,    87,    89,    91,    47,    47,    80,    80,
      75,    51,     3,    48,    49,    10,    50,    55,    52,    52,
      48,     3,     4,     5,    32,    33,    44,    45,    52,    54,
      88,    89,    52,    52,    81,    48,    48,    81,     3,    82,
      91,    10,    55,     7,    47,    47,    80,     3,    33,    88,
      88,     3,     3,    33,    89,    88,    50,    52,    88,     3,
      88,    88,     3,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    48,    88,    88,    24,
      30,    10,     7,    88,     3,    47,     3,    48,    51,    50,
      53,     3,    53,    53,    88,    53,    88,    90,    53,    50,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    53,    53,    52,    52,    88,    48,    10,
      50,    88,    48,    53,    48,    48,    51,    49,    53,    88,
      21,    25,    88,    88,    48,    88,    88,    51,    48,    50,
      88,    51,    81,    81,    53,    53,    48,    51,    50,    53,
      88,    50,    22,    23,    26,    48,    48,    10,    88,    48,
      51,    88,    81,    48,    48,    88,    51,    51,    23,    48,
      53,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    59,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    78,    78,    78,    78,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    84,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       3,     2,     1,     4,     2,     1,     3,     3,     2,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     7,     2,     4,     5,     3,     4,     2,     1,
       9,     8,    10,     9,     3,     1,     2,     3,     1,     1,
       3,     2,     2,     1,     3,     3,     4,     1,     2,     8,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     5,     8,    11,     6,     5,     5,     4,     7,
      10,     5,     4,    10,     8,     8,     7,     7,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     4,
       7,     2,     2,     5,     8,     4,     3,     3,     3,     3,
       1,     3
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
        case 10:
#line 41 "exprtree.y" /* yacc.c:1646  */
    {printTypeTable();}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 48 "exprtree.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-3])->varname, Fhead->fieldIndex, Fhead);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 51 "exprtree.y" /* yacc.c:1646  */
    {Fhead = FAppend(Fentry, Fhead);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 52 "exprtree.y" /* yacc.c:1646  */
    {Fhead = Fentry;}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "exprtree.y" /* yacc.c:1646  */
    {Fentry = FCreate((yyvsp[-1])->varname, declType);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 59 "exprtree.y" /* yacc.c:1646  */
    {
			evaluate();
			binding=1;
		}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "exprtree.y" /* yacc.c:1646  */
    {
			evaluate();
			binding=1;
		}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "exprtree.y" /* yacc.c:1646  */
    {declType=TLookup(inttype);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "exprtree.y" /* yacc.c:1646  */
    {declType=TLookup(strtype);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "exprtree.y" /* yacc.c:1646  */
    { 
        if(TLookup((yyvsp[0])->varname) == NULL)
        {
            declType = TLookup(temptype);
        }
        else
            declType=TLookup((yyvsp[0])->varname);
    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "exprtree.y" /* yacc.c:1646  */
    {declType=TLookup(inttype);}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "exprtree.y" /* yacc.c:1646  */
    {declType=TLookup(strtype);}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 93 "exprtree.y" /* yacc.c:1646  */
    { 
        if(TLookup((yyvsp[0])->varname) == NULL)
        {
            printf("Undeclared type %s\n", (yyvsp[0])->varname);
            exit(1);
        }
        declType=TLookup((yyvsp[0])->varname);
    }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0])->varname, declType, 1, 1, NODE_ID, NULL);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 109 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->varname, declType, (yyvsp[-1])->val, 1, NODE_ARRAY, NULL);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 110 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-6])->varname, declType, (yyvsp[-4])->val, (yyvsp[-1])->val, NODE_MATRIX, NULL);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 111 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0])->varname, declType, 1, 1, NODE_PTR, NULL);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 112 "exprtree.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3])->varname, declType, 0, 0, NODE_FUNC, Phead);
						Phead=Ptail=NULL;
					}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 116 "exprtree.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3])->varname, declType, 0, 0, NODE_FUNC, Phead);	
						Phead=Ptail=NULL;
					}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 120 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-2])->varname, declType, 0, 0, NODE_FUNC, NULL);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 121 "exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-2])->varname, declType, 0, 0, NODE_FUNC, NULL);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 128 "exprtree.y" /* yacc.c:1646  */
    {
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp1, *Ptemp2;
			functype=declType;
			binding=1;

			Gtemp=GLookup((yyvsp[-7])->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", (yyvsp[-7])->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", (yyvsp[-7])->varname);
				exit(1);
			}
			Gtemp->size1--;
			(yyvsp[-7])->Lentry=Lhead;

			Ptemp1=Phead;
			Ptemp2=Gtemp->paramlist;

			while(Ptemp1!=NULL && Ptemp2!=NULL){
				if(Ptemp1->type!=Ptemp2->type || strcmp(Ptemp1->name, Ptemp2->name) || Ptemp1->nodetype!=Ptemp2->nodetype){
					printf("Incorrect Parameter List\n");
					exit(1);
				}
				Ptemp1=Ptemp1->next;
				Ptemp2=Ptemp2->next;
			}

			if(Ptemp1!=NULL || Ptemp2!=NULL){
				printf("Incorrect Parameter List\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen((yyvsp[-1]));

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 186 "exprtree.y" /* yacc.c:1646  */
    {
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=declType;
			binding=1;

			Gtemp=GLookup((yyvsp[-6])->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", (yyvsp[-6])->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", (yyvsp[-6])->varname);
				exit(1);
			}
			Gtemp->size1--;
			(yyvsp[-6])->Lentry=Lhead;

			if(Gtemp->paramlist!=NULL){
				printf("Parameter List is not NULLs\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen((yyvsp[-1]));

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 231 "exprtree.y" /* yacc.c:1646  */
    {
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp1, *Ptemp2;
			functype=declType;
			binding=1;

			Gtemp=GLookup((yyvsp[-7])->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", (yyvsp[-7])->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", (yyvsp[-7])->varname);
				exit(1);
			}
			Gtemp->size1--;
			(yyvsp[-7])->Lentry=Lhead;

			Ptemp1=Phead;
			Ptemp2=Gtemp->paramlist;

			while(Ptemp1!=NULL && Ptemp2!=NULL){
				if(Ptemp1->type!=Ptemp2->type || strcmp(Ptemp1->name, Ptemp2->name) || Ptemp1->nodetype!=Ptemp2->nodetype){
					printf("Incorrect Parameter List\n");
					exit(1);
				}
				Ptemp1=Ptemp1->next;
				Ptemp2=Ptemp2->next;
			}

			if(Ptemp1!=NULL || Ptemp2!=NULL){
				printf("Incorrect Parameter List\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen((yyvsp[-1]));

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 289 "exprtree.y" /* yacc.c:1646  */
    {
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=declType;
			binding=1;

			Gtemp=GLookup((yyvsp[-6])->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", (yyvsp[-6])->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", (yyvsp[-6])->varname);
				exit(1);
			}
			Gtemp->size1--;
			(yyvsp[-6])->Lentry=Lhead;

			if(Gtemp->paramlist!=NULL){
				printf("Parameter List is not NULLs\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen((yyvsp[-1]));

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 339 "exprtree.y" /* yacc.c:1646  */
    {
			struct Paramstruct *Ptemp;
			Ptemp=PLookup((yyvsp[0])->varname);
			if(Ptemp!=NULL){
				printf("Multiple variable declaration: %s\n", (yyvsp[0])->varname);
				exit(1);
			}
			PInstall((yyvsp[0])->varname, PdeclType, NODE_ID);
		}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 348 "exprtree.y" /* yacc.c:1646  */
    {
			struct Paramstruct *Ptemp;
			Ptemp=PLookup((yyvsp[0])->varname);
			if(Ptemp!=NULL){
				printf("Multiple variable declaration: %s\n", (yyvsp[0])->varname);
				exit(1);
			}
			PInstall((yyvsp[0])->varname, PdeclType, NODE_PTR);
		}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 359 "exprtree.y" /* yacc.c:1646  */
    {PdeclType=TLookup(inttype);}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 360 "exprtree.y" /* yacc.c:1646  */
    {PdeclType=TLookup(strtype);}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 374 "exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname, declType, NODE_ID);}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 375 "exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname, declType, NODE_PTR);}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 376 "exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname, declType, NODE_ID);}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 377 "exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname, declType, NODE_PTR);}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 380 "exprtree.y" /* yacc.c:1646  */
    {
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=TLookup(inttype);
			binding=1;

			Gtemp=Ghead;
			while(Gtemp!=NULL){
				if(Gtemp->size1==0){
					printf("Function not declared: %s\n", Gtemp->name);
					exit(1);
				}
				Gtemp=Gtemp->next;
			}

			fprintf(target_file, "MAIN:\n");
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen((yyvsp[-1]));

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_CONN, (yyvsp[-2]), (yyvsp[-1]), NULL);}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 420 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_CONN, (yyvsp[-1]), NULL, NULL);}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 423 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_CONN, (yyvsp[-1]), (yyvsp[0]), NULL);}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 424 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 427 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 428 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_BREAK, NULL, NULL, NULL);}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 429 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_CONTINUE, NULL, NULL, NULL);}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 430 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_BRKP, NULL, NULL, NULL);}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 433 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-2]), NODE_ID);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_READ, (yyvsp[-2]), NULL, NULL);
			}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 437 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-5]), NODE_ARRAY);
				typeCheck((yyvsp[-3])->type, NULL, NODE_ARRAY);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_READ_ARRAY, (yyvsp[-5]), (yyvsp[-3]), NULL);
			}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 442 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-8]), NODE_MATRIX);
				typeCheck((yyvsp[-6])->type, (yyvsp[-3])->type, NODE_MATRIX);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_READ_MATRIX, (yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]));
			}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 447 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-2]), NODE_PTR);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_READ_PTR, (yyvsp[-2]), NULL, NULL);
			}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 452 "exprtree.y" /* yacc.c:1646  */
    {
        (yyval) = createTree(0, TLookup(nulltype), NULL, NODE_READ_FIELD, (yyvsp[-2]), NULL, NULL);
    }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 457 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(nulltype), NULL,  NODE_WRITE, (yyvsp[-2]), NULL, NULL);}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 460 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-3]), NODE_ID);
				typeCheck((yyvsp[-3])->type, (yyvsp[-1])->type, NODE_ASSIGN);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN, (yyvsp[-3]), (yyvsp[-1]), NULL); 
			}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 465 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-6]), NODE_ARRAY);
				typeCheck((yyvsp[-4])->type, NULL, NODE_ARRAY);
				typeCheck((yyvsp[-6])->type, (yyvsp[-1])->type, NODE_ASSIGN);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_ARRAY, (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
			}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 471 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-9]), NODE_MATRIX);
				typeCheck((yyvsp[-7])->type, (yyvsp[-4])->type, NODE_MATRIX);
				typeCheck((yyvsp[-9])->type, (yyvsp[-1])->type, NODE_ASSIGN);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_MATRIX, (yyvsp[-9]), createTree(0, 0, NULL, NODE_CONN, (yyvsp[-7]), (yyvsp[-4]), NULL),(yyvsp[-1]));
			}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 477 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-3]), NODE_PTR);
				typeCheck((yyvsp[-3])->type, (yyvsp[-1])->type, NODE_ASSIGN);
				(yyval)=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_PTR, (yyvsp[-3]), (yyvsp[-1]), NULL);
			}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 483 "exprtree.y" /* yacc.c:1646  */
    {
        typeCheck((yyvsp[-3])->type, (yyvsp[-1])->type, NODE_ASSIGN);
        (yyval) = createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_FIELD, (yyvsp[-3]), (yyvsp[-1]), NULL);
    }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 489 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_ELIF, (yyvsp[-7]), (yyvsp[-4]), (yyvsp[-2]));}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 490 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_IF, (yyvsp[-5]), (yyvsp[-2]), NULL);}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 493 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_WHILE, (yyvsp[-5]), (yyvsp[-2]), NULL);}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 494 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_DO_WHILE, (yyvsp[-5]), (yyvsp[-2]), NULL);}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 495 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_REPEAT, (yyvsp[-5]), (yyvsp[-2]), NULL);}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 498 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_PLUS);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_PLUS, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 502 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_MINUS);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_MINUS, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 506 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_MUL);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_MUL, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 510 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_DIV);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_DIV, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 514 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_MOD);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_MOD, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 518 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_LT);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_LT, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 522 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_GT);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_GT, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 526 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_LE);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_LE, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 530 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_GE);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_GE, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 534 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_NE);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_NE, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 538 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_EQ);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_EQ, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 542 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_AND);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_AND, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 546 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-2])->type, (yyvsp[0])->type, NODE_OR);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_OR, (yyvsp[-2]), (yyvsp[0]), NULL);
			}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 550 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[0])->type, TLookup(inttype), NODE_NOT);
				(yyval)=createTree(0, TLookup(booltype), NULL, NODE_NOT, (yyvsp[0]), NULL, NULL);
			}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 554 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck(TLookup(inttype), (yyvsp[0])->type, NODE_MINUS);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_NEG, (yyvsp[0]), NULL, NULL);
			}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 558 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 559 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 560 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = createTree(0, TLookup(nulltype), NULL, NODE_NULL, NULL, NULL, NULL);}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 561 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 562 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 563 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[0]), NODE_ID);
				(yyval)=(yyvsp[0]);
			}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 567 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-3]), NODE_ARRAY);
				typeCheck((yyvsp[-1])->type, NULL, NODE_ARRAY);
				(yyval)=createTree(0, (yyvsp[-3])->type, NULL, NODE_ARRAY, (yyvsp[-3]), (yyvsp[-1]), NULL);
			}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 572 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-6]), NODE_MATRIX);
				typeCheck((yyvsp[-4])->type, (yyvsp[-1])->type, NODE_MATRIX);
				(yyval)=createTree(0, (yyvsp[-6])->type, NULL, NODE_MATRIX, (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
			}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 577 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[0]), NODE_PTR);
				(yyval)=createTree(0, (yyvsp[0])->type, NULL, NODE_PTR, (yyvsp[0]), NULL, NULL);
			}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 581 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, TLookup(inttype), NULL, NODE_REF, (yyvsp[0]), NULL, NULL);}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 582 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-3]), NODE_REF_ARRAY);
				typeCheck((yyvsp[-1])->type, NULL, NODE_ARRAY);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_REF_ARRAY, (yyvsp[-3]), (yyvsp[-1]), NULL);
			}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 587 "exprtree.y" /* yacc.c:1646  */
    {
				idCheck((yyvsp[-6]), NODE_REF_MATRIX);
				typeCheck((yyvsp[-4])->type, (yyvsp[-1])->type, NODE_MATRIX);
				(yyval)=createTree(0, TLookup(inttype), NULL, NODE_REF_MATRIX, (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
			}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 592 "exprtree.y" /* yacc.c:1646  */
    {
				struct Gsymbol *Gtemp;
				idCheck((yyvsp[-3]), NODE_FUNC);
				Gtemp=GLookup((yyvsp[-3])->varname);
				(yyval)=createTree(0, (yyvsp[-3])->type, NULL, NODE_FUNC, (yyvsp[-3]), (yyvsp[-1]), NULL);
				(yyval)->arglist=(yyvsp[-1]);
			}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 599 "exprtree.y" /* yacc.c:1646  */
    {
				struct Gsymbol *Gtemp;
				idCheck((yyvsp[-2]), NODE_FUNC);
				Gtemp=GLookup((yyvsp[-2])->varname);
				if(Gtemp->paramlist!=NULL){
					printf("Parameter List is not NULL: %s\n", (yyvsp[-2])->varname);
					exit(1);
				}
				(yyval)=createTree(0, (yyvsp[-2])->type, NULL, NODE_FUNC, (yyvsp[-2]), NULL, NULL);
				(yyval)->arglist=NULL;
			}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 613 "exprtree.y" /* yacc.c:1646  */
    {
            struct Fieldlist *tempfield = getField(Fieldtail->type, (yyvsp[0])->varname);
            Fieldtail->ptr1 = createTree(0, tempfield->type, (yyvsp[0])->varname, NODE_FIELD, NULL, NULL, NULL);
            Fieldtail = Fieldtail->ptr1;
            (yyval) = (yyvsp[-2]);
            (yyval)->type = Fieldtail->type;
        }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 621 "exprtree.y" /* yacc.c:1646  */
    {
            struct Gsymbol *Gtemp = GLookup((yyvsp[-2])->varname);
            struct Lsymbol *Ltemp = LLookup((yyvsp[-2])->varname);
            struct Paramstruct *Ptemp = PLookup((yyvsp[-2])->varname);
            
            struct Typetable *type = NULL;
            if(Ltemp != NULL)
                type = Ltemp->type;
            else if(Ptemp != NULL)
                type = Ptemp->type;
            else if(Gtemp != NULL)
                type = Gtemp->type;
            else
            {
                printf("Undeclared object %s\n", (yyvsp[-2])->varname);
                exit(1);
            }
            struct Fieldlist *tempfield = getField(type, (yyvsp[0])->varname);
            Fieldtail = createTree(0, tempfield->type, (yyvsp[0])->varname, NODE_FIELD, NULL, NULL, NULL);
            (yyval) = createTree(0, Fieldtail->type, (yyvsp[-2])->varname, NODE_FIELD, Fieldtail, NULL, NULL);
            
        }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 645 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_ARG, (yyvsp[0]), (yyvsp[-2]), NULL);}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 646 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=createTree(0, 0, NULL, NODE_ARG, (yyvsp[0]), NULL, NULL);}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 649 "exprtree.y" /* yacc.c:1646  */
    {
				typeCheck((yyvsp[-1])->type, functype, NODE_ASSIGN);
				(yyval)=createTree(0, 0, NULL, NODE_RET, (yyvsp[-1]), NULL, NULL);
			}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2584 "y.tab.c" /* yacc.c:1646  */
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
#line 655 "exprtree.y" /* yacc.c:1906  */


void yyerror(char const *s){
	printf("yyerror %s\n",s);
}

int main(int argc, char* argv[]){
	if(argc>1){
		fp=fopen(argv[1], "r");
		if(fp)
			yyin=fp;
	}
	target_file=fopen("exprtree.xsm","w");
    TypeTableCreate();
	yyparse();
	return 0;
}
