#include "region.h"

extern structpile pile_region;
TabRegion tabRegion[REGION_MAX];
int nbRegion = 0;

void initTabRegion() {
  int i;
  for (i=0 ; i<=REGION_MAX ; i++) {
      tabRegion[i].taille = 0; //pour pouvoir incrementer directement
      tabRegion[i].niveauImbrication = -1;
      tabRegion[i].arbreRegion = NULL;
  }
}

int region_actuelle()
{
    return pile_region.tabpile[pile_region.nbrelements-1];
}


int ajouterRegion(int niveauImbrication, arbre arbreRegion) {

  if(nbRegion > REGION_MAX) {
    printf("Erreur, plus de mémoire disponible !\n");
    exit(-1);
  }
  tabRegion[nbRegion].niveauImbrication = niveauImbrication;
  tabRegion[nbRegion].arbreRegion = arbreRegion;
  nbRegion++;
  return 0;
}


void afficheTabRegion(TabRegion tab[]) {

  int i;

  printf("\n-----Table des régions-----\n");
  printf(" Region\t|Taille\t| NIS\t| Arbre\n");
  for (i=0 ; i<=nbRegion ; i++)
    printf(" %d\t| %d\t| %d\t|\n",i, tab[i].taille, tab[i].niveauImbrication);

}

/*
int main(int argc, char **argv) {

  initTabRegion();

  ajouterRegion(50,1,NULL);
  ajouterRegion(23,2,NULL);

  afficheTabRegion(tabRegion);

  return 0;
}*/
