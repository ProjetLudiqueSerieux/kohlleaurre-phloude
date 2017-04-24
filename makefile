documentation : grille.o tache.o
	doxygen config; cd latex; make; xpdf refman.pdf &

LotA : tache.o grille.o
	gcc -Wall -Wextra -ansi -o LotA tache.o grille.o

tache.o : tache.c tache.h grille.c grille.h
	gcc -Wextra -Wall -ansi -o tache.o -c tache.c

grille.o : grille.c grille.h
	gcc -Wextra -Wall -ansi -o grille.o -c grille.c

