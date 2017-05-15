/**
\file grille.c
*\author Quentin Durand
*\date 21/04/2017
*\brief desrciption de grille.c
*/

#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
*\fn int** creer_grille(int n)
*\brief creer une grille non initialisée de taille n
*\param n taille de la grille
*\return une grille non initialisée de taille n
*/
int** creer_grille(int n){
	int** res = (int**)malloc(sizeof(int*)*n);
	int i;
	for (i=0;i<n;i++)
		res[i] = (int*)malloc(sizeof(int)*n);
	return res;
}

/**
*\fn void vide_grille(int** grille,int n)
*\brief efface une grille et la memoire qui lui est allouee
*\param grille
*\param n taille de la grille
*\return void
*/
void vide_grille(int*** grille,int n){
	int i;
	for (i=0;i<n;i++)
	{
	  free((*grille)[i]);
	  (*grille)[i] = NULL;
	}
	free((*grille));
	(*grille) = NULL;
}

/**
*\fn void alea_init(int** grille,int n)
*\brief initialise une grille de taille n en la remplissant de couleur aléatoires
*\param grille
*\param n la taille de la grille
*\return void 
*/
void alea_init(int** grille,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			grille[i][j] = rand()%6;
}
/**
*\fn void fichier_init(int** grille,int n,const char* fichier)
*\brief initialise une grille a partir d'une serie de couleur contenue dans un fichier
*\param grille
*\param n la taille de la grille
*\param fichier le fichier contenant les couleurs
*\return void
*/

void fichier_init(int** grille,int n,const char* fichier){
	FILE* f = fopen(fichier,"r");
	if ( f == NULL)
	{
		perror("grille.c,fichier_init : echec ouverture fichier\n");
		exit(1);
	}
	else
	{
		int i,j;
		for (i=0;i<n;i++)
			
			for (j=0;j<n;j++)
				grille[i][j] = getc(f)-48;
	}
}
