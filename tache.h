#ifndef _TACHE_H
#define _TACHE_H

void rempl_coul( int** tab, int x, int y, int c );
int app_tache(int ** tache, int x, int y, int taille_tache);
void maj_tache( int** tab, int taille , int** tache, int taille_tache , int c );
int** init_tache( int** tab, int taille );
int cher_taille_tache(int** tache);
void chang_coul( int** tab, int** tache, int taille_tache,int c );
int cond_gagner(int** tab, int taille);

#endif
