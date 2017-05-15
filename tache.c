/**
\file tache.c
*\author Romanus Rosari et Rémi Faure-Gignoux
*\date 24/04/2017
*\brief desrciption de tache.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "tache.h"



/**
*\fn int app_tache(int coord0, int coord1, int ** tache, int taille_tache)
*\brief renvoie 1 si la case aux coordonnée coord0 coord1
*\param coord0 un int
*\param coord1 un int
*\param tache la tache
*\param taille_tache la taille de la tache
*\return void
*/

int app_tache(int coord0, int coord1, int ** tache, int taille_tache){
  int i = 0;
  for (i=0;i<taille_tache;i++){
    if (tache[i][0] == coord0 && tache[i][1] == coord1) return 1;
  }
  return 0;
}

/**
*\fn void maj_tache( int** tab, int taille , int** tache, int *taille_tache , int c )
*\brief met à jour la tache en se disant que l'utilisateur a cliqué sur la couleur c. On parcourt la liste des cases dans la tache. On regarde tous les voisins de chacune des cases ( cases du dessus,dessous, sur la gauche et sur la droite si elles existent. ) ; si une case est de couleur c, on l'ajoute à la tache ( ce qui modifie la taille de tache ). On s'arrête quand on a parcouru toute la tache.
*\param tab la grille 
*\param taille sa taille
*\param tache la tache
*\param taille_tache sa taille
*\param c la couleur.
*\return void
*/


void maj_tache( int** tab, int taille , int** tache, int *taille_tache , int c ){
  int n = taille;
  int reste_voisin = 1;
  int i = 0;
  while (reste_voisin == 1){
    int* elt_crt = tache[i];
    if ( 0 < elt_crt[0]){
      if ( tab[elt_crt[0]-1][elt_crt[1]] == c && app_tache(elt_crt[0]-1,elt_crt[1], tache, *taille_tache)==0){
      	tache[*taille_tache][0]=elt_crt[0]-1;
      	tache[*taille_tache][1]=elt_crt[1];
      	(*taille_tache) ++;
      }
    }
    if ( elt_crt[0] < n-1){
      if ( tab[elt_crt[0]+1][elt_crt[1]] == c && app_tache(elt_crt[0]+1,elt_crt[1], tache, *taille_tache)==0){
      	tache[*taille_tache][0]=elt_crt[0]+1;
      	tache[*taille_tache][1]=elt_crt[1];
      	(*taille_tache) ++;
      }
    }
    if ( 0 < elt_crt[1]){
      if ( tab[elt_crt[0]][elt_crt[1]-1] == c && app_tache(elt_crt[0],elt_crt[1]-1, tache, *taille_tache) ==0){
      	tache[*taille_tache][0]=elt_crt[0];
      	tache[*taille_tache][1]=elt_crt[1]-1;
      	(*taille_tache) ++;
      }
    }
    if ( elt_crt[1] < n-1 ){
      if ( tab[elt_crt[0]][elt_crt[1]+1] == c  && app_tache(elt_crt[0],elt_crt[1]+1, tache, *taille_tache)==0){
      	tache[*taille_tache][0]=elt_crt[0];
      	tache[*taille_tache][1]=elt_crt[1]+1;
      	(*taille_tache) ++;
      }
    }
    i++ ;
    if(i >= *taille_tache){
      reste_voisin = 0;
    }
  }
}

/**
*\fn int init_tache( int** tab, int taille )
*\brief initilise la tache
*\param tab la grille
*\param taille sa taille
*\return la tache en haut a gauche de la grille
*/

int** init_tache( int** tab, int taille ){
  int** tache;
  int n =taille;
  int i;
  tache = calloc(sizeof(int*),n*n);
  for (i=0;i<n*n;i++){
    tache[i]=calloc(sizeof(int),2);
  }
  tache[0][0]=0;
  tache[0][1]=0;
  int taille_tache = 1;
  maj_tache(tab,taille,tache,&taille_tache,tab[0][0]);
  return tache;
}

/**
*\fn int cher_taille_tache( int** tache )
*\brief trouve la taille de la tache
*\param tache la tache
*\return la taille de la tache
*/

int cher_taille_tache(int** tache){
  int taille=1;
  while( tache[taille][0] != 0 || tache[taille][1] != 0 ){
    taille++;
  }
  return taille;
}

/**
*\fn void chang_coul( int** tab, int** tache, int taille_tache, int c )
*\brief change la couleur de la tache
*\param tab la grille
*\param tache la tache
*\param taille_tache sa taille
*\param c la couleur
*\return void
*/


void chang_coul( int** tab, int** tache, int taille_tache,int c ){
  int i;
  for( i=0;i<taille_tache;i++ ){
    tab[tache[i][0]][tache[i][1]] = c;
  }
}

/**
*\fn int cond_gagner( int** tab, int taille )
*\brief test si la condition de victoire est verifiee
*\param tab la grille
*\param taille sa taille.
*\return Si le joueur a gagné, on retourne 0 ; sinon on retourne 1.
*/


int cond_gagner(int** tab, int taille){
  int c= tab[0][0];
  int i,j;
  int n = taille;
  for ( i=0 ; i<n; i++ ){
    for ( j=0 ; j<n; j++ ){
      if (tab[i][j] != c ){
	return 1;
      }
    }
  }
  return 0;
}



