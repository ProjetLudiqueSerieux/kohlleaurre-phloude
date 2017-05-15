
#include <stdio.h>
#include <stdlib.h>
#include "tache.h"
#include "grille.h"
#include "pile.h"

int solveur (int **grille, int n, Pile solution, int profondeur,int majoration ){
	int **t=init_tache(grille,n);
	if (majoration>profondeur){
	        int i;
		for (i=0; i<6; i=i+1){
		  if (i != sommet(&solution)){
				empiler(&solution,i);
				profondeur ++;
				int k=cher_taille_tache(t);
				maj_tache( grille, n,t,k,i);
				if(k==n*n){
					vide_grille(&grille,n);
					majoration=profondeur;
				}
				return solveur(grille, n, solution, profondeur,majoration);
		  }
		}
	}
	else{
		while(majoration<=profondeur){
			depiler(&solution);
			profondeur=profondeur-1;
		}
		while (sommet(&solution)==5){
			depiler(&solution);
			profondeur=profondeur-1;			
		}
		if (is_empty(solution)){/*cas ou on a vidé toute la pile car elle était pleine de 5: on a été exhaustif*/ 
			return majoration;}
	        solution.sommet->value = sommet(&solution)+1; 	/*on incrémente artificiellement la couleur du dernier coup car on ne rerentre pas encore dans la boucle*/
		return solveur(grille,n,solution,profondeur,majoration);
	};
}		





/*on cherche une premiere solution*/

int max_ind(int* t,int taille ){
	int M=t[0];
	int i;
	for (i=1;i<taille;i++){
		if (t[i]>M)
			M=t[i];
		}
	int k=0;
	while (t[k]<M) 
		k++;
	return k;
	}
		



int coup_opti( int ** grille, int taille){
	int l[6];
	int i;
	for (i=0;i<6;i++){
		int **g=init_tache (grille,taille);
		int taille_tache = cher_taille_tache(g);
		maj_tache(grille,taille,g,taille_tache,i);
		l[i]=taille_tache;
		}
	return max_ind(l,6);}

int une_solution(int ** grille, int taille){
  Pile p = creer_pile();
	int profondeur=0;
	while (cond_gagner(grille,taille)!=0){
	  empiler(&p,coup_opti(grille,taille));
		profondeur++;
	}
	return profondeur;
}


 int main(){

   
   return 0;
 }

