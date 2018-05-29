#include "arbres.h"

int main(void){
  maillon_t * arbre;
  maillon2_t * arbre2;
  
  arbre = CreationArbre("arbre.txt");
  printf("Avant :\n");
  AffichageIte(arbre);

  RechercheEtInsertion(&arbre, 'r', 'x');
  
  printf("Dopo :\n");
  AffichageIte(arbre);
  
  printf("On copie...\n");
  arbre2 = CopieArbre(arbre);
  return 0;
}
