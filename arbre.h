#ifndef ARBRES_H
#define ARBRES_H

#define TAILLE 100

#include "liste.h"
#include "pile.h"
#include "file.h"

maillon_t * CreationArbre(char *);
maillon_t * RechercheValeur(maillon_t **, char);
maillon_t * ParcoursFilsTrie(maillon_t *, char);
maillon2_t * CopieArbre(maillon_t *);

void RechercheEtInsertion(maillon_t **, char, char);

int IncrementerNbFilsPere(pile_t *);
void AffichagePostfixe(maillon_t *);
void AffichageIte(maillon_t *);
void AffichagePostfixe2(maillon2_t *);

void LibererArbre(maillon_t *);
void LibererArbre2(maillon2_t *);

#endif
