#include "arbres.h"

int main(void){
  maillon_t * arbre;
  maillon2_t * arbre2;
  
  arbre = CreationArbre("arbre.txt");
  printf("Arbre de base :\n");
  AffichageIte(arbre);
  printf("\n");

  RechercheEtInsertion(&arbre, 'r', 'x');
  printf("Apres insertion de r fils de x :\n");
  AffichageIte(arbre);
  printf("\n");

  printf("Affichage postfixee (format val[nbFils]):\n");
  AffichagePostfixee(arbre);
  printf("\n");

  printf("Copie de l'arbre\n");
  arbre2 = CopieArbre(arbre);

  printf("Affichage postfixee de l'arbre 2 :\n");
  AffichageArbre2(arbre2);

  return 0;
}
