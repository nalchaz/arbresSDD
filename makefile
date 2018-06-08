# compilateur
CC = gcc 
# options
CFLAGS = -Wall -Wextra -pedantic -ansi -g
# liste des fichiers objets
OBJ = main.o liste.o pile.o file.o arbre.o elem.o cas.o
# règle de production finale :
main : $(OBJ)
	$(CC) $(OBJ) -o prog
# règle de production pour chaque fichier
liste.o : liste.h liste.c
	$(CC) -c liste.c $(CFLAGS)
pile.o : pile.h pile.c
	$(CC) -c pile.c $(CFLAGS)
file.o : file.h file.c
	$(CC) -c file.c $(CFLAGS)
arbre.o : arbre.h arbre.c
	$(CC) -c arbre.c $(CFLAGS)
elem.o : elem.h elem.c
	$(CC) -c elem.c $(CFLAGS)
cas.o : cas.h cas.c
	$(CC) -c cas.c $(CFLAGS)
# règle de nettoyage

clean : 
	rm -f *.o
