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
#line 1 "yacc.y" /* yacc.c:339  */


#include <iostream>
#include "symbolTab.h"
#include "lex.yy.cpp"
#include "CodeGenerator.hpp"

#define Trace(t) if (Opt_P) cout << "TRACE => " << t << endl;

int Opt_P = 1;
void yyerror(string s);

SymbolTables symbol_tables;
CodeGenerator Code_Generator;

// Insert ID in current table (tables[top]), return 1 if succedd.
bool insertTableEntry(SymInfo*);
// check now is in main
bool is_Main_Block = false;
bool isReturn = false;
// Variable stack index
int stackVarID = 0;


#line 91 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    LE = 258,
    GE = 259,
    EQ = 260,
    NEQ = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    ASSIGN = 265,
    BEGINN = 266,
    BOOLEAN = 267,
    BREAK = 268,
    CHARACTER = 269,
    CASE = 270,
    CONTINUE = 271,
    CONSTANT = 272,
    DECLARE = 273,
    DO = 274,
    ELSE = 275,
    END = 276,
    EXIT = 277,
    FLOAT = 278,
    FOR = 279,
    IF = 280,
    IN = 281,
    INTEGER = 282,
    LOOP = 283,
    PRINT = 284,
    PRINTLN = 285,
    PROCEDURE = 286,
    PROGRAM = 287,
    RETURN = 288,
    STRING = 289,
    WHILE = 290,
    READ = 291,
    THEN = 292,
    CONST_INT = 293,
    CONST_FLOAT = 294,
    CONST_BOOL = 295,
    CONST_STR = 296,
    ID = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define LE 258
#define GE 259
#define EQ 260
#define NEQ 261
#define AND 262
#define OR 263
#define NOT 264
#define ASSIGN 265
#define BEGINN 266
#define BOOLEAN 267
#define BREAK 268
#define CHARACTER 269
#define CASE 270
#define CONTINUE 271
#define CONSTANT 272
#define DECLARE 273
#define DO 274
#define ELSE 275
#define END 276
#define EXIT 277
#define FLOAT 278
#define FOR 279
#define IF 280
#define IN 281
#define INTEGER 282
#define LOOP 283
#define PRINT 284
#define PRINTLN 285
#define PROCEDURE 286
#define PROGRAM 287
#define RETURN 288
#define STRING 289
#define WHILE 290
#define READ 291
#define THEN 292
#define CONST_INT 293
#define CONST_FLOAT 294
#define CONST_BOOL 295
#define CONST_STR 296
#define ID 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "yacc.y" /* yacc.c:355  */

    int 	ival;
    float 	fval;
    bool    bval;

    // pointer use *$
    string *sval;

    // Non-terminal type
    _Data_type dataType;
    Data *dataValue;

    SymInfo *func_arg;
    vector<SymInfo*>* func_args;
    vector<Data*>* func_call;

#line 234 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      54,    55,    47,    45,    57,    46,    58,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    50,
      43,     2,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    82,    74,    99,   100,   103,   104,   108,
     108,   112,   120,   127,   150,   164,   183,   194,   198,   202,
     206,   213,   214,   219,   232,   248,   218,   260,   274,   259,
     287,   292,   298,   304,   312,   318,   330,   331,   335,   336,
     337,   338,   339,   344,   382,   421,   420,   436,   435,   449,
     456,   462,   471,   475,   491,   498,   539,   565,   585,   614,
     643,   669,   695,   716,   750,   782,   814,   846,   878,   910,
     926,   948,   973,   979,   985,   991,  1000,  1018,  1043,  1048,
    1054,  1061,  1067,  1060,  1076,  1076,  1081,  1080,  1097,  1096,
    1101,  1106,  1110,  1105,  1124,  1123
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LE", "GE", "EQ", "NEQ", "AND", "OR",
  "NOT", "ASSIGN", "BEGINN", "BOOLEAN", "BREAK", "CHARACTER", "CASE",
  "CONTINUE", "CONSTANT", "DECLARE", "DO", "ELSE", "END", "EXIT", "FLOAT",
  "FOR", "IF", "IN", "INTEGER", "LOOP", "PRINT", "PRINTLN", "PROCEDURE",
  "PROGRAM", "RETURN", "STRING", "WHILE", "READ", "THEN", "CONST_INT",
  "CONST_FLOAT", "CONST_BOOL", "CONST_STR", "ID", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "';'", "':'", "'['", "']'", "'('", "')'",
  "'%'", "','", "'.'", "$accept", "program", "$@1", "$@2", "declartion",
  "var_const_decs", "var_const_dec", "const_dec", "var_dec", "type",
  "procedure_decs", "procedure_dec", "$@3", "$@4", "$@5", "$@6", "$@7",
  "return_type", "formal_args", "arg", "statements", "statement",
  "simple_statement", "$@8", "$@9", "expression", "literal_const",
  "function_invocation", "comma_separated_expression", "block", "$@10",
  "$@11", "block_or_simple_statement", "condition", "$@12", "else", "$@13",
  "loop", "$@14", "$@15", "$@16", YY_NULLPTR
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
     295,   296,   297,    60,    62,    43,    45,    42,    47,   298,
      59,    58,    91,    93,    40,    41,    37,    44,    46
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -14,     5,  -117,  -117,    -3,   -11,   -10,    -6,  -117,
     -11,  -117,  -117,    20,    21,   -10,   490,   499,  -117,   -27,
    -117,  -117,   490,  -117,  -117,  -117,  -117,   -30,   490,   490,
     118,  -117,  -117,  -117,    10,  -117,  -117,  -117,     2,    -4,
       9,  -117,   516,   315,   490,   490,    11,   132,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
    -117,   490,   490,    -4,   490,  -117,    27,  -117,    29,    -3,
      15,   490,  -117,  -117,   463,  -117,    30,    -1,    63,    65,
     516,  -117,    39,  -117,  -117,  -117,   138,    72,    32,  -117,
      37,    37,    37,    37,   315,   450,    37,    37,   -31,   -31,
      11,    11,   444,   192,    81,   206,    41,    45,    42,    50,
      96,    67,   220,   490,   490,  -117,   266,   490,    60,   490,
     490,  -117,    61,  -117,  -117,  -117,   490,  -117,  -117,   490,
    -117,    62,    -4,    59,    29,   516,   101,  -117,   280,   294,
    -117,   444,  -117,   348,   362,   516,   109,  -117,   376,  -117,
    -117,  -117,  -117,   110,    94,   524,  -117,  -117,   105,  -117,
     124,  -117,   106,  -117,    -3,    97,    91,     8,  -117,  -117,
     130,   524,   490,   131,  -117,   142,  -117,    98,  -117,   133,
     134,   430,   108,   516,   139,   129,   524,   144,   143,  -117,
    -117,   149,   147,   117,  -117,   123,   140,   151,   152,   164,
    -117,  -117,  -117,  -117,  -117,   172,   524,   161,   183,   155,
     178,  -117,   157,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     6,     8,    22,     0,     5,
       8,     9,    10,     0,     0,    22,     0,     0,     7,    31,
       3,    21,     0,    72,    73,    75,    74,    55,     0,     0,
       0,    53,    54,    20,     0,    18,    17,    19,     0,     0,
       0,    27,     6,    69,     0,    80,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    14,     0,    30,    34,     6,
       0,     0,    45,    47,     0,    91,     0,    76,     0,     0,
       6,    38,     0,    39,    40,    41,     0,    78,     0,    52,
      64,    66,    67,    68,    70,    71,    63,    65,    60,    61,
      58,    59,    62,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,    81,     0,    36,    42,    56,    80,    77,    12,     0,
      13,     0,     0,    31,    34,     6,     0,    86,     0,     0,
      50,    92,    49,     0,     0,     6,     0,    79,     0,    16,
      35,    24,    32,     0,     0,     6,    46,    48,     0,    43,
       0,    82,     0,    11,     6,     0,     0,     0,    85,    84,
      90,     6,     0,     0,     4,     0,    28,     0,    88,     0,
       0,     0,     0,     6,     0,     0,     6,     0,     0,    44,
      83,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      87,    93,    25,    29,    94,     0,     6,     0,     0,     0,
       0,    26,     0,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,  -117,    -5,   198,  -117,  -117,  -117,   -37,
     200,  -117,  -117,  -117,  -117,  -117,  -117,    83,    84,  -117,
     -77,  -117,  -105,  -117,  -117,   -15,  -117,   -32,    93,   -98,
    -117,  -117,  -116,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    42,    78,     9,    10,    11,    12,    38,
      14,    15,    40,   164,   205,    69,   184,    41,   108,   109,
      79,    80,    81,   113,   114,    87,    31,    32,    88,    83,
     145,   173,   170,    84,   155,   179,   186,    85,   117,   158,
     206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    30,    67,   123,    16,     4,    39,    43,    33,   119,
      82,     1,    64,    46,    47,     6,    58,    59,   119,    35,
      62,    13,    44,    36,    45,    61,   104,   -23,     3,    86,
      37,     8,    20,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    17,   102,   103,    82,   105,
     168,   120,    65,    45,    66,   180,   112,   169,   153,   116,
     120,    63,    19,    68,   110,   106,   168,    61,   161,   111,
     194,   107,   118,   169,   121,    48,    49,    50,    51,    52,
      53,   168,    56,    57,    58,    59,   122,   127,   169,   124,
     208,   129,    39,    61,   131,   150,   132,   133,   138,   139,
     134,   168,   141,    82,   143,   144,   191,   135,   169,   136,
     142,   146,   149,    82,   148,    54,    55,    56,    57,    58,
      59,    48,    49,    50,    51,    52,    53,   154,    61,   126,
     162,   165,   166,   171,   172,    48,    49,    50,    51,    52,
      53,    48,    49,    50,    51,    52,    53,   176,   174,   177,
     178,    82,   182,   183,   187,   188,   185,   181,   190,   175,
     192,    54,    55,    56,    57,    58,    59,   193,    60,   195,
     197,   196,   199,   200,    61,    54,    55,    56,    57,    58,
      59,    54,    55,    56,    57,    58,    59,    89,    61,   198,
     201,   125,   204,   207,    61,    48,    49,    50,    51,    52,
      53,   202,   203,   209,   210,   211,   212,   213,    18,    48,
      49,    50,    51,    52,    53,    21,   151,     0,   152,   147,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,     0,   128,     0,     0,     0,     0,     0,    61,    54,
      55,    56,    57,    58,    59,     0,   130,   137,     0,     0,
       0,     0,    61,    54,    55,    56,    57,    58,    59,    48,
      49,    50,    51,    52,    53,     0,    61,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,     0,   140,     0,    48,    49,
      50,    51,    61,    54,    55,    56,    57,    58,    59,     0,
     156,     0,     0,     0,     0,     0,    61,    54,    55,    56,
      57,    58,    59,     0,   157,     0,     0,     0,     0,     0,
      61,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,     0,    48,    49,    50,    51,    52,
      53,    61,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,     0,   159,     0,
       0,     0,     0,     0,    61,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,   160,     0,     0,    61,    54,
      55,    56,    57,    58,    59,     0,   163,     0,     0,     0,
       0,     0,    61,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    54,    55,    56,    57,    58,    59,     0,
     189,     0,     0,     0,     0,     0,    61,    54,    55,    56,
      57,    58,    59,    54,    55,    56,    57,    58,    59,    22,
      61,    23,    24,    25,    26,    27,    61,     0,     0,    28,
       0,    33,     0,   115,     0,     0,    34,    29,     0,     0,
       0,     0,    35,     0,     0,     0,    36,     0,    23,    24,
      25,    26,    27,    37,     6,     0,    28,   -37,     0,     0,
      70,    71,     6,     0,    29,    72,    73,     0,     0,    74,
       0,    75,    76,    72,    73,     0,     0,    74,    77,     0,
      76,     0,     0,     0,     0,     0,   167
};

static const yytype_int16 yycheck[] =
{
       5,    16,    39,    80,    10,     0,    33,    22,    12,    10,
      42,    32,    10,    28,    29,    18,    47,    48,    10,    23,
      10,    31,    52,    27,    54,    56,    63,    54,    42,    44,
      34,    42,    11,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    51,    61,    62,    80,    64,
     155,    52,    50,    54,    52,   171,    71,   155,   135,    74,
      52,    51,    42,    54,    69,    38,   171,    56,   145,    54,
     186,    42,    42,   171,    11,     3,     4,     5,     6,     7,
       8,   186,    45,    46,    47,    48,    21,    55,   186,    50,
     206,    10,    33,    56,    53,   132,    51,    55,   113,   114,
      50,   206,   117,   135,   119,   120,   183,    11,   206,    42,
      50,    50,    50,   145,   129,    43,    44,    45,    46,    47,
      48,     3,     4,     5,     6,     7,     8,    26,    56,    57,
      21,    21,    38,    28,    10,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    50,    42,    58,
      20,   183,    21,    11,    21,    21,    58,   172,    50,   164,
      21,    43,    44,    45,    46,    47,    48,    38,    50,    25,
      21,    28,    55,    50,    56,    43,    44,    45,    46,    47,
      48,    43,    44,    45,    46,    47,    48,    55,    56,    42,
      50,    53,    28,    21,    56,     3,     4,     5,     6,     7,
       8,    50,    50,    42,    21,    50,    28,    50,    10,     3,
       4,     5,     6,     7,     8,    15,   133,    -1,   134,   126,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    43,
      44,    45,    46,    47,    48,    -1,    50,    37,    -1,    -1,
      -1,    -1,    56,    43,    44,    45,    46,    47,    48,     3,
       4,     5,     6,     7,     8,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    -1,    50,    -1,     3,     4,
       5,     6,    56,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      56,     3,     4,     5,     6,     7,     8,    -1,    43,    44,
      45,    46,    47,    48,    -1,     3,     4,     5,     6,     7,
       8,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    43,
      44,    45,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    56,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    43,    44,    45,
      46,    47,    48,    43,    44,    45,    46,    47,    48,     9,
      56,    38,    39,    40,    41,    42,    56,    -1,    -1,    46,
      -1,    12,    -1,    50,    -1,    -1,    17,    54,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    -1,    38,    39,
      40,    41,    42,    34,    18,    -1,    46,    21,    -1,    -1,
      24,    25,    18,    -1,    54,    29,    30,    -1,    -1,    33,
      -1,    35,    36,    29,    30,    -1,    -1,    33,    42,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    60,    42,     0,    61,    18,    63,    42,    64,
      65,    66,    67,    31,    69,    70,    10,    51,    64,    42,
      11,    69,     9,    38,    39,    40,    41,    42,    46,    54,
      84,    85,    86,    12,    17,    23,    27,    34,    68,    33,
      71,    76,    62,    84,    52,    54,    84,    84,     3,     4,
       5,     6,     7,     8,    43,    44,    45,    46,    47,    48,
      50,    56,    10,    51,    10,    50,    52,    68,    54,    74,
      24,    25,    29,    30,    33,    35,    36,    42,    63,    79,
      80,    81,    86,    88,    92,    96,    84,    84,    87,    55,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    68,    84,    38,    42,    77,    78,
      63,    54,    84,    82,    83,    50,    84,    97,    42,    10,
      52,    11,    21,    79,    50,    53,    57,    55,    50,    10,
      50,    53,    51,    55,    50,    11,    42,    37,    84,    84,
      50,    84,    50,    84,    84,    89,    50,    87,    84,    50,
      68,    76,    77,    79,    26,    93,    50,    50,    98,    50,
      53,    79,    21,    50,    72,    21,    38,    42,    81,    88,
      91,    28,    10,    90,    42,    63,    50,    58,    20,    94,
      91,    84,    21,    11,    75,    58,    95,    21,    21,    50,
      50,    79,    21,    38,    91,    25,    28,    21,    42,    55,
      50,    50,    50,    50,    28,    73,    99,    21,    91,    42,
      21,    50,    28,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    61,    62,    60,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    68,
      68,    69,    69,    71,    72,    73,    70,    74,    75,    70,
      76,    76,    77,    77,    77,    78,    79,    79,    80,    80,
      80,    80,    80,    81,    81,    82,    81,    83,    81,    81,
      81,    81,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    86,    86,    87,    87,
      87,    89,    90,    88,    91,    91,    93,    92,    95,    94,
      94,    97,    98,    96,    99,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    12,     2,     0,     2,     0,     1,
       1,     8,     6,     6,     4,     4,     7,     1,     1,     1,
       1,     2,     0,     0,     0,     0,    17,     0,     0,    13,
       2,     0,     3,     1,     0,     3,     2,     0,     1,     1,
       1,     1,     2,     4,     7,     0,     4,     0,     4,     3,
       3,     2,     3,     1,     1,     1,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     1,     1,     1,     1,     1,     4,     1,     3,
       0,     0,     0,     7,     1,     1,     0,     9,     0,     3,
       0,     0,     0,     9,     0,    15
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
        case 2:
#line 75 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < PROGRAM >");
                    // Insert ID in current table.
                    insertTableEntry(new SymInfo(*(yyvsp[0].sval), DEC_PROGRAM));
                    Code_Generator.program_start();
                }
#line 1553 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "yacc.y" /* yacc.c:1646  */
    {
                    Code_Generator.main_start();
                    is_Main_Block = true;
                }
#line 1562 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "yacc.y" /* yacc.c:1646  */
    {
                    if (*(yyvsp[-10].sval) != *(yyvsp[0].sval))
                        yyerror("Program ID not match!");
                    //Dump all the list of tables.
                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    Code_Generator.main_end();
                    Code_Generator.program_end();
                }
#line 1577 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "yacc.y" /* yacc.c:1646  */
    { Trace("REDUCE < DECLARTION >") }
#line 1583 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "yacc.y" /* yacc.c:1646  */
    {
                    if ((yyvsp[-3].dataType) != (yyvsp[-1].dataValue)->get_data_type()) 
                    {
                        yyerror("Declartion Type Inconsistent");
                    }
                    insertTableEntry(new SymInfo(*(yyvsp[-7].sval), DEC_CONST, (yyvsp[-3].dataType), *(yyvsp[-1].dataValue)));
                }
#line 1595 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "yacc.y" /* yacc.c:1646  */
    {
                    insertTableEntry(new SymInfo(*(yyvsp[-5].sval), DEC_CONST, *(yyvsp[-1].dataValue)));
                }
#line 1603 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "yacc.y" /* yacc.c:1646  */
    {
                    if ((yyvsp[-3].dataType) != (yyvsp[-1].dataValue)->get_data_type())
                    {
                        yyerror("Declartion Type Inconsistent");
                    }
                    insertTableEntry(new SymInfo(*(yyvsp[-5].sval), DEC_VAR, (yyvsp[-3].dataType), *(yyvsp[-1].dataValue)));
                    if (symbol_tables.isGlobalTable())
                    {
                        if ((yyvsp[-1].dataValue)->get_data_type() == TYPE_BOOL){
                            Code_Generator.dec_global_var_with_value(*(yyvsp[-5].sval), (yyvsp[-1].dataValue)->get_bool()? 1:0);
                        }
                        else{
                        Code_Generator.dec_global_var_with_value(*(yyvsp[-5].sval), (yyvsp[-1].dataValue)->get_int());
                        }
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*(yyvsp[-5].sval));
                        id->stackID = stackVarID;
                        Code_Generator.assign_local_var(stackVarID++);
                    }
                }
#line 1630 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "yacc.y" /* yacc.c:1646  */
    {
                    insertTableEntry(new SymInfo(*(yyvsp[-3].sval), DEC_VAR, (yyvsp[-1].dataType)));
                    if (symbol_tables.isGlobalTable())
                    {
                         Code_Generator.dec_global_var(*(yyvsp[-3].sval));
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*(yyvsp[-3].sval));
                        id->stackID = stackVarID;
                        stackVarID++;
                    }
                }
#line 1648 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "yacc.y" /* yacc.c:1646  */
    {
                    insertTableEntry(new SymInfo(*(yyvsp[-3].sval), DEC_VAR, *(yyvsp[-1].dataValue)));
                    if (symbol_tables.isGlobalTable())
                    {
                        if ((yyvsp[-1].dataValue)->get_data_type() == TYPE_BOOL){
                            Code_Generator.dec_global_var_with_value(*(yyvsp[-3].sval), (yyvsp[-1].dataValue)->get_bool()? 1:0);
                        }
                        else{
                        Code_Generator.dec_global_var_with_value(*(yyvsp[-3].sval), (yyvsp[-1].dataValue)->get_int());
                        }
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*(yyvsp[-3].sval));
                        id->stackID = stackVarID;
                        Code_Generator.assign_local_var(stackVarID++);
                    }
                }
#line 1671 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "yacc.y" /* yacc.c:1646  */
    {
                    if ((yyvsp[-2].ival) < 1)
                    {
                        yyerror("Array length must greater than 1");
                    }
                    insertTableEntry(new SymInfo(*(yyvsp[-6].sval), DEC_ARRAY, (yyvsp[-4].dataType), (yyvsp[-2].ival)));
                }
#line 1683 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = TYPE_INT;
                }
#line 1691 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = TYPE_FLOAT;
                }
#line 1699 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 203 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = TYPE_STRING;
                }
#line 1707 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = TYPE_BOOL;
                }
#line 1715 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 219 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < PROCEDURE(args) >");
                    // New a function type STEI.
                    SymInfo* func = new SymInfo(*(yyvsp[0].sval), DEC_PROCEDURE);
                    stackVarID = 0;

                    // Add func into current table.
                    insertTableEntry(func);

                    /* Create a new child table. */
                    symbol_tables.add_table();
                }
#line 1732 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "yacc.y" /* yacc.c:1646  */
    {
                    SymInfo* func = symbol_tables.look_up(*(yyvsp[-5].sval));
                    // Add function arg type. use to check.
                    for(int i = 0 ; i < (yyvsp[-2].func_args)->size(); i++)
                    {
                        func->add_arg_type((*(yyvsp[-2].func_args))[i]->get_data_type());
                    }
                    func->set_return_type((yyvsp[0].dataType));
                    // Add func args into new table.
                    for (int i = 0 ; i < (yyvsp[-2].func_args)->size(); i++)
                    {
                        insertTableEntry((*(yyvsp[-2].func_args))[i]);
                    }
                    Code_Generator.dec_func_start(func);
                }
#line 1752 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 248 "yacc.y" /* yacc.c:1646  */
    { Trace("REDUCE < Procedure(args) end >");}
#line 1758 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "yacc.y" /* yacc.c:1646  */
    {
                    SymInfo* func = symbol_tables.look_up(*(yyvsp[-15].sval));
                    Code_Generator.def_func_end(func , isReturn);

                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    isReturn = false;
                }
#line 1772 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 260 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < PROCEDURE() >");
                    // New a function type STEI.
                    SymInfo* func = new SymInfo(*(yyvsp[-1].sval), DEC_PROCEDURE);
                    stackVarID = 0;
                    func->set_return_type((yyvsp[0].dataType));
                    Code_Generator.dec_func_start(func);
                    // Add func into current table.
                    insertTableEntry(func);

                    /* Create a new child table. */
                    symbol_tables.add_table();
                }
#line 1790 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 274 "yacc.y" /* yacc.c:1646  */
    { Trace("REDUCE < Procedure() end >");}
#line 1796 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "yacc.y" /* yacc.c:1646  */
    {
                    SymInfo* func = symbol_tables.look_up(*(yyvsp[-11].sval));
                    Code_Generator.def_func_end(func , isReturn);

                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    isReturn = false;
                }
#line 1810 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 288 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = (yyvsp[0].dataType);
                }
#line 1818 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 292 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataType) = TYPE_NONE;
                }
#line 1826 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "yacc.y" /* yacc.c:1646  */
    {
                    // Store arg into formal_args
                    (yyvsp[0].func_args)->push_back((yyvsp[-2].func_arg));
                    (yyval.func_args) = (yyvsp[0].func_args);
                }
#line 1836 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "yacc.y" /* yacc.c:1646  */
    {
                    // Create a vector which store only one arg.
                    vector<SymInfo*>* temp = new vector<SymInfo*>();
                    temp->push_back((yyvsp[0].func_arg));
                    (yyval.func_args) = temp;
                }
#line 1847 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 312 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.func_args) = new vector<SymInfo*>();
                }
#line 1855 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 319 "yacc.y" /* yacc.c:1646  */
    {
                    // Procedure args are all immutable
                    (yyval.func_arg) = new SymInfo(*(yyvsp[-2].sval), DEC_VAR, (yyvsp[0].dataType));
                    if (insertTableEntry((yyval.func_arg)))
                    {
                        (yyval.func_arg)->stackID = stackVarID++;
                    }
                }
#line 1868 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 345 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < ID := EXPR >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[-3].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[-3].sval) +" is Not FOUND"));
                    }
                    else
                    {
                        // Declare must be DEC_VAR
                        if (id->get_declare_type() != DEC_VAR)
                        {
                            yyerror(string("ID " + *(yyvsp[-3].sval) + " CONSTANT can't be assign"));
                        }   
                        // Only assign with same data type
                        else if (id->get_data_type() != (yyvsp[-1].dataValue)->get_data_type())
                        {
                            yyerror(string("ID " + *(yyvsp[-3].sval) + " Assign with different Data type"));
                        }
                        else 
                        {
                            // Set variable data
                            id->set_data(*(yyvsp[-1].dataValue));
                            // global
                            if (id->isGlobal())
                            {
                                Code_Generator.assign_global_var(id->get_id_name());
                            }
                            // local
                            else
                            {
                                Code_Generator.assign_local_var(id->stackID);
                            }
                        }
                    }
                }
#line 1910 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 383 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < ID[EXPR] := EXPR >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[-6].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[-6].sval) +" is Not FOUND"));
                    }
                    else 
                    {
                        // Index must be int
                        if ((yyvsp[-4].dataValue)->get_data_type() != TYPE_INT)
                        {
                            yyerror(string("ID " + *(yyvsp[-6].sval) + " array index must be int"));
                        }
                        // Declare type must be DEC_ARRAY;
                        else if (id->get_declare_type() != DEC_ARRAY)
                        {
                            yyerror(string("ID " + *(yyvsp[-6].sval) + " not array type"));
                        }
                        // Only assign with same data type
                        else if (id->get_array_data_type() != (yyvsp[-1].dataValue)->get_data_type())
                        {
                            yyerror(string("ID " + *(yyvsp[-6].sval) + " Assign with different Data type"));
                        }
                        // Check if index out of range
                        else if (id->get_array_length() <= (yyvsp[-4].dataValue)->get_int())
                        {
                            yyerror(string("ID " + *(yyvsp[-6].sval) + " array index out of range"));
                        }
                        else 
                        {
                            // Set array[index] data.
                            id->set_array_data((yyvsp[-4].dataValue)->get_int(), *(yyvsp[-1].dataValue));
                        }
                    }
                }
#line 1952 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 421 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < PRINT >")
                    Code_Generator.print_start();

                }
#line 1962 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 427 "yacc.y" /* yacc.c:1646  */
    { 
                    if((yyvsp[-1].dataValue)->get_data_type() == TYPE_STRING){
                        Code_Generator.print_str_end();
                    }
                    else{
                        Code_Generator.print_int_end();
                    }
                }
#line 1975 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 436 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < PRINTLN >")
                    Code_Generator.print_start();

                }
#line 1985 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 441 "yacc.y" /* yacc.c:1646  */
    { 
                    if((yyvsp[-1].dataValue)->get_data_type() == TYPE_STRING){
                        Code_Generator.println_str_end();
                    }
                    else{
                        Code_Generator.println_int_end();
                    }
                }
#line 1998 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 450 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < READ ID >")  
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[-1].sval));
                    if (id == NULL)
                        yyerror(string("ID " + *(yyvsp[-1].sval) +" is Not FOUND"));
                }
#line 2009 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 457 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < RETURN EXPR > ")
                    isReturn = true;
                    Code_Generator.func_end_inAdvance();
                }
#line 2019 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 463 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < RETURN > ")
                    isReturn = true;
                    Code_Generator.func_end_inAdvance();
                }
#line 2029 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 472 "yacc.y" /* yacc.c:1646  */
    { 
                    (yyval.dataValue) = (yyvsp[-1].dataValue);
                }
#line 2037 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 476 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.dataValue) = (yyvsp[0].dataValue);
                    if (!symbol_tables.isGlobalTable() || is_Main_Block)
                    {
                        if((yyvsp[0].dataValue)->get_data_type() == TYPE_STRING){
                            Code_Generator.load_const_str(*((yyvsp[0].dataValue)->get_string()));
                        }
                        else if((yyvsp[0].dataValue)->get_data_type() == TYPE_BOOL){
                            Code_Generator.load_const_int((yyvsp[0].dataValue)->get_bool()? 1:0);
                        }
                        else{
                            Code_Generator.load_const_int((yyvsp[0].dataValue)->get_int());
                        }
                    }
                }
#line 2057 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 492 "yacc.y" /* yacc.c:1646  */
    {
                    // Only get function type
                    Data* d = new Data();
                    d->set_data_type((yyvsp[0].dataType));
                    (yyval.dataValue) = d;
                }
#line 2068 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 499 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < ID >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[0].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[0].sval) +" is Not FOUND"));
                    }
                    else
                    {
                        // Return ID data.
                        (yyval.dataValue) = id->get_data();
                        Data *idData = id->get_data();
                        if (id->get_declare_type() == DEC_CONST)
                        {
                            if (id->get_data_type() == TYPE_INT)
                            {
                                Code_Generator.load_const_int(idData->get_int());
                            }
                            else if (id->get_data_type() == TYPE_STRING)
                            {
                                Code_Generator.load_const_str(*(idData->get_string()));
                            }
                        
                        }
                        else if (id->get_declare_type() == DEC_VAR)
                        {
                            // global
                            if (id->isGlobal())
                            {
                                Code_Generator.load_global_var(id->get_id_name());
                            }
                            // local
                            else
                            {
                                Code_Generator.load_local_var(id->stackID);
                            }
                        }
                    }
                }
#line 2113 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 540 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < ID[EXPR] >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[-3].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[-3].sval) +" is Not FOUND"));
                    }
                    else
                    {
                        // Check if index out of range
                        if (id->get_array_length() <= (yyvsp[-1].dataValue)->get_int())
                        {
                            yyerror(string("ID " + *(yyvsp[-3].sval) + " array index out of range"));
                        }
                        // Declare type must be DEC_ARRAY;
                        if (id->get_declare_type() != DEC_ARRAY)
                        {
                            yyerror(string("ID " + *(yyvsp[-3].sval) + " not array type"));
                        }
                        // Return ID[index] data.
                        (yyval.dataValue) = id->get_array_data((yyvsp[-1].dataValue)->get_int());
                    }
                }
#line 2142 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 566 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < - EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[0].dataValue)->get_data_type() == TYPE_INT)
                    {
                        Data *d = new Data(TYPE_INT, (yyvsp[0].dataValue)->get_int() * -1);
                        (yyval.dataValue) = d;
                    }
                    else if ((yyvsp[0].dataValue)->get_data_type() == TYPE_FLOAT)
                    {
                        Data *d = new Data(TYPE_FLOAT, (yyvsp[0].dataValue)->get_float() * -1);
                        (yyval.dataValue) = d;
                    }
                    else 
                    {
                        yyerror("TYPE ERROR in -exp");
                    }
                    Code_Generator.operation('n');
                }
#line 2166 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 586 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR * EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            int num1 = (yyvsp[-2].dataValue)->get_int();
                            int num2 = (yyvsp[0].dataValue)->get_int();
                            cout<<num1<<","<<num2<<endl;
                            Data *d = new Data(TYPE_INT, (yyvsp[-2].dataValue)->get_int() * (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, (yyvsp[-2].dataValue)->get_float() * (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp * exp");
                        }
                    }
                    Code_Generator.operation('*');
                }
#line 2199 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 615 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR / EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            int num1 = (yyvsp[-2].dataValue)->get_int();
                            int num2 = (yyvsp[0].dataValue)->get_int();
                            cout<<num1<<","<<num2<<endl;
                            Data *d = new Data(TYPE_INT, num1 / num2);
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, (yyvsp[-2].dataValue)->get_float() / (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp / exp");
                        }
                    }
                    Code_Generator.operation('/');
                }
#line 2232 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 644 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR + EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, (yyvsp[-2].dataValue)->get_int() + (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, (yyvsp[-2].dataValue)->get_float() + (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp + exp");
                        }
                    }
                    Code_Generator.operation('+');
                }
#line 2262 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 670 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR - EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, (yyvsp[-2].dataValue)->get_int() - (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, (yyvsp[-2].dataValue)->get_float() - (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp - exp");
                        }
                    }
                    Code_Generator.operation('-');
                }
#line 2292 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 696 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR % EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, (yyvsp[-2].dataValue)->get_int() % (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp % exp");
                        }
                    }
                    Code_Generator.operation('%');
                }
#line 2317 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 717 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR < EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        // Used to return
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() < (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() < (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            
                            d->set_value((yyvsp[-2].dataValue)->get_bool() < (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp < exp");
                        }
                    }
                    Code_Generator.relation("<");
                }
#line 2355 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 751 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR <= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() <= (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() <= (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() <= (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp <= exp");
                        }
                    }
                    Code_Generator.relation("<=");
                }
#line 2391 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 783 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR > EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() > (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() > (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() > (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp > exp");
                        }
                    }
                    Code_Generator.relation(">");
                }
#line 2427 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 815 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR >= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() >= (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() >= (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() >= (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp >= exp");
                        }
                    }
                    Code_Generator.relation(">=");
                }
#line 2463 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 847 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR = EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() == (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() == (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() == (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp = exp");
                        }
                    }
                    Code_Generator.relation("=");
                }
#line 2499 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 879 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR /= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_INT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_int() != (yyvsp[0].dataValue)->get_int());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_float() != (yyvsp[0].dataValue)->get_float());
                            (yyval.dataValue) = d;
                        }
                        else if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() != (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp /= exp");
                        }
                    }
                    Code_Generator.relation("/=");
                }
#line 2535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 911 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < LOGICAL_NOT EXPR >");
                    // Only calculate the type BOOL
                    if ((yyvsp[0].dataValue)->get_data_type() == TYPE_BOOL)
                    {
                        Data *d = new Data(TYPE_BOOL, false);
                        d->set_value(!(yyvsp[0].dataValue)->get_bool());
                        (yyval.dataValue) = d;
                    }
                    else
                    {
                        yyerror("TYPE ERROR in LOGICAL_NOT exp");
                    }
                    Code_Generator.operation('!');
                }
#line 2555 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 927 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR LOGICAL_AND EXPR >");
                    // Only calculate the type BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() && (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp LOGICAL_AND exp");
                        }
                    }
                    Code_Generator.operation('&');
                }
#line 2581 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 949 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < EXPR LOGICAL_OR EXPR >");
                    // Only calculate the type BOOL
                    if ((yyvsp[-2].dataValue)->get_data_type() != (yyvsp[0].dataValue)->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ((yyvsp[-2].dataValue)->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value((yyvsp[-2].dataValue)->get_bool() || (yyvsp[0].dataValue)->get_bool());
                            (yyval.dataValue) = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp LOGICAL_OR exp");
                        }
                    }
                    Code_Generator.operation('|');
                }
#line 2607 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 974 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Literal_Const INT >");
                    Data *d = new Data(TYPE_INT, (yyvsp[0].ival));
                    (yyval.dataValue) = d;
                }
#line 2617 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 980 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Literal_Const FLOAT >");
                    Data *d = new Data(TYPE_FLOAT, (yyvsp[0].fval));
                    (yyval.dataValue) = d;
                }
#line 2627 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 986 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Literal_Const STR >");
                    Data *d = new Data(TYPE_STRING, (yyvsp[0].sval));
                    (yyval.dataValue) = d;
                }
#line 2637 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 992 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Literal_Const BOOL >");
                    Data *d = new Data(TYPE_BOOL, (yyvsp[0].bval));
                    (yyval.dataValue) = d;
                }
#line 2647 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1001 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Func ID >");
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[0].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[0].sval) +" is Not FOUND"));
                    }
                    else
                    {
                        if (id->get_declare_type() != DEC_PROCEDURE)
                        {
                            yyerror(string("ID " + *(yyvsp[0].sval) +" function invocation must be declare as PROCEDURE"));
                        }
                        (yyval.dataType) = id->get_return_type();
                        Code_Generator.func_invoke(id);
                    }
                }
#line 2669 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1019 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < Func ID(EXPR) >");
                    SymInfo* id = symbol_tables.look_up(*(yyvsp[-3].sval));
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *(yyvsp[-3].sval) +" is Not FOUND"));
                    }
                    else
                    {
                        if (id->get_declare_type() != DEC_PROCEDURE)
                        {
                            yyerror(string("ID " + *(yyvsp[-3].sval) +" function invocation must be declare as PROCEDURE"));
                        }
                        // Check if comma_separated_exp type is equal to function args
                        if (id->check_arg_match((yyvsp[-1].func_call)) == false)
                        {
                            yyerror("Function arg type mismatch");
                        }
                        (yyval.dataType) = id->get_return_type();
                        Code_Generator.func_invoke(id);
                    }
                }
#line 2696 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1044 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.func_call) = new vector<Data*>();
                    (yyval.func_call)->push_back((yyvsp[0].dataValue));
                }
#line 2705 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1049 "yacc.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].func_call)->push_back((yyvsp[-2].dataValue));
                    (yyval.func_call) = (yyvsp[0].func_call);
                }
#line 2714 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1054 "yacc.y" /* yacc.c:1646  */
    {
                    (yyval.func_call) = new vector<Data*>();
                }
#line 2722 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1061 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < BLOCK >");
                    // Create a new child table
                    symbol_tables.add_table();
                }
#line 2732 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1067 "yacc.y" /* yacc.c:1646  */
    { Trace("REDUCE < BLOCK end >"); }
#line 2738 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1068 "yacc.y" /* yacc.c:1646  */
    {
                    symbol_tables.dump();
                    // Pop the current table.
                    symbol_tables.pop_table();
                }
#line 2748 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1081 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < IF EXPR THEN >");
                    Code_Generator.if_start();
                    if ((yyvsp[-1].dataValue)->get_data_type() != TYPE_BOOL)
                    {
                        yyerror("IF condition must be boolean");
                    }
                }
#line 2761 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1090 "yacc.y" /* yacc.c:1646  */
    {
                    Code_Generator.if_end();
                }
#line 2769 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1097 "yacc.y" /* yacc.c:1646  */
    {
                    Code_Generator.else_start();
                }
#line 2777 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1106 "yacc.y" /* yacc.c:1646  */
    {
                    Code_Generator.while_start();
                }
#line 2785 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1110 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < WHILE (EXPR) >");
                    if ((yyvsp[0].dataValue)->get_data_type() != TYPE_BOOL)
                    {
                        yyerror("WHILE expression must be boolean");
                    }
                    Code_Generator.if_start();
                }
#line 2798 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1119 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < Loop end >");
                    Code_Generator.while_end(); 
                }
#line 2807 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1124 "yacc.y" /* yacc.c:1646  */
    {
                    Trace("REDUCE < FOR >");
                    Code_Generator.load_const_int((yyvsp[-5].ival));
                    SymInfo *id = symbol_tables.look_up(*(yyvsp[-7].sval));

                    string relation;
                    if ((yyvsp[-5].ival) <= (yyvsp[-2].ival))
                        relation = "<=";
                    else
                        relation = ">=";
                    if (symbol_tables.isGlobalTable())
                        Code_Generator.for_globalVar_start(id->get_id_name(), relation, (yyvsp[-5].ival), (yyvsp[-2].ival));                
                    else   
                        Code_Generator.for_localVar_start(id->stackID, relation, (yyvsp[-5].ival), (yyvsp[-2].ival));
                }
#line 2827 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1140 "yacc.y" /* yacc.c:1646  */
    { 
                    Trace("REDUCE < Loop end >");
                    SymInfo *id = symbol_tables.look_up(*(yyvsp[-12].sval));
                    char op;
                    if ((yyvsp[-10].ival) <= (yyvsp[-7].ival))
                        op = '+';
                    else
                        op = '-';
                    if (id->isGlobal()) 
                        Code_Generator.for_globalVar_end(id->get_id_name(), op);                       
                    else
                        Code_Generator.for_localVar_end(id->stackID, op);
                }
#line 2845 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2849 "y.tab.cpp" /* yacc.c:1646  */
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
#line 1155 "yacc.y" /* yacc.c:1906  */


bool insertTableEntry(SymInfo *id)
{
    if (symbol_tables.insert(id) == -1)
    {
        //yyerror("Insert table entry faild: " + id->get_id_name());
        return false;
    }
    return true;
}

void yyerror(string msg)
{
    cout << "yyerror: " << msg << endl;
}

int main(int argc, char* argv[])
{
    /* open the source program file */
    if (argc == 1) {
        yyin = stdin;
    }
    else if (argc == 2) {
        yyin = fopen(argv[1], "r");         /* open input file */
    }
    else {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    string source = string(argv[1]);
    int dot = source.find(".");
    string filename = source.substr(0, dot);
    Code_Generator = CodeGenerator(filename);

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
    else
        cout << "Parsing succeed!" << endl;
    return 0;
}
