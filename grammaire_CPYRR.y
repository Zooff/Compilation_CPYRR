/*                   Fichier YACC du language CPYRR                         */
/*                       Auteur : Dimitri ESCALLE                           */
/* Contient la grammaire neccesaire au bon fonctionnement du langages CPYRR */






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


%%

 /*******************************************************/
 /*                  GRAMMAIRE CPYYR                    */
 /*******************************************************/

programme : PROG corps
          ;

corps : liste_declarations liste_instructions
      | liste_instructions
      ;

liste_declarations : declaration PV
                   | liste_declarations declaration PV
                   ;

liste_instructions : DEBUT suite_liste_inst FIN
                   ;

suite_liste_inst : instruction PV
                 | suite_liste_inst instruction PV
                 ;

/* DECLARATION */

declaration : declaration_type
            | declaration_variable
            | declaration_procedure
            | declaration_fonction
            ;

declaration_type : TYPE IDF DP suite_declaration_type
                 ;

suite_declaration_type : STRUCT liste_champs FSTRUCT
                       | TABLEAU dimension DE nom_type
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

nom_type : type_simple
         | IDF
         ;

type_simple : ENTIER
            | REEL
            | BOOLEEN
            | CARACTERE
            | CHAINE CO CSTE_ENTIERE CF
            ;

/* ----------- */

declaration_variable : VARIABLE liste_IDF DP nom_type 
                     ;

liste_IDF : IDF 
          | liste_IDF VIRG IDF
          ; 

/* FONCTION/PROCEDURE */

declaration_procedure : PROCEDURE IDF liste_parametres corps
                      ;

declaration_fonction : FONCTION IDF liste_parametres RETOURNE type_simple corps
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
            | condition
            | tant_que
            | declaration_procedure
            | appel
            | VIDE
            | RETOURNE resultat_retourne
            ;

resultat_retourne :
                  | expression
		  ;


/* APPEL FONCTION */

appel : IDF liste_arguments
      ;

liste_arguments : PO PF
                | PO liste_args PF
		;

liste_args : un_arg
           | liste_args VIRG un_arg
           ;

un_arg : expression
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
           | exp
           ;

exp : exp opp_bool exp1
    | exp1
    ;

exp1 : exp1 PLUS exp2
     | exp1 MOINS exp2
     | exp2
     ;

exp2 : exp2 MULT exp3
     | exp2 DIV exp3
     | exp2 MOD exp3
     | exp3
     ;

exp3 : PO expression PF
     | CSTE_ENTIERE
     | CSTE_REEL
     | CSTE_CARACTERE
     | CSTE_CHAINE
     | CSTE_BOOLEEN
     | appel
     | variable
     ;

opp_bool : EGAL
         | DIFFERENT
         | SUPERIEUR
         | INFERIEUR
         | SUP_EGAL
         | INF_EGAL
         ;


%%
