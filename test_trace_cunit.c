#include"grille.h"
#include"trace.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_app_tache(void){
  int** tab= creer_grille(4);
  alea_init(tab,4);
  int** tache = init_tache(tab,4);
  int taille_tache = cher_taille_tache(tache);
  CU_ASSERT(app_tache(tache,0,0,taille_tache)==1);
  int c = tab[0][0];
  tab[1][0] = c;
  tab[2][0] = c;
  tab[3][0] = (c+1)%6;
  tab[3][1] = (c+2)%6;
  int** tache2 = init_tache(tab,4);
  CU_ASSERT(app_tache(tache2,2,0,taille_tache)==1);
  CU_ASSERT(app_tache(tache2,3,0,taille_tache)==0);
}

void test_maj_tache(void){
  int ** tab= creer_grille(3);
  tab[0][0] = 1;
  tab[0][1] = 2;
  tab[0][2] = 5;
  tab[1][0] = 1;
  tab[1][1] = 4;
  tab[1][2] = 3;
  tab[2][0] = 2;
  tab[2][1] = 2;
  tab[2][2] = 3;
  int ** tache = init_tache(tab, 3);
  int taille_tache = cher_taille_tache(tache);
  maj_tache(tab, 3, tache, taille_tache, 2);
  CU_ASSERT(taille_tache == 5);
  CU_ASSERT(
