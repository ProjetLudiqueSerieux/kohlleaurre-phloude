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

/**
*\fn void trans_grille(int*** grille, int taille, int** *tache, int *taille_tache, int *cp_fait, int nouv_coul )
*\brief applique les transformation nécessaire a la grille : changement de couleur de la tache, mise à jour de la tache et du nombre de coup restant.
*\param grille la grille de jeu et sa taille en pointeur, la tache et sa taille en pointeur, et pointeur vers le nombre de coup restant et la nouvelle couleur sélectionnée.
*\return void
*/

void trans_grille(int** *grille, int taille, int** *tache, int *taille_tache, int *cp_fait, int nouv_coul ){
    maj_tache(grille,taille,&tache,&taille_tache,nouv_coul);
    int i;
    for (i=0;i<taille_tache;i++){
      case_tache=tache[i];
      if (grille[case_tache[0]][case_tache[1]] != nouv_coul){
        grille[case_tache[0]][case_tache[1]] = nouv_coul;
      }
    }
    cp_fait ++;
}
