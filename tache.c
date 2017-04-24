/**
\file tache.c
*\author Romanus Rosari et Rémi Faure-Gignoux
*\date 24/04/2017
*\brief desrciption de tache.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/**
*\fn int** rempl_coul( int** tab, int x, int y, int c )
*\brief remplit la case (x,y) avec la couleur c
*\param int** tab la grille, int x la 1ère coordonnée, int y la 2ème coordonnée, int c la couleur.
*\return void
*/
/* remplit la case (x,y) avec la couleur c */

void rempl_coul( int** tab, int x, int y, int c ){
  tab[x][y] = c;
}


/**
*\fn int** app_tacje( int** tab, int x, int y, int c )
*\brief remplit la case (x,y) avec la couleur c
*\param int** tab la grille, int x la 1ère coordonnée, int y la 2ème coordonnée, int c la couleur.
*\return void
*/
/* fonction d'appartenance à la tache*/
/* Si la case de coordonnées (coord0,coord1) appartient à la tache, alors on retourne 1 ; sinon on retourne 0.*/

int app_tache(int coord0, int coord1, int ** tache, int taille_tache){
  int i = 0;
  for (i=0;i<taille_tache;i++){
    if (tache[i][0] == coord0 && tache[i][1] == coord1) return 1;
  }
  return 0;
}

/**
*\fn void maj_tache( int** tab, int taille, int** tache, int taille_tache, int c )
*\brief met à jour la tache en se disant que l'utilisateur a cliqué sur la couleur c. On parcourt la liste des cases dans la tache. On regarde tous les voisins de chacune des cases ( cases du dessus,dessous, sur la gauche et sur la droite si elles existent. ) ; si une case est de couleur c, on l'ajoute à la tache ( ce qui modifie la taille de tache ). On s'arrête quand on a parcouru toute la tache.
*\param int** tab la grille, int taille sa taille, int** tache la tache, int taille_tache sa taille, int c la couleur.
*\return void
*/
/* On met à jour la tache en se disant que l'utilisateur a cliqué sur la couleur c. */
/* On parcourt la liste des cases dans la tache. On regarde tous les voisins de chacune des cases ( cases du dessus,dessous, sur la gauche et sur la droite si elles existent ) ; si une case est de couleur c, on l'ajoute à la tache ( ce qui modifie la taille de tache ).
   On s'arrête quand on a parcouru toute la tache.*/ 

void maj_tache( int** tab, int taille , int** tache, int taille_tache , int c ){
  int n = taille;
  int reste_voisin = 1;
  int i = 0;
  while (reste_voisin == 1){
    int* elt_crt=tache[i];
    if ( 0 < elt_crt[0]){
      if ( tab[elt_crt[0]-1][elt_crt[1]] == c && app_tache(elt_crt[0]-1,elt_crt[1], tache, taille_tache)==0){
	tache[taille_tache][0]=elt_crt[0]-1;
	tache[taille_tache][1]=elt_crt[1];
	taille_tache ++;
      }
    }
    if ( elt_crt[0] < n){
      if ( tab[elt_crt[0]+1][elt_crt[1]] == c && app_tache(elt_crt[0]+1,elt_crt[1], tache, taille_tache)==0){
	tache[taille_tache][0]=elt_crt[0]+1;
	tache[taille_tache][1]=elt_crt[1];
	taille_tache ++;
      }
    }
    if ( 0 < elt_crt[1]){
      if ( tab[elt_crt[0]][elt_crt[1]-1] == c && app_tache(elt_crt[0],elt_crt[1]-1, tache, taille_tache) ==0){
	tache[taille_tache][0]=elt_crt[0];
	tache[taille_tache][1]=elt_crt[1]-1;
	taille_tache ++;
      }
    }
    if ( elt_crt[1] < n ){
      if ( tab[elt_crt[0]][elt_crt[1]+1] == c  && app_tache(elt_crt[0],elt_crt[1]+1, tache, taille_tache)==0){
	tache[taille_tache][0]=elt_crt[0];
	tache[taille_tache][1]=elt_crt[1]+1;
	taille_tache ++;
      }
    }
    i++ ;
    if(i >= taille_tache)
      {reste_voisin = 0;}
  }
}

/**
*\fn int cher_taille_tache( int** tache )
*\brief trouve la taille de la tache
*\param int** tache la tache.
*\return la taille de la tache.
*/
/* initialise la tache */
/* On crée la tache en allouant la bonne taille ( n^2 ) et on la met à jour.*/ 

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
  maj_tache(tab,taille,tache,1,tab[0][0]);
  return tache;
}

/**
*\fn int cher_taille_tache( int** tache )
*\brief trouve la taille de la tache
*\param int** tache la tache.
*\return la taille de la tache.
*/
/* trouve la taille de la tache */

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
*\param int** tab la grille, int** tache la tache, int taille_tache sa taille, int c la couleur.
*\return void
*/
/* change la couleur de la tache */

void chang_coul( int** tab, int** tache, int taille_tache,int c ){
  int i;
  for( i=0;i<taille_tache;i++ ){
    rempl_coul(tab,tache[i][0],tache[i][1],c);
  }
}

/**
*\fn int cond_gagner( int** tab, int taille )
*\brief test si la condition de victoire est verifiee
*\param int** tab la grille, int taille_tache sa taille.
*\return Si le joueur a gagné, on retourne 0 ; sinon on retourne 1.
*/
/* test si la condition de victoire est verifiee*/
/* Si le joueur a gagné, on retourne 0 ; sinon on retourne 1.*/ 

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

int main(){
  int n=5;
  int** tab =creer_grille(n);
  alea_init(tab,n);
  int i,j;
  printf("\n");
  for( i=0;i<n;i++ ){
	  for( j=0;j<n;j++ ){
		  printf("%i|",tab[i][j]);
	  }
  }
  printf("\n");
  int** tache=init_tache(tab,n)
  int taille_tache = cher_taille_tache(tache);	
  chang_coul(tab,tache,taille_tache,c);
  fichier_init(tab,n,"fichier.txt");
  for( i=0;i<n;i++ ){
	  for( j=0;j<n;j++ ){
		  printf("%i|",tab[i][j]);
	  }
  }
  int** tache=init_tache(tab,n)
  int taille_tache = cher_taille_tache(tache);	
  chang_coul(tab,tache,taille_tache,c);
  fichier_init(tab,n,"fichier.txt");
  return 0;
}
