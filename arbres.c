#include "arbres.h"

/* Ca marche avec un simple pointeur */

maillon_t ** CreationArbre2(char * NomFic){
  FILE * fic;
  maillon_t * temp, *cour, * racine;
  maillon_t ** arbre;
  char c;
  pile_t * pile;
  int codeErreur;
  
  pile = InitPile(TAILLE);
      
  fic = fopen(NomFic, "r");
      
  if(fic != NULL){
    c=fgetc(fic);
  
    if(c == '('){
      c=fgetc(fic);
      temp = CreerMaillon(c);
      racine = temp;
      arbre = &racine;
      cour = racine ;
    }
  }
  c=fgetc(fic);
  while(c != EOF){
    switch(c){
    case '(' :
      codeErreur = Empiler(pile, cour);
      c=fgetc(fic);
      temp = CreerMaillon(c);
      cour->fils = temp;
      cour = cour->fils;
      break;
      
    case ',' :
      break;

    case ')' :
      if(EstVide(pile) == 0)
        codeErreur = Depiler(pile, &cour);
      break;
      
    case '\n' :
      break;
      
    default :
      /* TODO Verifier affectation du frere */
      temp = CreerMaillon(c);
      cour->frere = temp;
      cour = cour->frere;
     
      break;

    }
    c=fgetc(fic);
  }

  puts("");
  LibererPile(pile);
  return arbre;
    
}



/* Version double pointeur qui marche pas */

/*maillon_t ** CreationArbre(char * NomFic){
  FILE * fic;
  maillon_t ** arbre, ** prec;
  maillon_t * temp, * racine;
  char c;
  pile_t * pile;
  int codeErreur;
  
  pile = InitPile(TAILLE);
  arbre = InitList();
      
  fic = fopen(NomFic, "r");
      
  if(fic != NULL){
    c=fgetc(fic);
  
    if(c == '('){
      c=fgetc(fic);
      racine = CreerMaillon(c);
      arbre = &racine;
      prec = arbre;
    }
  }
  c=fgetc(fic);
  while(c != EOF){
    switch(c){
    case '(' :
      codeErreur = Empiler(pile, *prec);
      c=fgetc(fic);
      temp = CreerMaillon(c);
      (*prec)->fils = temp;
      prec = &((*prec)->fils);
      break;
      
    case ',' :
      break;

    case ')' :
      if(EstVide(pile) == 0)
    codeErreur = Depiler(pile, prec);
      break;
      
    case '\n' :
      break;
      
    default :
      temp = CreerMaillon(c);
      (*prec)->frere = temp;
      prec = &((*prec)->frere);
     
      break;

    }
    c=fgetc(fic);
  }

  puts("");
  LibererPile(pile);
  return racine;
    
}*/

void afficherArbre(maillon_t * arbre){
  if(arbre != NULL){
    printf("%c\t", arbre->val);
    if(arbre->fils){
      afficherArbre(arbre->fils);
    }
    puts("");
    printf("Actuel : %c Frere : %c\n", arbre->val, arbre->frere->val); 
    if(arbre->frere){
      afficherArbre(arbre->frere);
    }
  }
}


void AffichageIte(maillon_t * arbre){

    maillon_t * cour;
    pile_t * pile;
    int codeErreur = 0;

    cour = arbre;
    pile = InitPile(1000);
     
    while (cour != NULL && !codeErreur){
    printf("%c ", cour->val);
        if (cour->frere != NULL) Empiler(pile, cour);
        cour = cour->fils;
        if (cour == NULL && !EstVide(pile)){
            codeErreur = Depiler(pile, &cour);
            cour = cour->frere ;
        }
    }
    LibererPile(pile);
    puts("");
}