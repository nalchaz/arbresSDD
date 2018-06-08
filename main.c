#include "arbre.h"

int main(void){
  maillon_t * arbre;
  maillon2_t * arbre2;
  
  arbre = CreationArbre("arbre.txt");
  printf("1) : Arbre de base :\n");
  AffichageIte(arbre);
  printf("\n");

  RechercheEtInsertion(&arbre, 'r', 'x');
  printf("2) Insertion de \"r\" fils de \"x\" :\n");
  AffichageIte(arbre);
  printf("\n");

  printf("3) Affichage postfixe (format val[nbFils]):\n");
  AffichagePostfixe(arbre);
  printf("\n");

  printf("4) Copie de l'arbre\n");
  arbre2 = CopieArbre(arbre);

  printf("5) Affichage postfixe de l'arbre 2 :\n");
  AffichagePostfixe2(arbre2);

  LibererArbre(arbre);
  LibererArbre2(arbre2);
  
  return 0;
}
