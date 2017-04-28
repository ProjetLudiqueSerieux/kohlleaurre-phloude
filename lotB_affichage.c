#include "grille.h"
#include "tache.h"
#include "lotB_debut.h"
#include "lotB_affichage.h"
#include <stdio.h>
#include <stdlib.h>

char* couleur = ['R','B','J','V','O','C'];

void affiche_grille(int ** grille,int n,int r)
{
  int i,j;
  for (i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
      printf("%c  ",couleur[grille[i][j]]);
    printf("\n");
    }
  printf("coups restants : %i",r);
}

