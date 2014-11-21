/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 95 "grammaire_CPYRR.y" /* yacc.c:1909  */

struct noeud * type1;
int val_i;

#line 116 "grammaire_CPYRR.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAIRE_CPYRR_TAB_H_INCLUDED  */
