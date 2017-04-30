#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grille.h"
#include "tache.h"
#include "lotB_affichage.h"

int main()
{
  srand(time(NULL));
  printf("Entrez la taille du plateau de jeu : \n");
  int n = demande_int(); 
  printf("Entrez le nombre de coup autorisé : \n");
  int nb_coup = demande_int();
  int** grille = creer_grille(n);
  alea_init(grille,n);
  affiche_grille(grille,n,nb_coup);
  return 0;
}
