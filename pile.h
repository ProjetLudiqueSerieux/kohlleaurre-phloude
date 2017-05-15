#ifndef PILES
#define PILES

typedef struct Element Element;

struct Element
{
  int value;
  Element *suivant;
};

typedef struct Pile Pile;
 struct Pile
 {
  Element *sommet;
 };
Pile creer_pile();
int is_empty(Pile);
void empiler(Pile*,int);
int depiler(Pile*);
int sommet(Pile*);

#endif
