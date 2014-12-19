/*                   Fichier YACC du language CPYRR                         */
/*        Auteur : Dimitri ESCALLE DA COSTA VAZ Julien NAIDJI Nabil         */
/* Contient la grammaire neccesaire au bon fonctionnement du langages CPYRR */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_abstrait/arbre_abstrait.h"
#include "lexhashcode/lexhashcode.h"
#include "xmalloc/xmalloc.h"
#include "decla/decla.h"
#include "pile/pile.h"
#define MAX 1000

/* Variable table lexicographique */

    extern structlexhc tablelexico[MAX]; // Tableau qui contient tout les IDF possible
    extern int lexhashtab[31]; // tableau qui contient le premier element des 32 cas possible pour le hashcode
    extern int numlex;  // numero lexicographique comence a 4

/* ------- ------ */
    extern TabDecla tabDecla[DECLARATION_MAX];
    extern structpile pile_representation;
    extern int tab_representation[MAX];
        //  extern int numrep;
    extern structpile pile_region;
    arbre a;
    extern int nbRegion;
    int nb_imbrication = 0;
    extern structlexhc tablelexico[MAX];
    extern TabRegion tabRegion[REGION_MAX];

    int verifVariable(arbre var,arbre a);
    extern int yyerror(const char* erreur);
    int erreur = 0;

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

 /* Mots cle */
%token TANT_QUE FAIRE
%token SI ALORS SINON
%token TABLEAU DE
%token STRUCT FSTRUCT
%token PROG DEBUT FIN
%token TYPE VARIABLE
%token PROCEDURE FONCTION RETOURNE
%token VIDE

 /* Operateur */
%token PLUS MOINS MULT DIV MOD

 /* Operateur booleen */
%token EGAL DIFFERENT
%token SUPERIEUR INFERIEUR
%token SUP_EGAL INF_EGAL

 /* Operateur logique */
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


%union{
    struct noeud * type1;
    int val_i;
 }
%type <type1> expression exp exp1 exp2 exp3
%type <type1> corps liste_instructions suite_liste_inst
%type <type1>  instruction fonc_pre suite_ecriture
%type <type1> condition tant_que affectation declaration_procedure
%type <type1> appel liste_arguments liste_args un_arg resultat_retourne
%type <type1> variable var liste_crochet


%type <val_i> IDF CSTE_BOOLEEN CSTE_ENTIERE CSTE_REEL CSTE_CARACTERE CSTE_CHAINE
%type <val_i> opp_bool liste_parametres liste_param nom_type type_simple decla_suite_var
%type <val_i> liste_champs un_champ
%%

 /*******************************************************/
 /*                         GRAMMAIRE CPYYR                             */
 /*******************************************************/

programme : PROG corps {a = $2;}
;

corps : liste_declarations liste_instructions {$$ = $2;}//afecter $2 dans la table des region en cours
| liste_instructions {$$ = $1;}//afecter $1 dans la table des region en cours
;

liste_declarations : declaration PV
| liste_declarations declaration PV
;

liste_instructions : DEBUT suite_liste_inst FIN {$$ =concat_fils(creer_node(AA_LISTE,-1,-1),$2);}
;

suite_liste_inst : instruction PV {$$ = $1;}
| suite_liste_inst instruction PV {concat_frere(dernier_fils($1),concat_fils(creer_node(AA_LISTE,-1,-1),$2));}
;

/* DECLARATION */
declaration : declaration_type
| declaration_variable
| declaration_procedure
| declaration_fonction
;

declaration_type : TYPE IDF DP STRUCT liste_champs FSTRUCT
{

    if(ajouterDeclaStruct($2 ) == -1) yyerror("Table Decla pleine");
}
| TYPE IDF DP TABLEAU dimension DE nom_type

{
    if (ajouterDeclaTab($2,$7) == -1)
        yyerror("Table Decla pleine");
}
;

/* TABLEAU */
dimension : CO liste_dimensions CF
;

liste_dimensions : une_dimension
| liste_dimensions VIRG une_dimension
;

une_dimension : CSTE_ENTIERE PP CSTE_ENTIERE
{
    if(atoi(tablelexico[$3].chaine)-atoi(tablelexico[$1].chaine) < 0){
       yyerror("Dimension du tableau incorrect");
       exit(-1);
}
    empile(&pile_representation, atoi(tablelexico[$1].chaine));
    empile(&pile_representation, atoi(tablelexico[$3].chaine));
}

;

/* STRUCT */
liste_champs : un_champ PV {}
| liste_champs un_champ PV {}
;

un_champ : IDF DP nom_type {
empile(&pile_representation, $1);
if(ajouterDeclaVar($1, $3)==-1) yyerror("table Decla pleine");}
;

/* TYPE */
nom_type : type_simple {$$ = $1;}
| IDF {$$  = $1;}
;

type_simple : ENTIER {$$ = 0;}
| REEL {$$ = 1;}
| BOOLEEN {$$ = 2;}
| CARACTERE {$$ = 3;}
| CHAINE CO CSTE_ENTIERE CF {$$ = AA_TB_STRING;}
;

declaration_variable : VARIABLE decla_suite_var
;

decla_suite_var : IDF DP nom_type {if (ajouterDeclaVar($1, $3) == -1)
         yyerror("Table Decla pleine");
     $$ = $3;}
| IDF VIRG decla_suite_var {if (ajouterDeclaVar($1, $3) == -1)
          yyerror("Table Decla pleine");
     $$ = $3;}
;

/* FONCTION/PROCEDURE */

declaration_procedure : PROCEDURE {empile(&pile_region,nbRegion++);nb_imbrication++;} IDF liste_parametres corps
{
    ajouterRegion(nb_imbrication,$5);
    if (ajouterDeclaProc($3) == -1)
        yyerror("Table Decla pleine");
    nb_imbrication--;
    depile(&pile_region);
}
;

declaration_fonction : FONCTION {empile(&pile_region,nbRegion++);nb_imbrication++;}  IDF liste_parametres RETOURNE type_simple corps
{
    ajouterRegion(nb_imbrication,$7);
    empile(&pile_representation,$6);
    if (ajouterDeclaFonct($3) == -1)
        yyerror("Table Decla pleine");
    nb_imbrication--;
    depile(&pile_region);
}
;

liste_parametres : PO PF {}
| PO liste_param PF {}
;

liste_param : un_param {}
| liste_param PV un_param {}
;

un_param : IDF DP type_simple{if (ajouterDeclaVar($1, $3) == -1)
         yyerror("Table Decla pleine");}
;

/* -------------- */

instruction : affectation {$$ = $1;}
| condition {$$ = $1;}
| tant_que {$$ = $1;}
| declaration_procedure {$$ = $1;}
| appel {$$ = $1;$$->nature = AA_APPEL_PROC;  }//association de noms sur le nom $$->numlex de la procedure permetant d'obtenir le num de declaration de la procedure et de le stocker dans $$->numdecl
| VIDE {$$ = creer_node(AA_VIDE, -1, -1);}
| RETOURNE resultat_retourne {$$ = concat_fils(creer_node(AA_RETURN, -1, -1),$2);}
| fonc_pre {$$ = $1;}
;

resultat_retourne : {$$ = NULL;}
| expression {$$ = $1;}
;

/* APPEL FONCTION */
appel : IDF liste_arguments {$$ = concat_fils(creer_node(-1, -1, -1), $2);}
;

liste_arguments : PO PF {$$ = NULL;}
| PO liste_args PF {concat_fils(creer_node(AA_LISTE,-1,-1),$2);}
;

liste_args : un_arg {$$ = $1;}
| liste_args VIRG un_arg {concat_frere(dernier_fils($1),concat_fils(creer_node(AA_LISTE,-1,-1),$3));}
;

un_arg : expression {$$ = $1;}
;

/* STRUCTURE CONDITIONNEL */
condition : SI expression ALORS liste_instructions SINON liste_instructions
{
    $$ = concat_fils(creer_node(AA_SI,-1,-1),concat_frere($2,concat_frere($4,$6)));
}
;

tant_que : TANT_QUE PO expression PF FAIRE liste_instructions
{
    $$ = concat_fils(creer_node(AA_TANT_QUE, -1, -1), concat_frere($3, $6));
}
;

/* AFFECTATION */
affectation : variable OPAFF expression
{
  if ( verifVariable($1,$3) == -1){
    yyerror("Erreur d'affectation");
    erreur = 1;
    }
    if (verifVariable($1,$3) == -2){
      yyerror("Variable non déclaré");
      erreur = 1;
    }


    $$ = concat_fils(creer_node(AA_AFFECT, -1, -1), concat_frere($1,$3));
}
;

    /* A definir */
/* VARIABLE */
variable : var { $$ = $1;}
| variable P var {insere_arbre($1,$3);}
;

var : IDF { $$ = creer_node(AA_IDF,$1,-1); }
| IDF liste_crochet
{
    $$ = concat_fils(creer_node(AA_IDF,$1,-1),concat_fils(creer_node(AA_LISTE,-1,-1),$2));
}
;

liste_crochet : CO expression CF
{
    $$ = $2;
}
| liste_crochet CO expression CF
{
    $$=concat_frere(dernier_fils($1),concat_fils(creer_node(AA_LISTE,-1,-1),$3));
}
;

/* EXPRESSION */
expression : expression ET exp {$$ = concat_fils(creer_node(AA_ET,-1,-1), concat_frere($1,$3));}
| expression OU exp {$$ = concat_fils(creer_node(AA_OU,-1,-1), concat_frere($1,$3));}
| exp {$$ = $1;}
;

exp : exp opp_bool exp1 {$$ = concat_fils(creer_node($2,-1,-1), concat_frere($1,$3));}
| exp1 {$$ = $1;}
;

exp1 : exp1 PLUS exp2 {$$ = concat_fils(creer_node(AA_PLUS,-1,-1), concat_frere($1,$3));}
| exp1 MOINS exp2 {$$ = concat_fils(creer_node(AA_MOINS,-1,-1), concat_frere($1,$3));}
| exp2 {$$ = $1;}
;

exp2 : exp2 MULT exp3 {$$ = concat_fils(creer_node(AA_MULT,-1,-1), concat_frere($1,$3));}
| exp2 DIV exp3 {$$ = concat_fils(creer_node(AA_DIV,-1,-1), concat_frere($1,$3));}
| exp2 MOD exp3 {$$ = concat_fils(creer_node(AA_MOD, -1, -1), concat_frere($1,$3));}
| exp3 {$$ = $1;}
;

exp3 : PO expression PF {$$ = $2;}
| CSTE_ENTIERE {$$ = creer_node_cste_ent($1, $1);}
| CSTE_REEL {$$ = creer_node_cste_reel($1, $1);}
| CSTE_CARACTERE {$$ = creer_node_cste_char($1,$1);}
| CSTE_CHAINE {$$ = creer_node_cste_string($1,$1);}
| CSTE_BOOLEEN {$$ = creer_node_cste_bool($1, $1);}
| appel {$$ = $1;$$->nature = AA_APPEL_FCT;} // Association de nom pour l'apelle de fonction
| variable {$$ = $1;}
;

opp_bool : EGAL {$$ = AA_EGAL;}
| DIFFERENT {$$ = AA_DIFF;}
| SUPERIEUR {$$ = AA_SUPP;}
| INFERIEUR {$$ = AA_DIFF;}
| SUP_EGAL  {$$ =AA_SUPP_EG;}
| INF_EGAL {$$ = AA_INF_EG;}
;

/* FONCTION PREDEFINI */
fonc_pre: LIRE liste_arguments {$$ = concat_fils(creer_node(AA_READ,-1,-1), $2);}
| ECRIRE PO CSTE_CHAINE suite_ecriture PF {$$ = concat_fils(creer_node(AA_WRITE, -1, -1), concat_fils(creer_node(AA_LISTE,-1,-1),concat_frere(creer_node(AA_CSTE_STRING, $3, -1),$4)));}
;

suite_ecriture: VIRG expression suite_ecriture {$$ = concat_fils(creer_node(AA_LISTE,-1,-1),concat_frere($2,$3));}
| {$$ = NULL;}
;
%%



int verifVariable(arbre var,arbre a){

  arbre exp = a;
  int nature;

 if (tabDecla[var->numlex].description == -1){
    return -2;
}
/*  if (exp->nature == AA_LISTE)
    exp = exp->fils;

  if(exp->nature == AA_PLUS){
    exp = exp->frere
    while (exp->frere != NULL){
      if (exp->nature == exp->frere->nature)
        return nature;
      else
        return -1;
    }
  }*/


  if (exp->nature == AA_IDF){
    nature = tabDecla[exp->numlex].description;
      if (nature != tabDecla[var->numlex].description)
        return -1;
  }
  if (est_feuille(a)){
    if(exp->nature == AA_CSTE_INT)
      nature = 0;
    if(exp->nature == AA_CSTE_FLOAT)
      nature = 1;
    if(exp->nature == AA_CSTE_CHAR)
      nature = 3;
    if(exp->nature == AA_CSTE_BOOL)
      nature = 2;
    if (exp->nature == AA_IDF)
      nature = tabDecla[exp->numlex].description;

    fprintf(stderr, "%d", tabDecla[exp->numlex].description);
    if (nature != tabDecla[var->numlex].description){
      return -1;
    }
  }
}

int main(){

    int i;
    inittab(lexhashtab, 32);
    initTabDecla();
    init_pile();
    printf( "-------- Debut Compil -------- \n");
    if ( yyparse() != 0 ) {
        return -1;
    }
    if (erreur == 0){
      affiche_lextab(tablelexico);
      afficheTabDecla(tabDecla);
      afficheTabRegion(tabRegion);
      afficher_tabrep(tab_representation);
      afficher_arbre( a, 0);
      printf("\n");
    }
    else
      printf("Compilation Echoue\n");
}
