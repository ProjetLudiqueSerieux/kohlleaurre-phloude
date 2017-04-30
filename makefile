colorflood : main.o grille.o tache.o lotB_affichage.o
	gcc -Wextra -Wall -ansi -o colorflood main.o grille.o tache.o lotB_affichage.o
	
main.o : lotB_main.c grille.h tache.h lotB_affichage.h
	gcc -Wextra -Wall -ansi -o main.o -c lotB_main.c
	
grille.o : grille.c grille.h
	gcc -Wextra -Wall -ansi -o grille.o -c grille.c
	
tache.o : tache.c tache.h grille.h
	gcc -Wextra -Wall -ansi -o tache.o -c tache.c
	
lotB_affichage.o : lotB_affichage.c lotB_affichage.h tache.h grille.h
	gcc -Wextra -Wall -ansi -o lotB_affichage.o -c lotB_affichage.c