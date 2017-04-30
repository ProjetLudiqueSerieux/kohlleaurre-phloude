#include "grille.h"
#include "tache.h"
#include "lotB_debut.h"
#include "lotB_affichage.h"
#include <stdio.h>
#include <stdlib.h>

char couleur[6] = {'R','J','B','V','O','C'};


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

/**
*\fn void purger(void)
*\brief vide le flux pour permetrte a scanf de fonctionner
*\param void
*\return void
*/

void purger()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/**
*\fn int demande_int(void)
*\brief attend que l'utilisateur entre un entier et lui fait recommencer s'il a fait une erreur.
*\param void
*\return un int entré par l'utilisateur
*/

int demande_int()
{
  int res = 0;
  int verif = 'n';
  while(verif == 'n')
    {
      scanf("%i",&res);
      purger();
      printf("Vous avez entré %i. n pour recommencer, o sinon.\n",res);
      verif = getchar();
      purger();
    }
  return res;
}

