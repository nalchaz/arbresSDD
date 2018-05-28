#ifndef ARBRES_H
#define ARBRES_H

#define TAILLE 100

#include "liste.h"
#include "pile.h"
#include "file.h"

maillon_t * CreationArbre(char *);
void AffichageIte(maillon_t *);
maillon_t * RechercheValeur(maillon_t **, char);
maillon_t * parcoursFilsTrie(maillon_t *, char);
void RechercheEtInsertion(maillon_t **, char, char);
void AffichagePostfixee(maillon_t *);
#endif
