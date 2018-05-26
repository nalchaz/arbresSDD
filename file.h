#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "elem.h"

typedef struct file{
  int         taille;
  int         NbElts;
  int		  deb;
  int		  fin;
  elem_t	* tableau;
}file_t;

file_t * InitFile(int);
int EstVidef(file_t *);
int EstPleinef(file_t *);
int Enfiler(file_t *, elem_t);
int Defiler(file_t *, elem_t *);
void AfficherFile(file_t *);
void LibererFile(file_t *);
#endif
