#ifndef _GRILLE_H
#define _GRILLE_H

int** creer_grille(int n);
void vide_grille(int** grille,int n);
void alea_init(int** grille,int n);
void fichier_init(int** grille,int n,const char* fichier);


#endif