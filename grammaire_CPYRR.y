/*                   Fichier YACC du language CPYRR                         */
/*        Auteur : Dimitri ESCALLE DA COSTA VAZ Julien NAIDJI Nabil         */
/* Contient la grammaire neccesaire au bon fonctionnement du langages CPYRR */

%{

#include "include.h"


/* Variable table lexicographique */

structlexhc tablelexico[MAX];
int lexhashtab[31];
//int numlex=4;

/* ------- ------ */

TabDecla tabDecla[DECLARATION_MAX];

int nb_region = 1;

%}




                              /*    TOKEN    */



/* Ponctuation */

%token PV PP DP VIRG
%token PO PF
%token CO CF
%token P

 /* Affectation */

%token OPAFF

 /* Type */

%token ENTIER REEL BOOLEEN CARACTERE CHAINE

 /* Mots clé */

%token TANT_QUE FAIRE
%token SI ALORS SINON

%token TABLEAU DE
%token STRUCT FSTRUCT

%token PROG DEBUT FIN
%token TYPE VARIABLE

%token PROCEDURE FONCTION RETOURNE

%token VIDE

 /* Opérateur */

%token PLUS MOINS MULT DIV MOD

 /* Opérateur booleen */

%token EGAL DIFFERENT
%token SUPERIEUR INFERIEUR
%token SUP_EGAL INF_EGAL

 /* Opérateur logique */

%token OU ET

 /* Constante */

%token CSTE_ENTIERE
%token CSTE_REEL
%token CSTE_BOOLEEN
%token CSTE_CARACTERE
%token CSTE_CHAINE

 /* IDF */

%token IDF

 /* FONCTION PREDEFINI */

%token LIRE ECRIRE


%%

 /*******************************************************/
 /*                  GRAMMAIRE CPYYR                    */
 /*******************************************************/

programme : PROG corps
          ;

corps : liste_declarations liste_instructions {$$ = $2;}
      | liste_instructions {$$ = $1;}
      ;

liste_declarations : declaration PV
                   | liste_declarations declaration PV
                   ;

liste_instructions : DEBUT suite_liste_inst FIN {$$ = $2;}
                   ;

suite_liste_inst : instruction PV {$$ = $1;}
                 | suite_liste_inst instruction PV
                 ;

/* DECLARATION */

declaration : declaration_type
            | declaration_variable
            | declaration_procedure
            | declaration_fonction
            ;

declaration_type : TYPE IDF DP STRUCT liste_champs FSTRUCT
  {
     if (ajouterDeclaStruct(4) == -1)
       yyerror("Table Decla pleine");
  }
                           | TYPE IDF DP TABLEAU dimension DE nom_type
  {
     if (ajouterDeclaTab(4) == -1)
       yyerror("Table Decla pleine");
  }
                           ;


/* TABLEAU */

dimension : CO liste_dimensions CF
          ;

liste_dimensions : une_dimension
                 | liste_dimensions VIRG une_dimension
                 ;

une_dimension : expression PP expression
              ;

/* ---------- */

/* STRUCT */

liste_champs : un_champ PV
             | liste_champs un_champ PV
             ;

un_champ : IDF DP nom_type
         ;

/* ----------- */

/* TYPE */

nom_type : type_simple {$$ = $1;}
         | IDF {$$  = $1;}
         ;

type_simple : ENTIER
            | REEL
            | BOOLEEN
            | CARACTERE
            | CHAINE CO CSTE_ENTIERE CF
            ;

/* ----------- */

declaration_variable : VARIABLE decla_suite_var
                     ;

decla_suite_var : IDF DP nom_type {if (ajouterDeclaVar(4) == -1)
                                                           yyerror("Table Decla pleine");}
                        | IDF VIRG decla_suite_var {if (ajouterDeclaVar(4) == -1)
                                                                     yyerror("Table Decla pleine");}
          ;

/* FONCTION/PROCEDURE */

declaration_procedure : PROCEDURE IDF liste_parametres corps
  {
    if(ajouterDeclaProc(4) == -1)
      yyerror("Table Decla pleine");
  }
                      ;

declaration_fonction : FONCTION IDF liste_parametres RETOURNE type_simple corps
  {
    if (ajouterDeclaFonct(4) == -1)
      yyerror("Table Decla pleine");
  }
                     ;

liste_parametres : PO PF
                 | PO liste_param PF
		 ;

liste_param : un_param
            | liste_param PV un_param
            ;

un_param : IDF DP type_simple
         ;

/* -------------- */

instruction : affectation
            | condition {$$ = $1;}
            | tant_que {$$ = $1;}
            | declaration_procedure {$$ = $1;}
            | appel
            | VIDE
            | RETOURNE resultat_retourne
            | fonc_pre
            ;

resultat_retourne :
                  | expression
		  ;


/* APPEL FONCTION */

appel : IDF liste_arguments
      ;

liste_arguments : PO PF {/*$$ = NULL;*/}
                | PO liste_args PF {$$ = $2;}
		;

liste_args : un_arg {$$ = $1;}
           | liste_args VIRG un_arg
           ;

un_arg : expression {$$ = $1;}
       ;


/* --------- */

/* STRUCTURE CONDITIONNEL */

condition : SI expression ALORS liste_instructions SINON liste_instructions
          ;

tant_que : TANT_QUE PO expression PF FAIRE liste_instructions
         ;

/* -------- */

/* AFFECTATION */

affectation : variable OPAFF expression
            ;

                                  /* A définir */


/* VARIABLE */



variable : IDF CO liste_var CF var
         | IDF var
         ;

liste_var : expression
          | liste_var VIRG expression
          ;

var : P variable
    |
    ;

/* ---------- */

/* EXPRESSION */

expression : expression ET exp
           | expression OU exp
           | exp {$$ = $1;}
           ;

exp : exp opp_bool exp1
    | exp1 {$$ = $1;}
    ;

exp1 : exp1 PLUS exp2
     | exp1 MOINS exp2
     | exp2 {$$ = $1;}
     ;

exp2 : exp2 MULT exp3
     | exp2 DIV exp3
     | exp2 MOD exp3
     | exp3 {$$ = $1;}
     ;

exp3 : PO expression PF {$$ = $2;}
     | CSTE_ENTIERE
     | CSTE_REEL
     | CSTE_CARACTERE
     | CSTE_CHAINE
     | CSTE_BOOLEEN
     | appel {$$ = $1;}
     | variable {$$ = $1;}
     ;

opp_bool : EGAL
         | DIFFERENT
         | SUPERIEUR
         | INFERIEUR
         | SUP_EGAL
         | INF_EGAL
         ;

/* ------------- */

/* FONCTION PREDEFINI */

fonc_pre: LIRE PO liste_variables PF
        | ECRIRE PO format suite_ecriture PF
        ;

suite_ecriture: VIRG variable suite_ecriture
              |
              ;

format: CSTE_CHAINE
      ;

liste_variables: liste_variables VIRG variable
               | variable
               ;

%%

int main(){

 inittab(lexhashtab, 32);
 initTabDecla();


 printf( "-------- Début Compil --------");

 if ( yyparse() != 0 ) {
   fprintf(stderr,"Syntaxe incorrecte\n");
   return 1;
 }
 affiche_lextab(tablelexico);
 afficheTabDecla(tabDecla);
}
