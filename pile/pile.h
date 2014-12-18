#ifndef PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TaillePiles 1000

typedef struct structpile // structure pile
{
    int tabpile[TaillePiles]; // pile avec taille max egale a 1000
    int nbrelements;//nombre d'element dans la pile
} structpile;


int  est_vide(structpile* pile);

void init_pile();//fonction qui initialise la pile

void empile(structpile* pile,int elem); //fonction qui empile un element dans le tableau

int depile(structpile* pile);//fonction qui depile le tableau d'un element

void inverse(structpile* pile);//fonction qui inverse la pile

#endif
