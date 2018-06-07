#ifndef ELEM_H
#define ELEM_H

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

typedef union elem
{
    maillon_t * noeud;
    int fils;
}elem_t;

void AfficherElem(elem_t);
#endif
