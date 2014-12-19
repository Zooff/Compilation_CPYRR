#include "arbre_abstrait.h"

arbre creer_node(int chaine, int numl, int numd){
    arbre node;
    node =(arbre) xmalloc(1, sizeof(noeud));
    node->numlex = numl;
    node->numdecl = numd;
    node->nature = chaine;
    return node;
}

arbre dernier_fils(arbre a)
{
    while(a->frere != NULL)
    {
        a=a->frere->fils;
    }
    return a;
}

void insere_arbre(arbre x , arbre y)
{
    while((x->fils != NULL) && (x->fils->frere != NULL))
    {
        x = x->fils->frere;
    }
    if(x->fils == NULL)
    {
        concat_fils(x,concat_frere(creer_node(AA_LISTE,-1,-1),y));
    }
    else
    {
        concat_frere(x->fils,y);
    }
}

int est_feuille(arbre a){
  return (a->fils == NULL && a->frere);
}


arbre creer_node_cste_ent(int numl, int numd){
    arbre node = creer_node(AA_CSTE_INT, numl, numd);
    return node;
}

arbre creer_node_cste_reel(int numl, int numd){
    arbre node = creer_node(AA_CSTE_FLOAT, numl, numd);
    return node;
}

arbre creer_node_cste_bool(int numl, int numd){
    arbre node = creer_node(AA_CSTE_BOOL, numl, numd);
    return node;
}

arbre creer_node_cste_char(int numl, int numd){
    arbre node = creer_node(AA_CSTE_CHAR, numl, numd);
    return node;
}

arbre creer_node_cste_string(int numl, int numd){
    arbre node = creer_node(AA_CSTE_STRING, numl, numd);
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


char* afficherDefineArbre(int n) {

    switch(n) {
        case 33:
            return "AA_PLUS";
            break;
        case 34:
            return "AA_MOINS";
            break;
        case 35:
            return "AA_MULT";
            break;
        case 36:
            return "AA_DIV";
            break;
        case 37:
            return "AA_MOD";
            break;
        case 5:
            return "AA_SUPP";
            break;
        case 6:
            return "AA_INF";
            break;
        case 7:
            return "AA_EGAL";
            break;
        case 8:
            return "AA_DIFF";
            break;
        case 9:
            return "AA_SUPP_EG";
            break;
        case 10:
            return "AA_INF_EG";
            break;
        case 11:
            return "AA_ET";
            break;
        case 12:
            return "AA_OU";
            break;
        case 13:
            return "AA_SI";
            break;
        case 14:
            return "AA_ALORS";
            break;
        case 15:
            return "AA_TANT_QUE";
            break;
        case 16:
            return "afficher_arbre(arbre a)";
            break;
        case 20:
            return "AA_RETURN";
            break;
        case 21:
            return "AA_APPEL_FCT";
            break;
        case 22:
            return "AA_AFFECT";
            break;
        case 23:
            return "AA_CSTE_INT";
            break;
        case 24:
            return "AA_CSTE_FLOAT";
            break;
        case 25:
            return "AA_CSTE_BOOL";
            break;
        case 26:
            return "AA_CSTE_CHAR";
            break;
        case 27:
            return "AA_CSTE_STRING";
            break;
        case 28:
            return "AA_WRITE";
            break;
        case 29:
            return "AA_READ";
            break;
        case 30:
            return "AA_VIDE";
            break;
        case 31:
            return "AA_IDF";
            break;
        case 32:
            return "AA_TAB";
            break;
        case 0:
            return "AA_TB_INT";
            break;
        case 1:
            return "AA_TB_FLOAT";
            break;
        case 2:
            return "AA_TB_BOOL";
            break;
        case 3:
            return "AA_TB_CHAR";
            break;
        case 4:
            return "AA_TB_STRING";
            break;
        case 38:
            return "AA_P";
            break;
        case 39:
            return "AA_LISTE";
            break;

        default:
            return "Nombre invalide";
            break;
    }

}



void afficher_arbre(arbre a, int espace){
    int i;
    if(a != NULL){
        printf("(%s, %d, %d)",afficherDefineArbre(a->nature), a->numlex, a->numdecl);

        if(a->frere != NULL)
            printf("\n\t");
        for(i=0 ; i<espace ; i++)
            printf(" ");
        afficher_arbre(a->frere, espace+2);

        if (a->fils != NULL)
            printf("\n\t");
        for(i=0 ; i<espace ; i++)
            printf(" ");
        afficher_arbre(a->fils, espace +2);
    }
}



/* -------------------------------------------------- */


/* Débuggage */

/*int main(int argc, char **argv){

  arbre t, t1, t2;

  t = creer_node(AA_PLUS, 1, 1);
  t1 = creer_node(AA_MOINS, 2, 2);
  t2 = creer_node(AA_CSTE_INT, 3, 3);
  t = concat_fils(t, t1);
  t = concat_frere(t, t2);
  afficher_arbre(t);
  free_arbre(t);

  return 0;
  }
*/
