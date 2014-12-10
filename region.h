
#include "include.h"


// Structure de la table des régions
typedef struct TabRegion {
  int taille;
  int niveauImbrication;
  arbre arbreRegion;
}TabRegion;

#define REGION_MAX 10


void initTabRegion(); // Fonction qui initialise la table des régions à -1 pour la taille et le NIS et à NULL pour le pointeur vers l'arbre

int ajouterRegion(int taille, int niveauImbrication, arbre arbreRegion); // Fonction qui ajoute une région dans la table

void afficheTabRegion(TabRegion tab[]); // Fonction qui génère l'affichage de la table des régions

