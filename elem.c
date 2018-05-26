#include "elem.h"

/* -------------------------------------------------------------------- */
/* AfficherElem          Affiche un element                             */
/*                                                                      */
/* En entree: elem_t : l'element a afficher                             */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AfficherElem(elem_t elem){
  printf("%c\n", elem->val);
}
