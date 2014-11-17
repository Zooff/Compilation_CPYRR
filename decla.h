#ifndef TABDEC
#define TABDEC


#include "include.h"


#define TD_TBASE 0
#define TD_STRUCT 1
#define TD_TAB 2
#define TD_VAR 3
#define TD_PROC 4
#define TD_FONCT 5

#define DECLARATION_MAX 10000
#define DEBUT_DEBORDEMENT 8000


// Structure du tableau des déclarations
typedef struct TabDecla
{
  int nature;
  int suivant;
  int region;
  int description;
  int execution;
}TabDecla;


void initTabDecla(); // Fonction qui initialise le tableau des déclarations dont les 4 premières cases contiennent les types de base

int ajouterDeclaStruct(int numLexico); // Fonction qui ajoute une structure dans le tableau des déclarations

int ajouterDeclaTab(int numLexico); // Fonction qui ajoute un tableau dans le tableau des déclarations

int ajouterDeclaVar(int numLexico); // Fonction qui ajoute une variable dans le tableau des déclarations

int ajouterDeclaProc(int numLexico); // Fonction qui ajoute une procédure dans le tableau des déclarations

int ajouterDeclaFonct(int numLexico); // Fonction qui ajoute une fonction dans le tableau des déclarations

void afficheTabDecla(TabDecla tab[]); // Fonction qui affiche le tableau des déclarations, avec sa zone de déborbement si besoin


#endif
