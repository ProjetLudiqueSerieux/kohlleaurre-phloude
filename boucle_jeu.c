#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "tache.h"

int main()
{
  printf("Entrez la taille du plateau de jeu : \n");
  int n = 0;
  while (n <= 0)
  {
    scanf("%i",&n);
    if (n <= 0)
      printf("Veuillez saisir un entier positif non nul");
  }
  printf("Entrez le nombre de coup autorisé : \n");
  int nb_coup = 0;
  while (nb_coup <= 0)
  {
    scanf("%i",&nb_coup);
    if (nb_coup <= 0)
      printf("Veuillez saisir un entier positif non nul");
  }
  
  return 0;
}

