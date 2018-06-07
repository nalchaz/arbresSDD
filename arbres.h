#ifndef ARBRES_H
#define ARBRES_H

#define TAILLE 100

#include "liste.h"
#include "pile.h"
#include "file.h"

maillon_t * CreationArbre(char *);
maillon_t * RechercheValeur(maillon_t **, char);
maillon_t * parcoursFilsTrie(maillon_t *, char);
maillon2_t * CopieArbre(maillon_t *);

void RechercheEtInsertion(maillon_t **, char, char);
void AffichagePostfixee(maillon_t *);
void AffichageIte(maillon_t *);
void AffichageArbre2(maillon2_t *);

#endif
