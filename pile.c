

#include "pile.h"

bool is_empty (Pile p){
  pile->sommet==NULL;
}

void empiler (Pile *p, int valsuivant){
  Maillon *nouveau;
  nouveau->nombre = valsuivant;
  nouveau->suivant=p->sommet;
  pile->sommet=valsuivant;
}
int depiler(Pile *p){
  if !(is_empty(p))
    exit();
  Maillon *valeur=p->sommet;
  p->sommet= valeur->suivant;
  return valeur->value;
}

  
