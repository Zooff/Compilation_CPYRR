#include <stdio.h>
#include <stdlib.h>
#include "decla.h"

#define TBASE 0
#define STRUCT 1
#define TAB 2
#define VAR 3
#define PROC 4
#define FONCT 5

#define DECLARATION_MAX 10000
#define DEBUT_DEBORDEMENT 8000


TabDecla tabDecla[DECLARATION_MAX];
int nbDecla = 4;
int numRegion = 1;
int positionDebordement = DEBUT_DEBORDEMENT;


void initTab()
{
  int i;

  for(i=0 ; i<=3 ; i++)
    {
      tabDecla[i].nature = TBASE;
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


void ajouterDeclaStruct(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }
  
  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = STRUCT;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;
	
      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = STRUCT;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;	
    }
}


void ajouterDeclaTab(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = TAB;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;
	
      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = TAB;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;	
    }
}


void ajouterDeclaVar(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = VAR;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;
	
      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = VAR;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;	
    }
}


void ajouterDeclaProc(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = PROC;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;
	
      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = PROC;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;	
    }
}


void ajouterDeclaFonct(int numLexico)
{
  if(nbDecla >= DEBUT_DEBORDEMENT)
    {
      printf("Erreur, plus de mémoire disponible !\n");
      exit(-1);
    }

  if(tabDecla[numLexico].nature == -1)
    {
      tabDecla[numLexico].nature = FONCT;
      tabDecla[numLexico].suivant = -1;
      tabDecla[numLexico].region = numRegion;
      nbDecla++;
    }
  else
    {
      while(tabDecla[numLexico].suivant != -1)
	numLexico = tabDecla[numLexico].suivant;
	
      tabDecla[numLexico].suivant = positionDebordement;
      tabDecla[positionDebordement].nature = FONCT;
      tabDecla[positionDebordement].suivant = -1;
      tabDecla[positionDebordement].region = numRegion;
      positionDebordement++;	
    }
}


void afficheTabDecla(TabDecla tab[])
{
  int i;

  printf("\n-----Table des déclarations-----\n");
  printf(" Numlex\t|Nature\t|Suivant|Région\t| Description\t| Exécution\n");
  for (i=0 ; i<nbDecla ; i++)
    printf(" %d\t| %d\t| %d\t| %d\t| %d\t\t| -1\n",i, tab[i].nature, tab[i].suivant, tab[i].region, tab[i].description);

  if(positionDebordement > DEBUT_DEBORDEMENT)
    {
      printf("-----Zone de débordement-----\n");
      for (i=DEBUT_DEBORDEMENT ; i<positionDebordement ; i++)
	printf(" %d\t| %d\t| %d\t| %d\t| %d\t\t| -1\n",i, tab[i].nature, tab[i].suivant, tab[i].region, tab[i].description);
    }
}


int main(int argc, char **argv)
{
  initTab();  
  ajouterDeclaFonct(4);
  ajouterDeclaVar(4);
  ajouterDeclaStruct(4);
  afficheTabDecla(tabDecla);
  
  return EXIT_SUCCESS;
}

