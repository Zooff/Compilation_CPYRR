#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexhashcode.h"

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

structlexhc lextabhc[1000]; // Tableau qui contient tout les IDF possible
int lexhashtab[31]; // tableau qui contient le premier element des 32 cas possible pour le hashcode
int numlex=4;  // numero lexicographique comence a 4 


/* -------------------------------------------------------------------------- */


void inittab(int* tab,int n) //fonction qui initialise tout les case du tableau a -1 et les 4premier terme au type de base
{
	int i=0;
	for(i=0;i<=n;i++)
	{
		tab[i]=-1;
	}
        lextabhc[0].numerolex=0;
        lextabhc[0].longueur=strlen("entier");
        lextabhc[0].chaine="entier";
        lextabhc[0].suivant=-1;
        lextabhc[1].numerolex=1;
        lextabhc[1].longueur=strlen("réel");
        lextabhc[1].chaine="réel";
        lextabhc[1].suivant=-1;
        lextabhc[2].numerolex=2;
        lextabhc[2].longueur=strlen("booléen");
        lextabhc[2].chaine="booléen";
        lextabhc[2].suivant=-1;
        lextabhc[3].numerolex=3;
        lextabhc[3].longueur=strlen("char");
        lextabhc[3].chaine="char";
        lextabhc[3].suivant=-1;
        
}

int lexstockage( char* idf)
{
	int numhashcode=lexhc(idf);  // Passage de la fonction de hachage 
	int a=lexhashtab[numhashcode]; // a récupère l'indice du premier élément ayant la meme propriété de hachage
	if ( a==-1) // on gere le cas ou il n'y a pas de idf avec le meme numero de hash code 
	{
		lextabhc[numlex].numerolex=numlex;
		lextabhc[numlex].longueur=strlen(idf);
		lextabhc[numlex].chaine=idf;
		lextabhc[numlex].suivant=-1;
		lexhashtab[numhashcode]=numlex;
		numlex++;
		return numlex-1;
      	}
  	else // on gere le cas ou il y a un ou des idf avec le meme numero de hash code 
	{
		while(lextabhc[a].suivant != -1 && strcmp(lextabhc[a].chaine,idf)!=0) // on test s'il y a un suivant et si la chaine n'est pas deja dans le tableau et si il existe un suivant dans le tableau
	    	{
			
	      		a=lextabhc[a].suivant;
	    	}
	  	
		if(strcmp(lextabhc[a].chaine,idf)!=0) // cas lorsque la chaine n'est pas dans le tableau , on effectu toute les affectation puis on incremente numlex
	  	{
			lextabhc[a].suivant = numlex;
			lextabhc[numlex].numerolex=numlex;
		  	lextabhc[numlex].longueur=strlen(idf);
		  	lextabhc[numlex].chaine=idf;
		  	lextabhc[numlex].suivant=-1;
		  	numlex++;
			return numlex-1;
		}
		else // cas si la chaine est deja dans le tableau 
		{
			return lextabhc[a].numerolex;
		}
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
