/* -------------------------------------------------------------------- */
/*                             liste.h                                  */
/*                                                                      */
/*     Fichier source detaillant les structures et les prototypes       */
/* -------------------------------------------------------------------- */

#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
  char                val;
  struct maillon      * fils, * frere;
}maillon_t;

typedef struct maillon2{
  char                val;
  struct maillon2      * fils, * frere, *pere;
}maillon2_t;

maillon_t ** InitList();
maillon_t * CreerMaillon(char);
maillon2_t *CreerMaillon2(char);

#endif
