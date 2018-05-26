/* -------------------------------------------------------------------- */
/*                             liste.c                                  */
/*                                                                      */
/* Fonctions permettant de manipuler les listes, la structure maillon_t */
/* -------------------------------------------------------------------- */

#include "liste.h"


/* -------------------------------------------------------------------- */
/* InitList         Initialise une liste vide                           */
/*                                                                      */
/* En entree: aucune                                                    */
/*                                                                      */
/* En sortie: Un pointeur sur le premier element de la liste vide       */
/* -------------------------------------------------------------------- */
maillon_t ** InitList(void){
  maillon_t ** nouv;

  nouv = NULL;
  return nouv;
}

/* -------------------------------------------------------------------- */
/* CreerMaillon        Créer un nouveau maillon                         */
/*                                                                      */
/* En entree: 								                                          */
/*            val  : la valeur a ajouter dans la liste                  */
/*            posi : position en i de la valeur dans la matrice         */
/*            posj : position en j de la valeur dans la matrice         */
/*                                                                      */
/* En sortie: Adresse du maillon créé								                    */
/* -------------------------------------------------------------------- */
maillon_t * CreerMaillon (char val){
  
  maillon_t 	* nouv;
  
  nouv = (maillon_t*)malloc(sizeof(maillon_t));
  
  if(nouv != NULL){
    nouv->val=val;
    nouv->frere = NULL;
    nouv->fils = NULL;
  }
  
  return nouv ; /*retourne NULL si pas alloué*/
}
