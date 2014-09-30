#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexhc(char* lexeme) // fonction qui calcule le hashcode de la chaine
{
	int i=0;
	int compteur=0;
	for(i=0;i<=strlen(lexeme);i++)
	{
		compteur+=lexeme[i];
	}

return compteur%32;
}

typedef struct structlexhc 
{
	int numerolex;
    	int longueur;
	char* chaine;
	int suivant;
} structlexhc;


structlexhc lextabhc[1000]; // Tableau qui contient tout les IDF possible
int lexhashtab[31]; // tableau qui contient le premier element des 32 cas possible pour le hashcode
int numlex=0;  // numero lexicographique


/* -------------------------------------------------------------------------- */


void inittab(int* tab,int n) //fonction qui initialise tout les case du tableau a -1
{
	int i=0;
	for(i=0;i<=n;i++)
	{
		tab[i]=-1;
	}
}

void lexstockage( char* idf)
{
	int numhashcode=lexhc(idf);  // Passage de la fonction de hachage 
	int a=lexhashtab[numhashcode]; // a récupère l'indice du premier élément ayant la meme propriété de hachage
	if ( a==-1)
	{
		lextabhc[numlex].numerolex=numlex;
		lextabhc[numlex].longueur=strlen(idf);
		lextabhc[numlex].chaine=idf;
		lextabhc[numlex].suivant=-1;
		lexhashtab[numhashcode]=numlex;
		numlex++;
      	}
  	else
	{
		while(lextabhc[a].suivant != -1)
	    	{
	      		a=lextabhc[a].suivant;
	    	}
	  
	  	lextabhc[a].suivant = numlex;
		lextabhc[numlex].numerolex=numlex;
	  	lextabhc[numlex].longueur=strlen(idf);
	  	lextabhc[numlex].chaine=idf;
	  	lextabhc[numlex].suivant=-1;
	  	numlex++;
	}
  
}




// Fonction d'affichage de lextabhc

void affiche_lextab (structlexhc tab[])
{

	int i;
	printf("\n/* --------------lextabhc---------- */\n");
	printf("numlex : longueur : suivant :  chaine     |\n");
	for (i=0;i<20;i++)
	printf(" %d    :      %d  :   %d    :   %s  \n",tab[i].numerolex, tab[i].longueur, tab[i].suivant, tab[i].chaine);
	printf("/* -------------------------------- */ \n\n");
}

void affiche_lexhashtab(int tab[]){
  
	int i;
	printf("\n/* ------------table--achage-------- */\n");
	for(i=0;i<32;i++)
	{
		printf("  %d \n", tab[i]);
	}

	printf("/* -------------------------------- */ \n\n");
}



int main(int argc, char *argv[])
{
  int i;

	inittab(lexhashtab, 32);
	for (i=1;i<argc;i++)
	{
    		lexstockage(argv[i]);
	}
  	affiche_lexhashtab(lexhashtab);
  	affiche_lextab(lextabhc); 
     
    return 0;
}
