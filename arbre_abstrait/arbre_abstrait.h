/*        Arbre_abstrait.h       */
/* Auteur : Dimitri ESCALLE */
#ifndef ARBRE
#define ARBRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Type simple */
#define AA_TB_INT 0
#define AA_TB_FLOAT 1
#define AA_TB_BOOL 2
#define AA_TB_CHAR 3
#define AA_TB_STRING 4

/* Operateur */
#define AA_PLUS 33
#define AA_MOINS 34
#define AA_MULT 35
#define AA_DIV 36
#define AA_MOD 37

/* Comparateur */
#define AA_SUPP 5
#define AA_INF 6
#define AA_EGAL 7
#define AA_DIFF 8
#define AA_SUPP_EG 9
#define AA_INF_EG 10

/* Opérateur Booléen */
#define AA_ET 11
#define AA_OU 12

/* Conditionnel */
#define AA_SI 13
#define AA_ALORS 14
#define AA_TANT_QUE 15

/* Controlleur */
#define AA_APPEL_PROC 16
#define AA_RETURN 20
#define AA_APPEL_FCT 21


/* Affectation */
#define AA_AFFECT 22

/* Constante */
#define AA_CSTE_INT 23
#define AA_CSTE_FLOAT 24
#define AA_CSTE_BOOL 25
#define AA_CSTE_CHAR 26
#define AA_CSTE_STRING 27

/* Fonction Predefini */
#define AA_WRITE 28
#define AA_READ 29

/* Vide */
#define AA_VIDE 30

/* IDF */
#define AA_IDF 31

/* Tableau */
#define AA_TAB 32
#define AA_P 38

/*Liste */
#define AA_LISTE 39

typedef struct noeud {
  int nature;  //Nature du noeud ex : "AA_PLUS"
  int numlex; // Numero lexicographique
  int numdecl; // Numero de declaration
  struct noeud * frere;
  struct noeud * fils;
} noeud;

typedef struct noeud * arbre;

// Fonction de creation de noeud de l'arbre
arbre creer_node(int chaine, int numl, int numd);

//Fonction qui cree un arbre de nature constante entiere
arbre creer_node_cste_ent(int numl, int numd);

//Fonction qui cree un arbre de nature constante flottante
arbre creer_node_cste_reel(int numl, int numd);

//Fonction qui cree un arbre de nature constante booleene
arbre creer_node_cste_bool(int numl, int numd);

//Fonction qui cree un arbre de nature constante charactere
arbre creer_node_cste_char(int numl, int numd);

//Fonction qui cree un arbre de nature constante chaine
arbre creer_node_cste_string(int numl, int numd);

//Fonction qui assigne le pointeur fils du pere
arbre concat_fils(arbre pere, arbre fils1);

//Fonction qui assigne le pointeur frere du pere
arbre concat_frere(arbre pere, arbre frere1);

// Fonction de liberation de l'arbre
void free_arbre(arbre a);

char * afficherDefineArbre(int n);

//Fonction d'affichage
void afficher_arbre(arbre a, int espace);

//Fonction dernier fils
arbre dernier_fils(arbre a);

int est_feuille(arbre a);

//fonction inserer arbre
void insere_arbre(arbre x , arbre y);

#endif
