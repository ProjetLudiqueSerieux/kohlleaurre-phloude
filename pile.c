
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Pile creer_pile (){
  Pile p;
  p.sommet = NULL;
  return p;
}

int is_empty (Pile p){
  return p.sommet == NULL;
}

void empiler (Pile *p, int valsuivant){
  Element *nouveau = malloc(sizeof(Element));
  if (nouveau == NULL)
    exit(1);
  nouveau->value = valsuivant;
  nouveau->suivant = p->sommet;
  p->sommet = nouveau;
}


 int depiler(Pile *pile){
    if (pile == NULL){
      exit(1);
    }
    int nombreDepile = 0;
    Element *elementDepile = pile->sommet;
    if (pile != NULL && pile->sommet != NULL)
    {
        nombreDepile = elementDepile->value;
        pile->sommet = elementDepile->suivant;
        free(elementDepile);
    }
    return nombreDepile;
}

int sommet(Pile *p){
  return p->sommet->value;
}


  
