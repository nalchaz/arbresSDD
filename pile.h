/* -------------------------------------------------------------------- */
/*                             pile.h                                   */
/*                                                                      */
/*     Fichier source detaillant les structures et les prototypes       */
/*                                                                      */
/*    parametres de la structure :                                      */
/*    taille  : taille physique de la pile                              */
/*    sommet  : taille reelle de la pile                                */
/*    tableau : adresse de la pile                                      */
/* -------------------------------------------------------------------- */

#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include "elem.h"

typedef struct pile{
  int         taille;
  int         sommet;
  elem_t    * tableau;
}pile_t;

pile_t * InitPile(int);
int EstVide(pile_t *);
int EstPleine(pile_t *);
int Empiler(pile_t *, elem_t);
int Depiler(pile_t *, elem_t *);
void AfficherPile(pile_t *);
void LibererPile(pile_t *);
#endif
