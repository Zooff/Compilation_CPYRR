#define TaillePiles 1000

typedef struct structpile // structure pile
{
    int tabpile[TaillePiles]; // pile avec taille max egale a 1000
        int nbrelements;//nombre d'element dans la pile
} structpile;



void init_pile(structpile* pile);//fonction qui initialise la pile 

void empile(structpile* pile,int elem); //fonction qui empile un element dans le tableau

void depile(structpile* pile);//fonction qui depile le tableau d'un element 
