
#include "decla.h"




TabDecla tabDecla[DECLARATION_MAX];
int nbDecla = 4;
int numRegion = 1;
int positionDebordement = DEBUT_DEBORDEMENT;


void initTabDecla()
{
  int i;

  for(i=0 ; i<=3 ; i++)
    {
      tabDecla[i].nature = TD_TBASE;
      tabDecla[i].suivant = -1;
      tabDecla[i].region = 1;
      tabDecla[i].description = -1;
      tabDecla[i].execution = -1;
    }

  for(i=4 ; i<=DECLARATION_MAX ; i++)
    {
      tabDecla[i].nature = -1;
      tabDecla[i].suivant = -1;
      tabDecla[i].region = -1;
      tabDecla[i].description = -1;
      tabDecla[i].execution = -1;
    }
}


int ajouterDeclaStruct(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      return (-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TD_STRUCT;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;

      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TD_STRUCT;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;
    }
    return 0;
}


int ajouterDeclaTab(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TD_TAB;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;

      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TD_TAB;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;
    }
    return 0;
}


int ajouterDeclaVar(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      return (-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TD_VAR;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
        numLexico = tabDecla[numLexico].suivant;

      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TD_VAR;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;
    }
    return 0;
}


int ajouterDeclaProc(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      return (-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TD_PROC;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;

      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TD_PROC;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;
    }
    return 0;
}


int ajouterDeclaFonct(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      return (-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TD_FONCT;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;

      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TD_FONCT;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;
    }
    return 0;
}


void afficheTabDecla(TabDecla tab[])
{
  int i;

  printf("\n-----Table des déclarations-----\n");
  printf(" Numlex\t|Nature\t|Suivant|Région\t| Description\t| Exécution\n");
  for (i=0 ; i<nbDecla+2 ; i++)
    printf(" %d\t| %d\t| %d\t| %d\t| %d\t\t| -1\n",i, tab[i].nature, tab[i].suivant, tab[i].region, tab[i].description);

  if(positionDebordement > DEBUT_DEBORDEMENT)
    {
      printf("-----Zone de débordement-----\n");
      for (i=DEBUT_DEBORDEMENT ; i<positionDebordement ; i++)
	printf(" %d\t| %d\t| %d\t| %d\t| %d\t\t| -1\n",i, tab[i].nature, tab[i].suivant, tab[i].region, tab[i].description);
    }
}

/*
int main(int argc, char **argv)
{
  initTab();
  ajouterDeclaFonct(4);
  ajouterDeclaVar(4);
  ajouterDeclaStruct(4);
  afficheTabDecla(tabDecla);

  return EXIT_SUCCESS;
}
*/
