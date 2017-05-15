documentation : grille.o tache.o
	doxygen config; cd latex; make; xpdf refman.pdf &

solveur : tache.o grille.o pile.o solveur.o
	gcc -Wall -Wextra -ansi -o solveur tache.o grille.o pile.o solveur.o

solveur.o : solveur.c tache.h grille.h pile.h
	gcc -Wextra -Wall -ansi -o solveur.o -c solveur.c

tache.o : tache.c tache.h grille.c grille.h
	gcc -Wextra -Wall -ansi -o tache.o -c tache.c

grille.o : grille.c grille.h
	gcc -Wextra -Wall -ansi -o grille.o -c grille.c

pile.o : pile.c pile.h
	gcc -Wextra -Wall -ansi -o pile.o -c pile.c

