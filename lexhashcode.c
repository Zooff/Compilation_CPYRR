
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

structlexhc tablelexico[MAX]; // Tableau qui contient tout les IDF possible
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
        tablelexico[0].numerolex=0;
        tablelexico[0].longueur=strlen("entier");
        strcpy(tablelexico[0].chaine,"entier");
        tablelexico[0].suivant=-1;
        tablelexico[1].numerolex=1;
        tablelexico[1].longueur=strlen("réel");
        strcpy(tablelexico[1].chaine,"réel");
        tablelexico[1].suivant=-1;
        tablelexico[2].numerolex=2;
        tablelexico[2].longueur=strlen("booléen");
        strcpy(tablelexico[2].chaine,"booléen");
        tablelexico[2].suivant=-1;
        tablelexico[3].numerolex=3;
        tablelexico[3].longueur=strlen("char");
        strcpy(tablelexico[3].chaine,"char");
        tablelexico[3].suivant=-1;

}

int lexstockage( char* idf)
{
	int numhashcode=lexhc(idf);  // Passage de la fonction de hachage
	int a=lexhashtab[numhashcode]; // a récupère l'indice du premier élément ayant la meme propriété de hachage
	if(numlex >= MAX)
		return -1;
	if ( a==-1) // on gere le cas ou il n'y a pas de idf avec le meme numero de hash code
	{
		tablelexico[numlex].numerolex=numlex;
		tablelexico[numlex].longueur=strlen(idf);
		strcpy(tablelexico[numlex].chaine,idf);
		tablelexico[numlex].suivant=-1;
		lexhashtab[numhashcode]=numlex;
		numlex++;
		return numlex-1;
      	}
  	else // on gere le cas ou il y a un ou des idf avec le meme numero de hash code
	{
		while(tablelexico[a].suivant != -1 && strcmp(tablelexico[a].chaine,idf)!=0) // on test s'il y a un suivant et si la chaine n'est pas deja dans le tableau et si il existe un suivant dans le tableau
	    	{

	      		a=tablelexico[a].suivant;
	    	}

		if(strcmp(tablelexico[a].chaine,idf)!=0) // cas lorsque la chaine n'est pas dans le tableau , on effectu toute les affectation puis on incremente numlex
	  	{
			tablelexico[a].suivant = numlex;
			tablelexico[numlex].numerolex=numlex;
		  tablelexico[numlex].longueur=strlen(idf);
		  strcpy(tablelexico[numlex].chaine,idf);
		  tablelexico[numlex].suivant=-1;
		  numlex++;
			return numlex-1;
		}
		else if (strcmp(tablelexico[a].chaine, idf) ==0) // cas si la chaine est deja dans le tableau
		{
			return tablelexico[a].numerolex;
		}
	}

}




// Fonction d'affichage de tablelexico

void affiche_lextab (structlexhc tab[])
{

	int i;
	printf("\n/* --------------tablelexico---------- */\n");
	printf("numlex : longueur : suivant :  chaine     |\n");
	for (i=0;i<numlex;i++)
	fprintf(stderr, " %d    :      %d  :   %d    :   %s  \n",tab[i].numerolex, tab[i].longueur, tab[i].suivant, tab[i].chaine);
	printf("/* -------------------------------- */ \n\n");
}

void affiche_lexhashtab(int tab[]){

	int i;
	printf("\n/* ------------table--hachage-------- */\n");
	for(i=0;i<32;i++)
	{
		printf("  %d \n", tab[i]);
	}

	printf("/* -------------------------------- */ \n\n");
}


/* Débugage */
/*int main(int argc, char *argv[])
{
  int i;


	inittab(lexhashtab, 32);

        for (i=1;i<argc;i++)
	{
    		lexstockage(argv[i]);
	}
  	affiche_lexhashtab(lexhashtab);
  	affiche_lextab(tablelexico);

    return 0;
}
*/
