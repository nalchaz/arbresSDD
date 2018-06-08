#include "cas.h"


/* -------------------------------------------------------------------- */
/* cas1     Cas de fonctionnement normal (avec l'arbre en exemple)      */
/*                                                                      */
/* -------------------------------------------------------------------- */

void cas1(maillon_t * arbre, maillon2_t * arbre2){

  puts("[CAS GENERAL]");
  arbre = CreationArbre("arbres/arbre.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas2                Cas ou le fichier n'existe pas                   */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas2(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS FICHIER INEXISTANT]");
  
  arbre = CreationArbre("arbres/inexistant.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas3                   Cas ou le fichier est vide                    */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas3(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS FICHIER VIDE]");
  
  arbre = CreationArbre("arbres/vide.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas4              Cas ou il n'y a qu'une seule racine                */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas4(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS UNE SEULE RACINE]");
  
  arbre = CreationArbre("arbres/uneracine.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas5     Cas de fonctionnement normal (avec l'arbre en exemple)      */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas5(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS QUE DES FILS]");
  
  arbre = CreationArbre("arbres/quefils.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas6              Cas ou il n'y a que des racines                    */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas6(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS QUE DES RACINES]");
  
  arbre = CreationArbre("arbres/queracines.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas7     Cas ou il n'y a que des fils et une deuxieme racine         */
/*                                                                      */
/* -------------------------------------------------------------------- */
void cas7(maillon_t * arbre, maillon2_t * arbre2){
  
  puts("[CAS QUE DES FILS ET UNE DEUXIEME RACINES]");
  
  arbre = CreationArbre("arbres/fils2racines.txt");
  printf("1) Arbre de base :\n");
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
}

/* -------------------------------------------------------------------- */
/* cas8         Cas d'insertion de valeur dans un arbre                 */
/*                                                                      */
/* -------------------------------------------------------------------- */

void cas8(maillon_t * arbre){

  puts("[CAS DES INSERTIONS]");
  arbre = CreationArbre("arbres/arbre.txt");
  printf("1) Arbre de base :\n");
  AffichageIte(arbre);
  printf("\n");
  
  pere = RechercheValeur(&arbre,'x');
  prec = ParcoursFilsTrie(pere, 'r');
  printf("RECHERCHE DU PERE x : %c \n", pere->val);
  printf("PRECEDENT DE r : %c ", prec->val);

  RechercheEtInsertion(&arbre, 'r', 'x');
  printf("2) Insertion en milieu de liste de \"r\" fils de \"x\" :\n");
  AffichageIte(arbre);
  printf("\n");
  
  RechercheEtInsertion(&arbre, 'a', 'a');
  printf("3) Insertion en debut de liste de \"a\" fils de \"a\" :\n");
  AffichageIte(arbre);
  printf("\n");
  
  RechercheEtInsertion(&arbre, 'z', 'x');
  printf("4) Insertion en fin de liste de \"z\" fils de \"x\" :\n");
  AffichageIte(arbre);
  printf("\n");

  RechercheEtInsertion(&arbre, 'y', 'n');
  printf("5) Insertion pere inexistant de \"y\" fils de \"n\" :\n");
  AffichageIte(arbre);
  printf("\n");
  
  LibererArbre(arbre);
}
