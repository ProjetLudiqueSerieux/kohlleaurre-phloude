#include "grille.h"
#include "tache.h"
#include "lotB_affichage.h"
#include <stdio.h>
#include <stdlib.h>

char couleur[6] = {'R','J','B','V','O','C'}; //Définition des couleurs

/**
*\fn affiche_grille(int ** grille,int n,int r)
*\brief affiche la grille de jeu dans le terminal
*\param int** grille, la grille à afficher
*\return void
*/
 
void affiche_grille(int ** grille,int n,int r)
{
  int i,j;
  for(i=0;i<3*n;i++)
	  printf("_");
  for (i=0;i<n;i++)
	{
	printf("|  ");
	for(j=0;j<n;j++)
	  printf("%c  ",couleur[grille[i][j]]);
	printf("\n");
	}
	printf("|");
  for(i=0;i<3*n;i++)
	printf("_");
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

/**
*\fn int sel_coul(void)
*\brief attend que l'utilisateur entre le numero de la couleur et lui fait recommencer s'il a fait une erreur.
*\param void
*\return un int entré par l'utilisateur
*/
int sel_coul(){
   int n=0;
   printf("Veuillez sélectionner une couleur parmi celles suivantes :\n1 pour Rouge,\n2 pour Jaune,\n3 pour Bleu,\n4 pour Vert,\n5 pour Orange,\n6 pour Cuisse de nymphe émue.");
   scanf("%i",&n);
   if ( n%1 == 0 ){
      if ( 1<=n ){
         if ( n<=6 ){
            return n;
}
         else{
            printf("Veuillez rentrer un chiffre entre 1 et 6");
            return sel_coul();
}
}
      else{
            printf("Veuillez rentrer un chiffre entre 1 et 6");
            return sel_coul();}

}
   else{
       printf("Veuillez rentrer un chiffre entre 1 et 6");
       return sel_coul();}
}
