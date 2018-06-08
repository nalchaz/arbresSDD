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
  elem_t nouv;
  char c;
  
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
      nouv.noeud = *prec;
      Empiler(pile, nouv);
      c=fgetc(fic);
      temp = CreerMaillon(c);
      (*prec)->fils = temp;
      *prec = (*prec)->fils;
      break;
      
    case ',' :
      break;

    case ')' :
      if(!EstVide(pile)){
        Depiler(pile, &nouv);
      }
      *prec=nouv.noeud;
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
	
  file_t * file;
  int CodeErreur ;
  elem_t cour, fils;

  cour.noeud = *racine;
  file = InitFile(TAILLE);
  CodeErreur = 0;
	
  while (!CodeErreur && cour.noeud != NULL && cour.noeud->val != valeur){	
    while (!CodeErreur && cour.noeud != NULL && cour.noeud->val != valeur){	
      if (cour.noeud->fils != NULL){
	fils.noeud = cour.noeud->fils;
        CodeErreur = Enfiler(file, fils);
      }
      cour.noeud = cour.noeud->frere;
    }
    if (cour.noeud == NULL && !EstVidef(file)){ 
      CodeErreur = Defiler(file, &cour);
    }	
  }
	
  LibererFile(file);
  return cour.noeud;
	
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
  maillon_t *pere, *PereOuFrere, *nouv ;

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
  maillon2_t * arbre2, * temp;
  maillon2_t ** prec;
  elem_t cour;
  int fin;
  pile_t *pile;
	
  pile = InitPile(TAILLE);
  fin = 0;
	
  /* Création de la racine */
  arbre2 = CreerMaillon2(arbre1->val);
  arbre2->pere = NULL;
  arbre2->frere = NULL;
	
  /* Courant sur l'arbre a copier, prec sur le nouvel arbre */
  cour.noeud = arbre1;
  prec = &arbre2;
    
  while(!fin){

    while(cour.noeud->fils != NULL){
      Empiler(pile, cour);
      cour.noeud = cour.noeud->fils;
      temp = CreerMaillon2(cour.noeud->val);
      (*prec)->fils = temp;
      (*prec)->fils->pere = *prec;
      prec = &((*prec)->fils);
    }
    
    while (cour.noeud->frere == NULL && !EstVide(pile)){ 
      Depiler(pile, &cour);
      prec = &((*prec)->pere);
    }
    if(cour.noeud->frere == NULL && EstVide(pile)){
      fin = 1;
    }
    else{
      cour.noeud = cour.noeud->frere;
      temp = CreerMaillon2(cour.noeud->val);
      (*prec)->frere = temp;
      (*prec)->frere->pere = (*prec)->pere;
      prec = &((*prec)->frere);
    }		 
  }
	
  return arbre2;
}


/* -------------------------------------------------------------------- */
/* AffichagePostfixee    Affichage post fixee d'un arbre                */
/*                              */
/* En entree: arbre : l'arbre a afficher                    */
/*                                                                      */
/* En sortie: aucune                    */
/* -------------------------------------------------------------------- */
void AffichagePostfixee(maillon_t * arbre){
  elem_t cour;
  elem_t nbFilsCour;
  elem_t prec;
  elem_t nbFilsPrec;

  pile_t * pilePrec ;
  int codeErreur = 0;

  nbFilsPrec.fils = 0;
  cour.noeud = arbre ;
  pilePrec = InitPile(TAILLE);
  
  

  while(cour.noeud != NULL && !codeErreur) {

    if (cour.noeud->fils != NULL){
      nbFilsCour.fils = 1;
      Empiler(pilePrec, nbFilsCour);
      codeErreur = Empiler(pilePrec, cour);
      cour.noeud = cour.noeud->fils; 
    }
    else{
      nbFilsCour.fils = 0 ;
      printf("%c[%d] ", cour.noeud->val, nbFilsCour.fils);
      if (cour.noeud->frere != NULL){

        if (!EstVide(pilePrec)){
          Depiler(pilePrec,&prec);
          Depiler(pilePrec,&nbFilsPrec);
          nbFilsPrec.fils++;
          Empiler(pilePrec, nbFilsPrec);
          codeErreur = Empiler(pilePrec, prec);
        }

        cour.noeud = cour.noeud->frere ;
      }
      else{
        while(cour.noeud != NULL && cour.noeud->frere == NULL){
          if (!EstVide(pilePrec)){
            Depiler(pilePrec,&cour);
            Depiler(pilePrec,&nbFilsCour);
            printf("%c[%d] ", cour.noeud->val, nbFilsCour.fils);
          }
          else{
            cour.noeud = NULL;
          }
        }
        if(cour.noeud != NULL){
          cour.noeud = cour.noeud->frere ;
          if (!EstVide(pilePrec)){
            Depiler(pilePrec,&prec);
            Depiler(pilePrec,&nbFilsPrec);
            nbFilsPrec.fils++;
            Empiler(pilePrec, nbFilsPrec);
            codeErreur = Empiler(pilePrec, prec);
          }
        }
      }
    }
  }
  LibererPile(pilePrec);
  printf("\n");
}

/* -------------------------------------------------------------------- */
/* AffichageIte    Affichage iteratif de l'arbre                        */
/*                                                                      */
/* En entree:  arbre : arbre a afficher 	                	*/
/*                                                                      */
/* En sortie: aucune						      	*/
/* -------------------------------------------------------------------- */
void AffichageIte(maillon_t * arbre){

  elem_t cour;
  pile_t * pile;
  int codeErreur = 0;

  cour.noeud = arbre;
  pile = InitPile(TAILLE);
  
  while (cour.noeud != NULL && !codeErreur){
    printf("%c ", cour.noeud->val);
    if (cour.noeud->frere != NULL){
      Empiler(pile, cour);
    }
    cour.noeud = cour.noeud->fils;
    if (cour.noeud == NULL && !EstVide(pile)){
      codeErreur = Depiler(pile, &cour);
      cour.noeud = cour.noeud->frere ;
    }
  }
  LibererPile(pile);
  puts("");
}


/* -------------------------------------------------------------------- */
/* AffichageArbre2    Affichage postfixee de l'arbre avec lien pere     */
/*                                                                      */
/* En entree:  arbre : arbre a afficher                                 */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AffichageArbre2(maillon2_t * arbre){
  maillon2_t * cour;

  int codeErreur = 0;
  cour = arbre;
 
  while (cour != NULL && !codeErreur){
    if (cour->fils != NULL){
      cour = cour->fils; 
    }
    else{
      printf("%c ", cour->val);
      if (cour->frere != NULL){
        cour = cour->frere ;
      }
      else{
        while(cour != NULL && cour->frere == NULL){
        
          if (cour->pere == NULL){
            cour = NULL ; 
          }
          else{
            cour = cour->pere; 
            printf("%c ", cour->val) ;
          }
        }

        if(cour != NULL){
          cour = cour->frere ;
        }
      }
    }
  }
  printf("\n") ; 
}
