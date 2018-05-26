/* -------------------------------------------------------------------- */
/*                             pile.c                                   */
/*                                                                      */
/*    Fonctions permettant d'utiliser la structure pile_t               */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "pile.h"

/* -------------------------------------------------------------------- */
/* InitPile             Initialise la pile                              */
/*                                                                      */
/* En entree: taille : taille de la pile a initialiser                  */
/*                                                                      */
/* En sortie: L'adresse pile initialisee                                */
/*            NULL en cas d'erreur                                      */
/* -------------------------------------------------------------------- */

pile_t * InitPile(int taille){
  pile_t * pile;

  pile = (pile_t *)malloc(sizeof(pile_t));
  if(pile){
    pile->tableau = (elem_t *)malloc(taille*sizeof(elem_t));
    if(pile->tableau){
      pile->taille = taille;
      pile->sommet = -1;
    }
    else{
      free(pile);
    }
  }
  return pile; 
}

/* -------------------------------------------------------------------- */
/* EstVide             Test si la pile est vide                         */
/*                                                                      */
/* En entree: pile_t : la pile a tester                                 */
/*                                                                      */
/* En sortie: 1 si la pile est vide                                     */
/*            0 si elle n'est pas vide                                  */
/* -------------------------------------------------------------------- */
int EstVide(pile_t * pile){
  return (pile->sommet == -1);
}

/* -------------------------------------------------------------------- */
/* EstPleine             Test si la pile est pleine                     */
/*                                                                      */
/* En entree: pile_t : la pile a tester                                 */
/*                                                                      */
/* En sortie: 1 si la pile est pleine                                   */
/*            0 si elle n'est pas pleine                                */
/* -------------------------------------------------------------------- */
int EstPleine(pile_t * pile){
  return (pile->sommet+1 >= pile->taille);
}

/* -------------------------------------------------------------------- */
/* Empiler             Permet d'empiler un element                      */
/*                                                                      */
/* En entree: pile_t : la pile dans laquelle empiler                    */
/*            elem : element a empiler                                  */
/*                                                                      */
/* En sortie: 0 si pas de probleme                                      */
/*            1 en cas d'erreur                                         */
/* -------------------------------------------------------------------- */

int Empiler(pile_t * pile, elem_t elem){
  int CodeErreur = 0;
  if(EstPleine(pile) == 0){
    pile->tableau[pile->sommet+1] = elem; 
    pile->sommet++;  
  }
  else{
    CodeErreur = 1;
  }
  return CodeErreur;
}

/* -------------------------------------------------------------------- */
/* Depiler             Permet de depiler un element                     */
/*                                                                      */
/* En entree: pile_t : la pile dans laquelle depiler                    */
/*            elem : adresse dans laquelle l'element depile sera insere */
/*                                                                      */
/* En sortie: 0 si pas de probleme                                      */
/*            1 en cas d'erreur                                         */
/* -------------------------------------------------------------------- */
int Depiler(pile_t * pile, elem_t * elem){
  int CodeErreur = 0;
  if(EstVide(pile) == 0){
    *elem = pile->tableau[pile->sommet];
    pile->sommet--;
  }
  else{
    CodeErreur = 1;
  }
  return CodeErreur;
}

/* -------------------------------------------------------------------- */
/* AfficherPile             Affiche la pile                             */
/*                                                                      */
/* En entree: pile_t : la pile a afficher                               */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AfficherPile(pile_t * pile){
  int i;
  
  printf("[TAILLE] : %d\t [SOMMET] : %d\n", pile->taille, pile->sommet);
  for(i = 0; i<pile->sommet+1; i++){
    AfficherElem(pile->tableau[i]);
  }
}

/* -------------------------------------------------------------------- */
/* LibererPile             Libère la pile                               */
/*                                                                      */
/* En entree: pile_t : la pile a liberer                                */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void LibererPile(pile_t * pile){
	free(pile->tableau);
	free(pile);
}
