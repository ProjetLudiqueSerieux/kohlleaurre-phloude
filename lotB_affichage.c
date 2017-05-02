/**
*\file lotB_affichage.c
*\author Quentin Durand Romanus Rosari
*\date 02/05/2017
*\brief desrciption de lotB_affichage.c
*/

#include "grille.h"
#include "tache.h"
#include "lotB_affichage.h"
#include <stdio.h>
#include <stdlib.h>

char couleur[6] = {'R','J','B','V','O','C'};


/**
*\fn affiche_grille(int ** grille,int n,int r)
*\brief affiche la grille de jeu dans le terminal
*\param int** grille, la grille à afficher
*\return void
*/
 
void affiche_grille(int ** grille,int n,int r)
{
  int i,j;
  printf("|");
  for(i=0;i<3*n+2;i++)
	  printf("-");
  printf("|");
  printf("\n");
  for (i=0;i<n;i++)
	{
	printf("|  ");
	for(j=0;j<n;j++)
	  printf("%c  ",couleur[grille[i][j]]);
  	printf("|");
	printf("\n");
	}
  printf("|");
  for(i=0;i<3*n+2;i++)
	printf("-");
  printf("|");
  printf("\ncoups restants : %i\n\n",r);
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


/**
*\fn int sel_coul(void)
*\brief attend que l'utilisateur entre le numero de la couleur et lui fait recommencer s'il a fait une erreur.
*\param void
*\return un int entré par l'utilisateur
*/

int sel_coul(){
   int n=0;
   printf("Veuillez sélectionner une couleur parmi celles suivantes :\n0 pour Rouge,\n1 pour Jaune,\n2 pour Bleu,\n3 pour Vert,\n4 pour Orange,\n5 pour Cuisse de nymphe.\n");
   scanf("%i",&n);
   if ( n%1 == 0 ){
      if ( 0<=n ){
         if ( n<=5 ){
            return n;
}
         else{
            printf("Veuillez rentrer un chiffre entre 0 et 5");
            return sel_coul();
}
}
      else{
            printf("Veuillez rentrer un chiffre entre 0 et 5");
            return sel_coul();}

}
   else{
       printf("Veuillez rentrer un chiffre entre 0 et 5");
       return sel_coul();}
}




