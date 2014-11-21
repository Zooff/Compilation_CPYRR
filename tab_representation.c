#include "tab_representation.h"

structpile pile_representation;
int tab_representation[MAX];
int numrep=0;

void stockage_representation(int nombre,int nbr)
{

  empile(&pile_representation,nbr);
  empile(&pile_representation,nombre);

}


int stock_rep(structpile * pile, int numr){
  int a = numr;
  while (!est_vide(pile)){
    tab_representation[a] = depile(pile);
    a++;
  }
  numrep = a;
  return numr;
}

void afficher_tabrep(int tab[]){
  int i;
  for (i = 0;i<numrep;i++)
    printf(" | %d", tab[i]);
  printf("\n");
}
