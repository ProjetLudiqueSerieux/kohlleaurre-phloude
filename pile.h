#ifndef PILES
#define PILES

typedef struct element {
  int value;
  element *suivant;
}
  Maillon;

typedef struct pile_s {
  Maillon *sommet}
  Pile;

void empiler(Pile*,int);
int depiler(Pile*);
#endif
