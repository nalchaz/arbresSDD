#include "elem.h"

/* -------------------------------------------------------------------- */
/* AfficherElem          Affiche un element                             */
/*                                                                      */
/* En entree: elem_t : l'element a afficher                             */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AfficherElem(elem_t elem){
	if(elem.noeud->val){
 		printf("%c\n", elem.noeud->val);
	}
	else{
		printf("%c\n", elem.noeud->fils);
	}
}
