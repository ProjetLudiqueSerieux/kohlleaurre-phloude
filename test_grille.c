/*
 gcc     test_grille.c  grille.c  -o test_grille -I /usr/local/Cellar/cunit/2.1-3/include/ -lCUnit -L /usr/local/Cellar/cunit/2.1-3/lib/
 */


#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "grille.h"



void test_creer_grille(void)
{
	int n = 3;
	int** grille = creer_grille(n);
	CU_ASSERT(grille != NULL);
	vide_grille(&grille,3);
	
}

void test_vide_grille()
{
	int** grille = creer_grille(3);
	vide_grille(&grille,3);
	CU_ASSERT(grille == NULL);
}

void test_alea_init()
{
	int** grille = creer_grille(3);
	alea_init(grille,3);
	int i,j;
	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
			CU_ASSERT(grille[i][j] < 6 && grille[i][j] >= 0);
	vide_grille(&grille,3);
}

void test_fichier_init()
{
	int** grille = creer_grille(5);
	fichier_init(grille,5,"fichier.txt");
	int i,j;
	for (i=0;i<5;i++)
		for (j=0;j<5;j++)
			CU_ASSERT(grille[i][j] < 6 && grille[i][j] >= 0);
	vide_grille(&grille,5);
}

int main()
{
	CU_pSuite pSuite = NULL;
	
	if (CU_initialize_registry() != CUE_SUCCESS) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Suite",NULL,NULL);

	if (pSuite==NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}
    if (CU_add_test (pSuite, "test of 1",test_creer_grille)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
	}
    if (CU_add_test (pSuite, "test of 2",test_vide_grille)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
	}
    if (CU_add_test (pSuite, "test of 3",test_alea_init)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
	}
    if (CU_add_test (pSuite, "test of 4",test_fichier_init)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
	}
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    //CU_cleanup_registry();
    
	return 0;
}