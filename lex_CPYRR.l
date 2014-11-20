%{

#include "include.h"

int nb_ligne = 1;
%}



%%

";" {return(PV);}
":" {return(DP);}
".." {return(PP);}
"," {return(VIRG);}
"(" {return(PO);}
")" {return(PF);}
"[" {return(CO);}
"]" {return(CF);}
"." {return(P);}

":=" {return(OPAFF);}

int {return(ENTIER);}
float {return(REEL);}
bool {return(BOOLEEN);}
char {return(CARACTERE);}
string {return(CHAINE);}

while {return(TANT_QUE);}
do {return(FAIRE);}

if {return(SI);}
then {return(ALORS);}
else {return(SINON);}

array {return(TABLEAU);}
of {return(DE);}

struct {return(STRUCT);}
fstruct {return(FSTRUCT);}

begin {return(DEBUT);}
end {return(FIN);}

type {return(TYPE);}
var {return(VARIABLE);}

proc {return(PROCEDURE);}
function {return(FONCTION);}
return {return(RETOURNE);}

read {return (LIRE);}
write {return (ECRIRE);}

vide {return(VIDE);}

"+" {return(PLUS);}
"-" {return(MOINS);}
"*" {return(MULT);}
"/" {return(DIV);}
"%" {return(MOD);}

"==" {return(EGAL);}
"!=" {return(DIFFERENT);}
">" {return(SUPERIEUR);}
"<" {return(INFERIEUR);}
">=" {return(SUP_EGAL);}
"<=" {return(INF_EGAL);}

"||" {return(OU);}
"&&" {return(ET);}

0|[1-9][0-9]* {if (yylval.type2 = lexstockage(yytext) ==-1) yyerror("table lexico pleine"); return(CSTE_ENTIERE);}
0|[1-9][0-9]*\.[0-9]+ {if (yylval.type2 = lexstockage(yytext) ==-1) yyerror("table lexico pleine");return(CSTE_REEL);}
"true"|"false" {if (yylval.type2 = lexstockage(yytext) ==-1) yyerror("table lexico pleine");return(CSTE_BOOLEEN);}
\'[a-zA-Z]\' {if (yylval.type2 = lexstockage(yytext) ==-1) yyerror("table lexico pleine");return(CSTE_CARACTERE);}
\"[^\"]*\" {if (yylval.type2 = lexstockage(yytext) ==-1) yyerror("table lexico pleine");return(CSTE_CHAINE);}


[a-zA-Z][a-zA-Z0-9_]* {if ((yylval.type2 = lexstockage(yytext)) == -1)
                                        yyerror("Table lexicographique pleine");
                                      return(IDF);}

~[a-zA-Z]*~|~[a-zA-Z]*_[a-zA-Z0-9]*~ {return(PROG);}


\/\*([^\"\*\/]|\*|(\**\"[^\"]*\"))*\*+\/ { int i =0;
                                                        for (i=0;yytext[i] != '\0';i++)
                                                          if (yytext[i] = '\n')
                                                            nb_ligne++;
                                                    };
\/\/.* ;
\"\"~.* ;

"\n" {nb_ligne++ ;}

" "|\t ;
. {return (yyerror("Symbole inattendu"));}

%%

int yyerror(const char *s)

{
  fprintf(stderr, "Ligne : %d - Erreur : %s\n", nb_ligne, s);

  return 1;
}
