#include <stdio.h>
#include <stdlib.h>
#include "xmalloc.h"


typedef struct noeud {

  char * nature;
  int numlex;
  int numdecl;
  struct noeud * frere;
  struct noeud * fils;

} noeud;

typedef struct noeud * arbre;


arbre creer_node(char * chaine, int numl, int numd){
  
  arbre node;
  node =(arbre) xmalloc(1, sizeof(noeud));
  
  node->numlex = numl;
  node->numdecl = numd;
  node->nature = chaine;

  return node;
}

arbre concat_fils(arbre pere, arbre fils1){
  
  if (fils1 == NULL)
    return pere;

  pere->fils = fils1;
  
  return pere;
}

arbre concat_frere(arbre pere, arbre frere1){

  if (frere1 == NULL)
    return pere;

  pere->frere = frere1;

  return pere;
}


void free_arbre(arbre a){

  if (a == NULL)
    return;
  
  free_arbre(a->frere);
  free_arbre(a->fils);

  free(a);
}
  
void afficher_arbre(arbre a){

    printf("(%s, %d, %d)", a->nature, a->numlex, a->numdecl);
    printf("\t");
    if(a->frere != NULL)
      afficher_arbre(a->frere);
    printf("\n\t");
    if (a->fils != NULL)
      afficher_arbre(a->fils);
}
/* -------------------------------------------------- */
 

/* Débuggage */
 
int main(int argc, char **argv){
  
  arbre t, t1, t2;
  
  t = creer_node("a", 1, 1);
  t1 = creer_node("b", 2, 2);
  t2 = creer_node("c", 3, 3);
  t = concat_fils(t, t1);
  t = concat_frere(t, t2);
  afficher_arbre(t);
  free_arbre(t);

  return 0;
}
  



