#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexhashcode.h"
#include "pile.h"



void init_pile(structpile* pile)
{
    (*pile).nbrelements=0; //on initialise le nombre d'element a 0
}


void empile(structpile* pile,int elem)
{
    if ((*pile).nbrelements==TaillePiles)
    {
        printf("Impossible d'empile la pile est pleine");// si la pile est pleine on ne peut pas empile
    }
    else 
    {
        int a=(*pile).nbrelements;
        (*pile).tabpile[a]=elem; //met l'element a la case nbr_elements car les tableau commence a 0
        (*pile).nbrelements+=1;// et on augmente le nbr d'element de la pile d'un
    }
}

void depile(structpile* pile)
{
    if ((*pile).nbrelements==0)
    {
        fprintf(stderr,"Impossible de depiler, la pile est vide");// si la pile est vide on ne peut pas depile
    }
    else 
    {
        (*pile).tabpile[(*pile).nbrelements-1]=-1;// on suprime le dernier element du tableau
        (*pile).nbrelements-=1;// et on decremente le nbr d'element d'un
    }
}

int main(int argc, char *argv[])
{
	int i;
	structpile testpile;
	init_pile(&testpile);
	empile(&testpile,79);
	depile(&testpile);
	for(i=0;i<5;i++)
	{
		printf("%d\n",testpile.tabpile[i]);
	}
	
    return 0;
}
