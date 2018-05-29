#include "arbres.h"

/* -------------------------------------------------------------------- */
/* CreationArbre     Creer un arbre a partir d'un fichier               */
/*                                                                      */
/* En entree: NomFic : nom du fichier dans lequel trouver l'arbre       */
/*                                                                      */
/* En sortie: adresse de l'arbre creer                                  */
/* -------------------------------------------------------------------- */
maillon_t * CreationArbre(char * NomFic){
  FILE * fic;
  maillon_t * temp;
  maillon_t * arbre, ** prec;
  
  pile_t * pile;

  char c;
  int codeErreur;
  
  pile = InitPile(TAILLE);
      
  fic = fopen(NomFic, "r");
      
  if(fic != NULL){
    c=fgetc(fic);
  
    if(c == '('){
      c=fgetc(fic);
      arbre = CreerMaillon(c);
      prec = &arbre ;
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
      *prec = (*prec)->fils;
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
      *prec = (*prec)->frere;
     
      break;

    }
    c=fgetc(fic);
  }

  puts("");
  fclose(fic);
  LibererPile(pile);
  return arbre;
    
}

/* -------------------------------------------------------------------- */
/* RechercheValeur     Recherche une valeur dans un arbre               */
/*                                                                      */
/* En entree: racine : la racine de l'arbre			        */
/*            valeur : valeur à rechercher dans l'arbre                 */
/*                                                                      */
/* En sortie: adresse de la valeur recherchée		         	*/
/* 			  NULL si non trouvée                           */
/* -------------------------------------------------------------------- */
maillon_t * RechercheValeur(maillon_t ** racine, char valeur){
	
  maillon_t * cour ;
  file_t * file;
  int CodeErreur ;
	
  cour = *racine;
  file = InitFile(TAILLE);
  CodeErreur = 0;
	
  while (!CodeErreur && cour != NULL && cour->val != valeur){	
    while (!CodeErreur && cour != NULL && cour->val != valeur){	
      if (cour->fils != NULL) CodeErreur = Enfiler(file, cour->fils);
      cour = cour->frere;
    }
    if (cour == NULL && !EstVidef(file)) CodeErreur = Defiler(file, &cour);	
  }
	
  LibererFile(file);
  return cour;
	
}

/* -------------------------------------------------------------------- */
/* parcoursFilsTrie     Recherche de l'emplacement d'une        	*/
/* 		      	valeur dans une liste de fils triée             */
/*                                                                      */
/* En entree: pere : pere de la liste des fils                   	*/
/*            valeur : valeur dont l'on souhaite connaître      	*/
/*        	       l'emplacement  				        */
/*                                                                      */
/* En sortie: 						        	*/
/*  - si le pere V a au moins un fils : retourne l'adresse du fils    	*/
/*    après lequel il faudrait		                                */ 
/*    insérer la valeur W				                */
/*  - si le pere V n'a pas de fils : retourne l'adresse de V    	*/
/* -------------------------------------------------------------------- */
maillon_t * parcoursFilsTrie(maillon_t * pere, char valeur){

  maillon_t ** prec ;
  prec = &pere;
	
  if ((*prec)->fils != NULL){ /* Cas où le père possède au moins un fils */
    prec = &((*prec)->fils);
    while (*prec != NULL && (*prec)->val > valeur ){
      prec = &((*prec)->frere) ;
    }
  }
  return *prec ;
}


/* -------------------------------------------------------------------- */
/* RechercheEtInsertion    Insertion d'un fils de valeur W              */
/* 	        	au point de valeur V s'il existe		*/
/*		       		       					*/
/* HYP : les fils d'un points sont triés par ordre croissant   		*/
/*                                                                      */
/* En entree: racine : la racine de l'arbre	                	*/
/*            	   W : valeur du fils à insérer	                 	*/
/*	           V : valeur du pere auquel on veut ajouter un fils	*/
/*                                                                      */
/* En sortie: aucune						      	*/
/* -------------------------------------------------------------------- */
void RechercheEtInsertion(maillon_t ** racine, char W, char V){
  maillon_t 		*pere, *PereOuFrere, *nouv ;

  pere = RechercheValeur(racine, V);
	
  if (pere != NULL){
    PereOuFrere = parcoursFilsTrie(pere, W);
    nouv = CreerMaillon(W);
		
    if (nouv != NULL){
			
      if (PereOuFrere != pere){ /* Cas où le père a au moins un fils */
	nouv->frere = PereOuFrere->frere;
	PereOuFrere->frere = nouv ;
      }else{ /* Cas où le père n'a pas de fils */
	PereOuFrere->fils = nouv;
      }
    }
  }
}

/* -------------------------------------------------------------------- */
/* CopieArbre  Creer une copie d'un arbre avec des pointeurs sur pere   */
/*		       		       					*/
/*                                                                      */
/* En entree: arbre1 : l'arbre a copier    	                	*/
/*                                                                      */
/* En sortie: l'arbre copie					      	*/
/* -------------------------------------------------------------------- */
maillon2_t * CopieArbre(maillon_t * arbre1){
  maillon2_t *arbre2, **temp, ** prec;
  maillon_t * cour;
  int CodeErreur1;
  pile_t *pile;
	
  pile = InitPile(TAILLE);
  CodeErreur1 = 0;
	
  /* Création de la racine */
  arbre2 = CreerMaillon(arbre1->val);
  arbre2->pere = arbre2;
  arbre2->frere = NULL;
	
  /* Courant sur l'arbre à 3 cellules, prec sur l'arbre ) 4 */
  cour = arbre1->fils;
  prec = &arbre2;
    
  while(cour != NULL){
    /*Creation du noeud*/
    temp = CreerMaillon(cour->val);
    (*prec)->fils = temp;
    (*prec)->fils->pere = (*prec);
    prec = &((*prec)->fils);
		
    while (cour != NULL){ /*Parcours des freres*/
      if(cour->fils != NULL){ /* Si le noeud a un fils on enfile */
	CodeErreur1 = Enpiler(pile, cour->fils);
      }
      /*Création du frere*/
      temp = CreerMaillon(cour->val);
      (*prec)->frere = temp;
      (*prec)->frere->pere = (*prec)->pere;
      prec = &((*prec)->frere);
			 
    }
		
    if (!EstVide(pile)){
      CodeErreur = Depiler(pile, &cour);
    }
  }
	
  return arbre2;
}

/* -------------------------------------------------------------------- */
/* AffichagePostfixee    Affichage post fixee d'un arbre                */
/*		       		       					*/
/* En entree: arbre : l'arbre a afficher 	                	*/
/*                                                                      */
/* En sortie: aucune						      	*/
/* -------------------------------------------------------------------- */
void AffichagePostfixee(maillon_t * arbre){
  maillon_t * cour;
  pile_t * pile;
  int codeErreur = 0;

  cour = arbre;
  pile = InitPile(1000);
     
  while (cour != NULL && !codeErreur){
	
    while (cour->fils != NULL){
      Empiler(pile, cour);
      cour = cour->fils;
    }
    printf("%c ", cour->val);
    cour = cour->frere;
		
    while (cour == NULL && !EstVide(pile)){
      codeErreur = Depiler(pile, &cour);
      printf("%c ", cour->val);
      cour = cour->frere;
    }
  }
  LibererPile(pile);
}


/* -------------------------------------------------------------------- */
/* AffichageIte    Affichage iteratif de l'arbre                        */
/*                                                                      */
/* En entree:  arbre : arbre a afficher 	                	*/
/*                                                                      */
/* En sortie: aucune						      	*/
/* -------------------------------------------------------------------- */
void AffichageIte(maillon_t * arbre){

  maillon_t * cour;
  pile_t * pile;
  int codeErreur = 0;

  cour = arbre;
  pile = InitPile(TAILLE);
         
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
