
#ifndef LEXTAB
#define LEXTAB

#include "include.h"

typedef struct structlexhc // structure table lexicografique
{
	int numerolex;
	int longueur;
	char chaine[256];
	int suivant;
} structlexhc;


int lexhc(char* lexeme); // fonction qui calcule le hashcode de la chaine




/* -------------------------------------------------------------------------- */


void inittab(int* tab,int n); //fonction qui initialise tout les case du tableau a -1 et les 4premier terme au type de base


int lexstockage( char* idf);//fonction qui stock un idf et return son numlex



void affiche_lextab (structlexhc tab[]);// Fonction d'affichage de lextabhc , les 20 premiers


void affiche_lexhashtab(int tab[]);//fonction qui afiche la table de hashcode



#endif
