
#include <stdio.h>
#include <stdlib.h>
#include "tache.h"
#include "grille.h"
#include "pile.h"


/**
*\fn int solveur(int** grille, int n, pile solution, int profondeur, int majoration)
*\brief grâce à une estimation rapide en utilisant les fonction coup_opti et une_solution, on arrive à trouver une majoration assez fiable.
*\param int** grille, la grille contenant les couleurs, int n, la taille de ta grille, pile solution, la solution en cours de test, int profondeur, le nombre de couleurs utilisées dans la solution, int majoration, la majoration qu'on a pour l'instant.  
*\return la majoration  qu'on aura calculée.
*/
int solveur (int **grille, int n, Pile solution, int profondeur,int majoration ){
	int **t=init_tache(grille,n);
	if (majoration>profondeur){
	        int i;
		for (i=0; i<6; i=i+1){
		  if (i != *(solution.sommet).value){
				solution=(empiler (solution, i));
				profondeur ++;
				int k=cher_taille_tache(t,n);
				maj_tache( g, n,t,k,i);
				if(k==n*n){
					vide_grille(g,n);
					majoration=profondeur;
				}
				return solveur(grille, n, solution, profondeur,majoration);
			};
	else{
		while(majoration<=profondeur){
			depiler(solution);
			profondeur=profondeur-1;
		}
		while (*(solution.sommet).value)=5){
			depiler(solution);
			profondeur=profondeur-1;			
		}
		if (est_vide(solution)){/*cas ou on a vidé toute la pile car elle était pleine de 5: on a été exhaustif*/ 
			return majoration;}
	        *(solution.sommet).value)++; 	/*on incrémente artificiellement la couleur du dernier coup car on ne rerentre pas encore dans la boucle*/
		return solveur(grille,n,solution,profondeur,majoration);
	};
}		





/*on cherche une premiere solution*/
/**
*\fn int max_ind(int* t,int taille)
*\brief calcule l'indice max.
*\param int* t, la tache, int taille, taille de la grille.
*\return l'indice dont le contenu de la case est la plus grande.
*/
int max_ind(int* t,int taille ){
	int M=t[0];
	for (i=1;i<taille;i++){
		if (t[i]>M)
			M=t[i];
		}
	k=0;
	while (t[k]<M) 
		k++;
	return k;
	}
		
/**
*\fn int coup_opti( int ** grille, int taille)
*\brief retourne une première majoration 
*\param int** grille, la grille contenant les couleurs, int taille, taille de la grille
*\return l'indice i pour lequel la tache est maximale.
*/
int coup_opti( int ** grille, int taille){
	int[6] l;
	for (i=0;i<6;i++){
		int **g=init_tache (grille,taille);
		maj_tache(g,i);
		l[i]=taille_tache(g);
		}
	return max_ind(l,6);}

/**
*\fn int une_solution( int ** grille, int taille)
*\brief calcule la profondeur de la solution.
*\param int** grille, la grille contenant les couleurs, int taille, taille de la grille.
*\return la taille de la solution.
*/		
int une_solution(int ** grille, int taille){
	Pile p;
	int profondeur=0;
	while (cond_gagner(grille,taille)!=0){
		empiler(coup_opti(grille,taille),p);
		profondeur++;
	}
	return profondeur;
}


 int main(){
   return 0;
 }

