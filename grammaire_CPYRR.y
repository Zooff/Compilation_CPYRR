/*                   Fichier YACC du language CPYRR                         */
/*        Auteur : Dimitri ESCALLE DA COSTA VAZ Julien NAIDJI Nabil         */
/* Contient la grammaire neccesaire au bon fonctionnement du langages CPYRR */

%{

#include "include.h"


/* Variable table lexicographique */

extern structlexhc tablelexico[MAX]; // Tableau qui contient tout les IDF possible
extern int lexhashtab[31]; // tableau qui contient le premier element des 32 cas possible pour le hashcode
extern int numlex;  // numero lexicographique comence a 4

/* ------- ------ */
 extern TabDecla tabDecla[DECLARATION_MAX];

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

 /* Mots cl� */

%token TANT_QUE FAIRE
%token SI ALORS SINON

%token TABLEAU DE
%token STRUCT FSTRUCT

%token PROG DEBUT FIN
%token TYPE VARIABLE

%token PROCEDURE FONCTION RETOURNE

%token VIDE

 /* Op�rateur */

%token PLUS MOINS MULT DIV MOD

 /* Op�rateur booleen */

%token EGAL DIFFERENT
%token SUPERIEUR INFERIEUR
%token SUP_EGAL INF_EGAL

 /* Op�rateur logique */

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

/* --------------------------------------------------------------------------------- */

%union{
struct noeud * type1;
int type2;
}


%type <type1> expression exp exp1 exp2 exp3
%type <type1> corps liste_instructions suite_liste_inst nom_type type_simple
%type <type1> decla_suite_var instruction fonc_pre suite_ecriture
%type <type1> condition tant_que affectation declaration_procedure
%type <type1> appel liste_arguments liste_args un_arg resultat_retourne

%type <type1> variable liste_var var


%type <type2> IDF CSTE_BOOLEEN CSTE_ENTIERE CSTE_REEL CSTE_CARACTERE CSTE_CHAINE
%type <type2> opp_bool



%%

 /*******************************************************/
 /*                         GRAMMAIRE CPYYR                             */
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
     if (ajouterDeclaStruct($2) == -1)
       yyerror("Table Decla pleine");
  }
                           | TYPE IDF DP TABLEAU dimension DE nom_type
  {
     if (ajouterDeclaTab($2) == -1)
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
         | IDF {$$  = creer_node(AA_IDF, -1, -1);}
         ;

type_simple : ENTIER {$$ = creer_node(AA_TB_INT, -1, -1);}
            | REEL {$$ = creer_node(AA_TB_FLOAT, -1, -1);}
            | BOOLEEN {$$ = creer_node(AA_TB_BOOL, -1, -1);}
            | CARACTERE {$$ = creer_node(AA_TB_CHAR, -1, -1);}
            | CHAINE CO CSTE_ENTIERE CF {$$ = creer_node(AA_TB_STRING, -1, -1);}
            ;

/* ----------- */

declaration_variable : VARIABLE decla_suite_var
                     ;

decla_suite_var : IDF DP nom_type {if (ajouterDeclaVar($1) == -1)
                                                           yyerror("Table Decla pleine");
                                                        $$ = $3;}
                        | IDF VIRG decla_suite_var {if (ajouterDeclaVar($1) == -1)
                                                                     yyerror("Table Decla pleine");
                                                                    $$ = $3;}
          ;

/* FONCTION/PROCEDURE */

declaration_procedure : PROCEDURE {nb_region++;} IDF liste_parametres corps
  {
    if(ajouterDeclaProc($3) == -1)
      yyerror("Table Decla pleine");
  }
                      ;

declaration_fonction : FONCTION {nb_region++;}  IDF liste_parametres RETOURNE type_simple corps
  {
    if (ajouterDeclaFonct($3) == -1)
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
            | appel {$$ = $1;}
            | VIDE {$$ = creer_node(AA_VIDE, -1, -1);}
            | RETOURNE resultat_retourne {$$ = creer_node(AA_RETURN, -1, -1);}
            | fonc_pre {$$ = $1;}
            ;

resultat_retourne : {$$ = NULL;}
                            | expression {$$ = $1;}
		                        ;


/* APPEL FONCTION */

appel : IDF liste_arguments {$$ = concat_fils(creer_node(AA_APPEL_FCT, -1, -1), $2);}
      ;

liste_arguments : PO PF {$$ = NULL;}
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
  {
     $$ = concat_fils(concat_frere(creer_node(AA_SI, -1, -1), concat_frere($2,$4)), concat_frere(creer_node(AA_ALORS, -1, -1), $6));
}
          ;

tant_que : TANT_QUE PO expression PF FAIRE liste_instructions
  {
     $$ = concat_fils(creer_node(AA_TANT_QUE, -1, -1), concat_frere($3, $6));
}
         ;

/* -------- */

/* AFFECTATION */

affectation : variable OPAFF expression {$$ = concat_fils(creer_node(AA_AFFECT, -1, -1), concat_frere($1,$3));}
            ;

                                  /* A d�finir */


/* VARIABLE */



variable : IDF CO liste_var CF var {$$ = concat_frere(concat_fils(creer_node(AA_TAB, -1 ,-1), $3), $5);}
             | IDF var {$$ = concat_frere($$, $2);}
             ;

liste_var : expression {$$ = $1;}
          | liste_var VIRG expression {$$ = concat_frere($$, $1);}
          ;

var : P variable {$$ = concat_frere($$, $2);}
    | {$$ = NULL;}
    ;

/* ---------- */

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
     | appel {$$ = $1;}
     | variable {$$ = $1;}
     ;

opp_bool : EGAL {$$ = AA_EGAL;}
         | DIFFERENT {$$ = AA_DIFF;}
         | SUPERIEUR {$$ = AA_SUPP;}
         | INFERIEUR {$$ = AA_DIFF;}
         | SUP_EGAL  {$$ =AA_SUPP_EG;}
         | INF_EGAL {$$ = AA_INF_EG;}
         ;

/* ------------- */

/* FONCTION PREDEFINI */

fonc_pre: LIRE PO liste_variables PF {$$ = concat_fils(creer_node(AA_READ,-1,-1), $3);}
        | ECRIRE PO format suite_ecriture PF {$$ = concat_fils(creer_node(AA_WRITE, -1, -1), concat_frere($3, $4);}
        ;

suite_ecriture: VIRG variable suite_ecriture
              | {$$ = NULL;}
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


 printf( "-------- D�but Compil -------- \n");

 printf("%d\n", numlex);

 if ( yyparse() != 0 ) {
   fprintf(stderr,"Syntaxe incorrecte\n");
   return -1;
 }

 affiche_lextab(tablelexico);
 afficheTabDecla(tabDecla);

}
