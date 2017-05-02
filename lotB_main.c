


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
  int victoire = 1;
  int c;
  int** tache = init_tache(grille,n);
  int taille_tache = cher_taille_tache(tache);
  affiche_grille(grille,n,nb_coup);
  while(victoire && nb_coup > 0)
  {
	  c = sel_coul();
	  chang_coul(grille,tache,taille_tache,c);
	  maj_tache(grille,n,tache,&taille_tache,c);
	  nb_coup --;
	  affiche_grille(grille,n,nb_coup);
	  victoire = cond_gagner(grille,n);
  }
  if (!victoire)
    {
		printf("vous avez gagné !\n");
		return 0;
	}
  else
    {
		printf("Vous avez perdu !\n");
		return 0;
	}
  vide_grille(&grille,n);
  vide_grille(&tache,taille_tache);
}
