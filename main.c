#include "arbres.h"

int main(void){
  maillon_t * arbre1;
  maillon_t ** arbre2;
  
  /*arbre1 = CreationArbre("arbre.txt");
  AffichageIte(arbre1);
  */
  
  arbre1 = CreationArbre2("arbre.txt");
  AffichageIte(arbre1);
  return 0;
}