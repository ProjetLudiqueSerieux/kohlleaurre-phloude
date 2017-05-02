documentation : grille.o tache.o lotB_affichage.o
	doxygen config_dox; cd latex; make; xpdf refman.pdf

colorflood : main.o grille.o tache.o lotB_affichage.o
	gcc -Wextra -Wall -ansi -o colorflood main.o grille.o tache.o lotB_affichage.o

mySDL : mySDL.o grille.o tache.o
	gcc -Wextra -Wall -o mySDL mySDL.o grille.o tache.o -lSDL

mySDL.o : mySDL.c tache.h grille.h
	gcc -Wextra -Wall -ansi -o mySDL.o -c mySDL.c -lSDL

main.o : lotB_main.c grille.h tache.h lotB_affichage.h
	gcc -Wextra -Wall -ansi -o main.o -c lotB_main.c

grille.o : grille.c grille.h
	gcc -Wextra -Wall -ansi -o grille.o -c grille.c

tache.o : tache.c tache.h grille.h
	gcc -Wextra -Wall -ansi -o tache.o -c tache.c

lotB_affichage.o : lotB_affichage.c lotB_affichage.h tache.h grille.h
	gcc -Wextra -Wall -ansi -o lotB_affichage.o -c lotB_affichage.c

