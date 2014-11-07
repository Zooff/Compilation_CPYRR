#ifndef TABDEC
#define TABDEC


#include "include.h"

// Structure du tableau des déclarations
typedef struct TabDecla
{
  int nature;
  int suivant;
  int region;
  int description;
  int execution;
}TabDecla;


void initTab(); // Fonction qui initialise le tableau des déclarations dont les 4 premières cases contiennent les types de base

void ajouterDeclaStruct(int numLexico); // Fonction qui ajoute une structure dans le tableau des déclarations

void ajouterDeclaTab(int numLexico); // Fonction qui ajoute un tableau dans le tableau des déclarations

void ajouterDeclaVar(int numLexico); // Fonction qui ajoute une variable dans le tableau des déclarations

void ajouterDeclaProc(int numLexico); // Fonction qui ajoute une procédure dans le tableau des déclarations

void ajouterDeclaFonct(int numLexico); // Fonction qui ajoute une fonction dans le tableau des déclarations

void afficheTabDecla(TabDecla tab[]); // Fonction qui affiche le tableau des déclarations, avec sa zone de déborbement si besoin


#ifndef
