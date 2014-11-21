/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "grammaire_CPYRR.y" /* yacc.c:339  */


#include "include.h"


/* Variable table lexicographique */

extern structlexhc tablelexico[MAX]; // Tableau qui contient tout les IDF possible
extern int lexhashtab[31]; // tableau qui contient le premier element des 32 cas possible pour le hashcode
extern int numlex;  // numero lexicographique comence a 4

/* ------- ------ */
 extern TabDecla tabDecla[DECLARATION_MAX];
 extern structpile pile_representation;
 extern int tab_representation[MAX];
 extern int numrep;
arbre a;
int nb_region = 1;


#line 87 "grammaire_CPYRR.tab.c" /* yacc.c:339  */

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
   by #include "grammaire_CPYRR.tab.h".  */
#ifndef YY_YY_GRAMMAIRE_CPYRR_TAB_H_INCLUDED
# define YY_YY_GRAMMAIRE_CPYRR_TAB_H_INCLUDED
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
    PV = 258,
    PP = 259,
    DP = 260,
    VIRG = 261,
    PO = 262,
    PF = 263,
    CO = 264,
    CF = 265,
    P = 266,
    OPAFF = 267,
    ENTIER = 268,
    REEL = 269,
    BOOLEEN = 270,
    CARACTERE = 271,
    CHAINE = 272,
    TANT_QUE = 273,
    FAIRE = 274,
    SI = 275,
    ALORS = 276,
    SINON = 277,
    TABLEAU = 278,
    DE = 279,
    STRUCT = 280,
    FSTRUCT = 281,
    PROG = 282,
    DEBUT = 283,
    FIN = 284,
    TYPE = 285,
    VARIABLE = 286,
    PROCEDURE = 287,
    FONCTION = 288,
    RETOURNE = 289,
    VIDE = 290,
    PLUS = 291,
    MOINS = 292,
    MULT = 293,
    DIV = 294,
    MOD = 295,
    EGAL = 296,
    DIFFERENT = 297,
    SUPERIEUR = 298,
    INFERIEUR = 299,
    SUP_EGAL = 300,
    INF_EGAL = 301,
    OU = 302,
    ET = 303,
    CSTE_ENTIERE = 304,
    CSTE_REEL = 305,
    CSTE_BOOLEEN = 306,
    CSTE_CARACTERE = 307,
    CSTE_CHAINE = 308,
    IDF = 309,
    LIRE = 310,
    ECRIRE = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 95 "grammaire_CPYRR.y" /* yacc.c:355  */

struct noeud * type1;
int val_i;

#line 189 "grammaire_CPYRR.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAIRE_CPYRR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "grammaire_CPYRR.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   124,   125,   128,   129,   132,   135,   136,
     141,   142,   143,   144,   147,   153,   163,   166,   167,   170,
     177,   178,   181,   188,   189,   192,   193,   194,   195,   196,
     201,   204,   207,   214,   214,   221,   221,   221,   229,   230,
     233,   234,   237,   242,   243,   244,   245,   246,   247,   248,
     249,   252,   253,   259,   262,   263,   266,   267,   270,   278,
     284,   294,   304,   308,   309,   310,   317,   318,   319,   322,
     323,   326,   327,   328,   331,   332,   333,   334,   337,   338,
     339,   340,   341,   342,   343,   344,   347,   348,   349,   350,
     351,   352,   359,   360,   363,   364,   367,   370,   371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PV", "PP", "DP", "VIRG", "PO", "PF",
  "CO", "CF", "P", "OPAFF", "ENTIER", "REEL", "BOOLEEN", "CARACTERE",
  "CHAINE", "TANT_QUE", "FAIRE", "SI", "ALORS", "SINON", "TABLEAU", "DE",
  "STRUCT", "FSTRUCT", "PROG", "DEBUT", "FIN", "TYPE", "VARIABLE",
  "PROCEDURE", "FONCTION", "RETOURNE", "VIDE", "PLUS", "MOINS", "MULT",
  "DIV", "MOD", "EGAL", "DIFFERENT", "SUPERIEUR", "INFERIEUR", "SUP_EGAL",
  "INF_EGAL", "OU", "ET", "CSTE_ENTIERE", "CSTE_REEL", "CSTE_BOOLEEN",
  "CSTE_CARACTERE", "CSTE_CHAINE", "IDF", "LIRE", "ECRIRE", "$accept",
  "programme", "corps", "liste_declarations", "liste_instructions",
  "suite_liste_inst", "declaration", "declaration_type", "dimension",
  "liste_dimensions", "une_dimension", "liste_champs", "un_champ",
  "nom_type", "type_simple", "declaration_variable", "decla_suite_var",
  "declaration_procedure", "$@1", "declaration_fonction", "$@2", "$@3",
  "liste_parametres", "liste_param", "un_param", "instruction",
  "resultat_retourne", "appel", "liste_arguments", "liste_args", "un_arg",
  "condition", "tant_que", "affectation", "variable", "var", "expression",
  "exp", "exp1", "exp2", "exp3", "opp_bool", "fonc_pre", "suite_ecriture",
  "format", "liste_variables", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    73,    86,    65,    41,    48,  -114,  -114,  -114,    73,
    -114,   109,  -114,  -114,  -114,  -114,  -114,   110,    21,    21,
    -114,    71,   131,   132,    59,  -114,   137,  -114,  -114,  -114,
    -114,   133,  -114,   138,   120,  -114,    90,    92,  -114,   144,
    -114,    21,    21,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     -14,   -25,    91,    -8,  -114,  -114,    82,     2,    21,    95,
    -114,  -114,    95,    97,  -114,   145,  -114,    21,   -11,    22,
      48,   147,   147,  -114,    14,    18,   123,    21,    21,  -114,
    -114,  -114,  -114,  -114,  -114,    21,    21,    21,    21,    21,
      21,  -114,    81,  -114,    82,    -4,    87,  -114,  -114,    84,
    -114,   146,  -114,    82,   148,   102,  -114,  -114,  -114,  -114,
     149,  -114,  -114,  -114,  -114,     3,    73,  -114,   140,  -114,
     139,   -25,   -25,    91,    -8,    -8,  -114,  -114,  -114,    21,
    -114,    87,    95,  -114,    21,   152,    21,   141,   157,   -13,
     160,   115,  -114,   161,    42,  -114,  -114,   134,   123,   123,
    -114,  -114,  -114,    -1,  -114,    58,  -114,    11,    22,    22,
    -114,   164,  -114,   159,    94,   116,  -114,    94,  -114,  -114,
    -114,    21,  -114,    21,  -114,  -114,  -114,  -114,  -114,  -114,
      73,  -114,    82,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    33,    35,     2,     0,
       4,     0,    10,    11,    12,    13,     1,     0,     0,    51,
      48,    65,     0,     0,     0,    46,     0,    47,    44,    45,
      43,     0,    50,     0,     0,    30,     0,     0,     3,     0,
       5,     0,     0,    79,    80,    83,    81,    82,    84,    85,
       0,    68,    70,    73,    77,    49,    52,     0,     0,     0,
      53,    62,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,    54,     0,    56,    58,     0,    65,    64,    98,     0,
      96,    95,     9,    61,     0,     0,    25,    26,    27,    28,
       0,    24,    31,    23,    32,     0,     0,    36,     0,    78,
       0,    67,    66,    69,    71,    72,    74,    75,    76,     0,
      55,    65,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    40,    34,     0,     0,     0,
      57,    63,    97,    95,    93,     0,    17,     0,     0,     0,
      14,     0,    20,     0,     0,     0,    39,     0,    60,    59,
      94,     0,    16,     0,    15,    22,    21,    29,    42,    41,
       0,    18,    19,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -113,  -114,    -7,  -114,   162,  -114,  -114,  -114,
       4,  -114,    33,   -27,   -83,  -114,   103,     5,  -114,  -114,
    -114,  -114,   104,  -114,     9,   153,  -114,    24,  -114,  -114,
      49,  -114,  -114,  -114,     1,    51,   -18,    57,    96,    50,
      34,  -114,  -114,    26,  -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    24,    11,    12,   137,   155,
     156,   139,   140,   112,   113,    13,    35,    14,    36,    15,
      37,   147,   116,   144,   145,    26,    55,    48,    60,    92,
      93,    28,    29,    30,    49,    61,    94,    51,    52,    53,
      54,    85,    32,   135,   101,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    56,    38,   146,    31,   134,   131,    76,    25,    42,
      91,   142,   104,   160,   105,   173,    79,    80,    81,    82,
      83,    84,   118,    74,    75,    31,   119,    27,    42,    25,
      88,    89,    90,    77,    78,   106,   107,   108,   109,   110,
      95,   138,     1,    77,    78,   165,    77,    78,    27,   103,
     166,    43,    44,    45,    46,    47,    21,   143,    77,    78,
      97,    77,    78,    98,   171,    77,    78,   183,   172,   120,
      43,    44,    45,    46,    47,    21,   111,    17,    57,    18,
      58,   178,    59,    17,   180,    18,    16,   129,    64,   130,
     132,     6,   133,    19,    20,    33,    58,     6,    59,    19,
      20,     3,    34,     4,     5,     6,     7,   106,   107,   108,
     109,   110,    40,    21,    22,    23,   153,    41,   157,    21,
      22,    23,   126,   127,   128,    69,    70,    86,    87,    77,
      78,   174,   175,   152,   121,   122,   124,   125,    62,    63,
      66,   168,   169,    68,    71,    67,    72,    73,   102,    96,
     100,     3,   134,   157,   115,   182,   138,   136,   141,   148,
     154,   149,   159,   162,   163,   158,   164,   176,   167,   177,
     143,    39,   161,   114,   179,   181,   117,    65,   150,   170,
       0,   123,   151
};

static const yytype_int16 yycheck[] =
{
      18,    19,     9,   116,     3,     6,    10,    21,     3,     7,
       8,     8,    23,    26,    25,     4,    41,    42,    43,    44,
      45,    46,     8,    41,    42,    24,     8,     3,     7,    24,
      38,    39,    40,    47,    48,    13,    14,    15,    16,    17,
      58,    54,    27,    47,    48,     3,    47,    48,    24,    67,
       8,    49,    50,    51,    52,    53,    54,    54,    47,    48,
      59,    47,    48,    62,     6,    47,    48,   180,    10,    76,
      49,    50,    51,    52,    53,    54,    54,    18,     7,    20,
       9,   164,    11,    18,   167,    20,     0,     6,    29,     8,
       6,    32,     8,    34,    35,    54,     9,    32,    11,    34,
      35,    28,    54,    30,    31,    32,    33,    13,    14,    15,
      16,    17,     3,    54,    55,    56,   134,     7,   136,    54,
      55,    56,    88,    89,    90,     5,     6,    36,    37,    47,
      48,   158,   159,   132,    77,    78,    86,    87,     7,     7,
       3,   148,   149,     5,    54,    12,    54,     3,     3,    54,
      53,    28,     6,   171,     7,   173,    54,     9,     9,    19,
       8,    22,     5,     3,    49,    24,     5,     3,    34,    10,
      54,     9,   139,    70,   165,   171,    72,    24,   129,   153,
      -1,    85,   131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    58,    28,    30,    31,    32,    33,    59,    60,
      61,    63,    64,    72,    74,    76,     0,    18,    20,    34,
      35,    54,    55,    56,    62,    74,    82,    84,    88,    89,
      90,    91,    99,    54,    54,    73,    75,    77,    61,    63,
       3,     7,     7,    49,    50,    51,    52,    53,    84,    91,
      93,    94,    95,    96,    97,    83,    93,     7,     9,    11,
      85,    92,     7,     7,    29,    82,     3,    12,     5,     5,
       6,    54,    54,     3,    93,    93,    21,    47,    48,    41,
      42,    43,    44,    45,    46,    98,    36,    37,    38,    39,
      40,     8,    86,    87,    93,    93,    54,    91,    91,   102,
      53,   101,     3,    93,    23,    25,    13,    14,    15,    16,
      17,    54,    70,    71,    73,     7,    79,    79,     8,     8,
      61,    94,    94,    95,    96,    96,    97,    97,    97,     6,
       8,    10,     6,     8,     6,   100,     9,    65,    54,    68,
      69,     9,     8,    54,    80,    81,    59,    78,    19,    22,
      87,    92,    91,    93,     8,    66,    67,    93,    24,     5,
      26,    69,     3,    49,     5,     3,     8,    34,    61,    61,
     100,     6,    10,     4,    70,    70,     3,    10,    71,    81,
      71,    67,    93,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    71,    71,    71,
      72,    73,    73,    75,    74,    77,    78,    76,    79,    79,
      80,    80,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    85,    85,    86,    86,    87,    88,
      89,    90,    91,    92,    92,    92,    93,    93,    93,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     3,     3,     2,     3,
       1,     1,     1,     1,     6,     7,     3,     1,     3,     3,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     4,
       2,     3,     3,     0,     5,     0,     0,     8,     2,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     1,     2,     2,     3,     1,     3,     1,     6,
       6,     3,     2,     4,     2,     0,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     3,     0,     1,     3,     1
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
#line 121 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {a = (yyvsp[0].type1);}
#line 1421 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 124 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1427 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1433 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[-1].type1);}
#line 1439 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 135 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[-1].type1);}
#line 1445 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere((yyvsp[-2].type1), (yyvsp[-1].type1));}
#line 1451 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 148 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
     empile(&pile_representation,(yyvsp[-1].val_i));
     if (ajouterDeclaStruct((yyvsp[-4].val_i),stock_rep(&pile_representation, numrep) ) == -1)
       yyerror("Table Decla pleine");
  }
#line 1461 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
     if (ajouterDeclaTab((yyvsp[-5].val_i)) == -1)
       yyerror("Table Decla pleine");
  }
#line 1470 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 177 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = 1;}
#line 1476 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 178 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = (yyvsp[-2].val_i) + 1;}
#line 1482 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {stockage_representation((yyvsp[-2].val_i),(yyvsp[0].val_i));}
#line 1488 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = (yyvsp[0].val_i);}
#line 1494 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i)  = (yyvsp[0].val_i);}
#line 1500 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 192 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_TB_INT;}
#line 1506 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 193 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_TB_FLOAT;}
#line 1512 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_TB_BOOL;}
#line 1518 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 195 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_TB_CHAR;}
#line 1524 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_TB_STRING;}
#line 1530 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {if (ajouterDeclaVar((yyvsp[-2].val_i), (yyvsp[0].val_i)) == -1)
                                                           yyerror("Table Decla pleine");
                                                        (yyval.val_i) = (yyvsp[0].val_i);}
#line 1538 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 207 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {if (ajouterDeclaVar((yyvsp[-2].val_i), (yyvsp[0].val_i)) == -1)
                                                                     yyerror("Table Decla pleine");
                                                                    (yyval.val_i) = (yyvsp[0].val_i);}
#line 1546 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {nb_region++;}
#line 1552 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 215 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
    if(ajouterDeclaProc((yyvsp[-2].val_i), stock_rep(&pile_representation, numrep)) == -1)
      yyerror("Table Decla pleine");
  }
#line 1561 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {nb_region++;}
#line 1567 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 221 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {empile(&pile_representation,(yyvsp[0].val_i));}
#line 1573 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 222 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
    if (ajouterDeclaFonct((yyvsp[-5].val_i), stock_rep(&pile_representation, numrep)) == -1)
      yyerror("Table Decla pleine");

  }
#line 1583 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 229 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = 0;}
#line 1589 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 230 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = (yyvsp[-1].val_i);}
#line 1595 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 233 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = 1;}
#line 1601 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 234 "grammaire_CPYRR.y" /* yacc.c:1646  */
    { (yyval.val_i) = (yyvsp[-2].val_i) + 1;}
#line 1607 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 237 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {stockage_representation((yyvsp[-2].val_i),(yyvsp[0].val_i));}
#line 1613 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 242 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1619 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 243 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1625 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 244 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1631 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1637 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 246 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1643 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 247 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node(AA_VIDE, -1, -1);}
#line 1649 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 248 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_RETURN, -1, -1),(yyvsp[0].type1));}
#line 1655 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 249 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1661 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 252 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = NULL;}
#line 1667 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 253 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1673 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 259 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_APPEL_FCT, -1, -1), (yyvsp[0].type1));}
#line 1679 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 262 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = NULL;}
#line 1685 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 263 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[-1].type1);}
#line 1691 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 266 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1697 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 267 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere((yyvsp[-2].type1),(yyvsp[0].type1));}
#line 1703 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 270 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1709 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
     (yyval.type1) = concat_fils(concat_frere(creer_node(AA_SI, -1, -1), concat_frere((yyvsp[-4].type1),(yyvsp[-2].type1))), concat_frere(creer_node(AA_ALORS, -1, -1), (yyvsp[0].type1)));
}
#line 1717 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 285 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {
     (yyval.type1) = concat_fils(creer_node(AA_TANT_QUE, -1, -1), concat_frere((yyvsp[-3].type1), (yyvsp[0].type1)));
}
#line 1725 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 294 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_AFFECT, -1, -1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1731 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 304 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere(creer_node(AA_IDF, (yyvsp[-1].val_i), (yyvsp[-1].val_i)), (yyvsp[0].type1));}
#line 1737 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 308 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere(concat_fils(creer_node(AA_TAB, -1 ,-1), (yyvsp[-2].type1)), (yyvsp[0].type1));}
#line 1743 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 309 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere(creer_node(AA_P, -1 ,-1), (yyvsp[0].type1));}
#line 1749 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 310 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = NULL;}
#line 1755 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 317 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_ET,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1761 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 318 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_OU,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1767 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 319 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1773 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 322 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node((yyvsp[-1].val_i),-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1779 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 323 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1785 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 326 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_PLUS,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1791 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 327 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_MOINS,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1797 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 328 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1803 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 331 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_MULT,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1809 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 332 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_DIV,-1,-1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1815 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 333 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_MOD, -1, -1), concat_frere((yyvsp[-2].type1),(yyvsp[0].type1)));}
#line 1821 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 334 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1827 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 337 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[-1].type1);}
#line 1833 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 338 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node_cste_ent((yyvsp[0].val_i), (yyvsp[0].val_i));}
#line 1839 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 339 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node_cste_reel((yyvsp[0].val_i), (yyvsp[0].val_i));}
#line 1845 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 340 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node_cste_char((yyvsp[0].val_i),(yyvsp[0].val_i));}
#line 1851 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 341 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node_cste_string((yyvsp[0].val_i),(yyvsp[0].val_i));}
#line 1857 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 342 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = creer_node_cste_bool((yyvsp[0].val_i), (yyvsp[0].val_i));}
#line 1863 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 343 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1869 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 344 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1875 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 347 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_EGAL;}
#line 1881 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 348 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_DIFF;}
#line 1887 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 349 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_SUPP;}
#line 1893 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 350 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_DIFF;}
#line 1899 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 351 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) =AA_SUPP_EG;}
#line 1905 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 352 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.val_i) = AA_INF_EG;}
#line 1911 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 359 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_READ,-1,-1), (yyvsp[-1].type1));}
#line 1917 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 360 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_fils(creer_node(AA_WRITE, -1, -1), concat_frere((yyvsp[-2].type1), (yyvsp[-1].type1)));}
#line 1923 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 363 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere((yyvsp[-1].type1),(yyvsp[0].type1));}
#line 1929 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 364 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = NULL;}
#line 1935 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 367 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {creer_node_cste_string((yyvsp[0].val_i), (yyvsp[0].val_i));}
#line 1941 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 370 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = concat_frere((yyvsp[-2].type1),(yyvsp[0].type1));}
#line 1947 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 371 "grammaire_CPYRR.y" /* yacc.c:1646  */
    {(yyval.type1) = (yyvsp[0].type1);}
#line 1953 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
    break;


#line 1957 "grammaire_CPYRR.tab.c" /* yacc.c:1646  */
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
#line 374 "grammaire_CPYRR.y" /* yacc.c:1906  */


int main(){

int i;
 inittab(lexhashtab, 32);
 initTabDecla();
 init_pile(&pile_representation);



 printf( "-------- D�but Compil -------- \n");

 printf("%d\n", numlex);

 if ( yyparse() != 0 ) {
   fprintf(stderr,"Syntaxe incorrecte\n");
   return -1;
 }

 affiche_lextab(tablelexico);
 afficheTabDecla(tabDecla);
 afficher_arbre( a);
 printf("\n");
 afficher_tabrep(tab_representation);

}
