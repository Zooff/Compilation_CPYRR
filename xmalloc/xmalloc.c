#include "xmalloc.h"

void * xmalloc(size_t nbbloc, size_t tailleob){
  void* pt;
  pt = malloc(nbbloc * tailleob);
  if (pt == NULL){
    printf(" Erreur d'allocation mémoire ");
    return NULL;
  }
  return (pt);
}
