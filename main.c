#include "arbres.h"

int main(void){
  maillon_t * arbre;
  
  arbre = CreationArbre("arbre.txt");
  printf("Avant :\n");
  AffichageIte(arbre);

  RechercheEtInsertion(&arbre, 'r', 'x');
  
  printf("Dopo :\n");
  AffichageIte(arbre);
  
  return 0;
}
