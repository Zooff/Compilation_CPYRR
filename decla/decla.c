#include "decla.h"

TabDecla tabDecla[DECLARATION_MAX];
int nbDecla = 4;
int numRegion = 1;
int positionDebordement = DEBUT_DEBORDEMENT;
extern TabRegion tabRegion[REGION_MAX];
extern structpile pile_representation;
int tab_representation[MAX];
int numrep=0;

void initTabDecla()
{
    int i;
    for(i=0 ; i<=3 ; i++)
    {
        tabDecla[i].nature = TD_TBASE;
        tabDecla[i].suivant = -1;
        tabDecla[i].region = 1;
        tabDecla[i].description = -1;
        tabDecla[i].execution = 1;
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


int ajouterDeclaStruct(int numLexico, int numeroDescription)
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
        tabDecla[numLexico].description = numeroDescription;
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
        tabDecla[numLexico].description = numeroDescription;
        positionDebordement++;
    }
    return 0;
}


int ajouterDeclaTab(int numLexico, int numeroDescription)
{
    int i;
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
        tabDecla[numLexico].description = numrep;
        tabDecla[numLexico].execution = nbDecla++;
    }
    else
    {
        while(tabDecla[numLexico].suivant != -1)
            numLexico = tabDecla[numLexico].suivant;

        tabDecla[numLexico].suivant = positionDebordement;
        tabDecla[positionDebordement].nature = TD_TAB;
        tabDecla[positionDebordement].suivant = -1;
        tabDecla[positionDebordement].region = numRegion;
        tabDecla[positionDebordement].description = numrep;
        positionDebordement++;
    }
    
    tab_representation[numrep++] =  ((pile_representation.nbrelements)/2); //premier element de la tab_rep est le nombre de dimension du tableau
    tab_representation[numrep++] = numeroDescription; 
    for(i = 0; i<pile_representation.nbrelements ; i++)
    {
        tab_representation[numrep++] =  pile_representation.tabpile[i]; // on copie le tableau de la pile dans le tableau de la tab_rep
    }
    pile_representation.nbrelements = 0;//vide la pile des representation pour avoir une pile propre lors de la prochaine declaration d'objet se stockant dans la table des decla
    return 0;
}


int ajouterDeclaVar(int numLexico, int numeroDescription)
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
        tabDecla[numLexico].description = numeroDescription;
        tabDecla[numLexico].execution =tabRegion[region_actuelle()].taille ;
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
        tabDecla[positionDebordement].description = numeroDescription;
        tabDecla[positionDebordement].execution =tabRegion[region_actuelle()].taille ;
        positionDebordement++;
    }
    tabRegion[region_actuelle()].taille += tabDecla[numeroDescription].execution;// rajoute a la taille de la region actuel la taille d'un element du type de la variable que l'on vient de declarer
        return 0;
}


int ajouterDeclaProc(int numLexico,int numeroDescription)
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
        tabDecla[numLexico].description = numeroDescription;

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
        tabDecla[numLexico].description = numeroDescription;
        positionDebordement++;
    }
    return 0;
}


int ajouterDeclaFonct(int numLexico,int numeroDescription)
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
        tabDecla[numLexico].description = numeroDescription;
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
        tabDecla[numLexico].description = numeroDescription;
        positionDebordement++;
    }
    return 0;
}


void afficheTabDecla(TabDecla tab[])
{
    int i;
    printf("\n-----Table des déclarations-----\n");
    printf(" Numlex\t|Nature\t|Suivant|Région\t| Description\t| Exécution\n");
    for (i=0 ; i<positionDebordement ; i++)
        if(tab[i].nature != -1)
            printf(" %d\t| %d\t| %d\t| %d\t| %d\t\t| %d\n",i, tab[i].nature, tab[i].suivant, tab[i].region, tab[i].description, tab[i].execution);
}

void afficher_tabrep(){
  int i;
  for (i = 0 ; i<numrep ; i++)
    printf(" %d", tab_representation[i]);
  printf("\n");
}

int association_nom(int numlex)
{
    

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
