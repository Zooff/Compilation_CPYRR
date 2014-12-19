#include "decla.h"

TabDecla tabDecla[DECLARATION_MAX];
int nbDecla = 4;
int numRegion = 1;
int positionDebordement = DEBUT_DEBORDEMENT;
extern TabRegion tabRegion[REGION_MAX];
extern structpile pile_representation;
extern structpile pile_region;
int tab_representation[MAX];
int numrep=0;

int tailleStruct(){
  int i, res = 0;
  for (i = 0; i<pile_representation.nbrelements; i++){
    res += tabDecla[tabDecla[pile_representation.tabpile[i]].description].execution;
  }
  return res;
}
int taille_tab()
{
    int i=0;
    int j=1;
    for(i=0;i<pile_representation.nbrelements-1;i+=2)
        j*= pile_representation.tabpile[i+1]-pile_representation.tabpile[i];
    return j;
}

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


int ajouterDeclaStruct(int numLexico)
{
    int i;
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
        tabDecla[numLexico].description = numrep;
        tabDecla[numLexico].execution = tailleStruct();
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
        tabDecla[positionDebordement].description = numrep;
        tabDecla[positionDebordement].execution = tailleStruct();
        positionDebordement++;
    }
    tab_representation[numrep++] =  pile_representation.nbrelements; //premier element de la tab_rep est le nombre de champs de la struct
    for(i = 0; i<pile_representation.nbrelements ; i++)
    {
        tab_representation[numrep++] =  pile_representation.tabpile[i]; // on copie le tableau de la pile dans le tableau de la tab_rep
        tab_representation[numrep++] =  tabDecla[pile_representation.tabpile[i]].description;
        if (i == 0)
          tab_representation[numrep++] =  0;
        else
          tab_representation[numrep++] = tabDecla[pile_representation.tabpile[i]].execution + tab_representation[numrep -4];
    }
    pile_representation.nbrelements = 0;//vide la pile des representation pour avoir une pile propre lors de la prochaine declaration d'objet se stockant dans la table des decla
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
        tabDecla[numLexico].execution = taille_tab()*tabDecla[numeroDescription].execution;
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
        tabDecla[positionDebordement].execution = taille_tab()*tabDecla[numeroDescription].execution;
        positionDebordement++;
    }


    tab_representation[numrep++] =  ((pile_representation.nbrelements)/2); //premier element de la tab_rep est le nombre de dimension du tableau
    tab_representation[numrep++] = numeroDescription; //numeroDescription est le type du tableau
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
        tabDecla[numLexico].region = region_actuelle();
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
        tabDecla[positionDebordement].region = region_actuelle();
        tabDecla[positionDebordement].description = numeroDescription;
        tabDecla[positionDebordement].execution =tabRegion[region_actuelle()].taille ;
        positionDebordement++;
    }
    tabRegion[region_actuelle()].taille += tabDecla[numeroDescription].execution;// rajoute a la taille de la region actuel la taille d'un element du type de la variable que l'on vient de declarer
        return 0;
}


int ajouterDeclaProc(int numLexico)
{
    int i;

    if(nbDecla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, plus de mémoire disponible !\n");
        return (-1);
    }

    if(tabDecla[numLexico].nature == -1)
    {
        tabDecla[numLexico].nature = TD_PROC;
        tabDecla[numLexico].suivant = -1;
        tabDecla[numLexico].region = pile_region.tabpile[pile_region.nbrelements-2];
        tabDecla[numLexico].description = numrep;
        tabDecla[numLexico].execution = pile_region.tabpile[pile_region.nbrelements-1];
        nbDecla++;
    }
    else
    {
        while(tabDecla[numLexico].suivant != -1)
            numLexico = tabDecla[numLexico].suivant;

        tabDecla[numLexico].suivant = positionDebordement;
        tabDecla[positionDebordement].nature = TD_PROC;
        tabDecla[positionDebordement].suivant = -1;
        tabDecla[positionDebordement].region = pile_region.tabpile[pile_region.nbrelements-2];
        tabDecla[positionDebordement].description = numrep;
        tabDecla[positionDebordement].execution =pile_region.tabpile[pile_region.nbrelements-1];
        positionDebordement++;
    }

    tab_representation[numrep++] = pile_representation.nbrelements;
    for(i = 0; i<pile_representation.nbrelements; i++)
    {
        tab_representation[numrep++] = pile_representation.tabpile[i];
        tab_representation[numrep++] = tabDecla[pile_representation.tabpile[i]].description;
    }
    pile_representation.nbrelements = 0;

    return 0;
}


int ajouterDeclaFonct(int numLexico)
{
    int i;

    if(nbDecla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, plus de mémoire disponible !\n");
        return (-1);
    }

    if(tabDecla[numLexico].nature == -1)
    {
        tabDecla[numLexico].nature = TD_FONCT;
        tabDecla[numLexico].suivant = -1;
        tabDecla[numLexico].region =  pile_region.tabpile[pile_region.nbrelements-2];
        tabDecla[numLexico].description = numrep;
        tabDecla[numLexico].execution =pile_region.tabpile[pile_region.nbrelements-1];
        nbDecla++;
    }
    else
    {
        while(tabDecla[numLexico].suivant != -1)
            numLexico = tabDecla[numLexico].suivant;

        tabDecla[numLexico].suivant = positionDebordement;
        tabDecla[positionDebordement].nature = TD_FONCT;
        tabDecla[positionDebordement].suivant = -1;
        tabDecla[positionDebordement].region =  pile_region.tabpile[pile_region.nbrelements-2];
        tabDecla[positionDebordement].description = numrep;
        tabDecla[positionDebordement].execution =pile_region.tabpile[pile_region.nbrelements-1];
        positionDebordement++;
    }

    tab_representation[numrep++] = pile_representation.nbrelements-1;
    for(i = 0; i<pile_representation.nbrelements-1; i++)
    {
        tab_representation[numrep++] =  pile_representation.tabpile[i];
        tab_representation[numrep++] = tabDecla[pile_representation.tabpile[i]].description;
    }
    tab_representation[numrep++] = pile_representation.tabpile[pile_representation.nbrelements-1];
    pile_representation.nbrelements = 0;

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
