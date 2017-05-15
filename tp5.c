#include <stdlib.h>
#include <stdio.h>
#include<math.h>

#define epsilon 1e-20

typedef struct maillon* list;

struct maillon{
  double val;
  list next;
};

/*@requires rien
  assigns rien
  ensures retourne 0 si liste est vide, 1 sinon
 */
int estVide (list l){
  return NULL==l;
}

/*@requires rien
  assigns
  ensures ajoute la valeur e à la liste l, ce qu'on appelle un ajout par effet
*/
void add(double e, list *l){
  list h;
  h=(list) malloc(sizeof(struct maillon));
  h->val=e;
  h->next=*l;
  *l=h;
}
/*@requires rien
  assigns
  ensures affiche la liste l
*/
void affiche (list l){
  while (l!=NULL){
    printf("[ %f ]->",l->val);
    l=l->next;
  }
  printf("[]");
}

/*@requires rien
  assigns
  ensures
*/
list cons(double e, list l){
  list r;
  r=(list) malloc(sizeof(struct maillon));
  r->val=e;
  r->next=l;
  return r;
}

/*@requires rien
  assigns
  ensures
*/
list creerVide(){
  return NULL;
}


/*

void rem(list *l){
  list tmp=*l;
  *l=(*l)->next;
  free(tmp);
}
*/

int longueur(list l){
  int i=0;
  while(l!=NULL){
    i=i+1;
    l=l->next;
  }
  return i;
}

double somme(list l){
  double som=0;
  while(l!=NULL){
    som=som+l->val;
    l=l->next;
  }
  return som;
}

list inverser(list l){
  list q=creerVide();
  while (l!=NULL){
    q=cons(l->val,q);
    l=l->next;
  }
  return q;
}

int mem( double e,list l){
  while(l!=NULL){
    if (fabs(l->val - e) <= epsilon) return 1;
    l=l->next;
  }
  return 0;
}

void retUniq(double e, list *l){
  int d=0;
  while (l!=NULL && d=0)

}




int main(){
  list l;
  l=creerVide();
  add(23,&l);
  add(2,&l);
  l=cons(26.5,l);
  l=cons(1.5,l);
  l=cons(2.25,l);
  l=cons(3.376,l);
  affiche(l);
  printf("\nLa longueur est de %i",longueur(l));
  printf("\nLa somme est de %f",somme(l));
  printf("\n");
  l=inverser(l);
  affiche(l);
  printf("\n");
  printf("3.375 : %i , 1.5 : %i , 5 : %i\n",mem(3.375,l),mem(1.5,l),mem(5,l));
  return 0;
}
