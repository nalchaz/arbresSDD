#include "arbre.h"

/* -------------------------------------------------------------------- */
/* CreationArbre     Cree un arbre a partir d'un fichier               */
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

  arbre = NULL;
  pile = InitPile(TAILLE);
      
  fic = fopen(NomFic, "r");
      
  if(fic != NULL){
    c=fgetc(fic);
  
    if(c == '('){
      c=fgetc(fic);
      arbre = CreerMaillon(c);
      prec = &arbre ;
      nouv.noeud = *prec;
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
  }
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
maillon_t * RechercheValeur(maillon_t ** arbre, char valeur){
	
  file_t * file;
  int CodeErreur ;
  elem_t cour, filsCour;

  cour.noeud = *arbre;
  file = InitFile(TAILLE);
  CodeErreur = 0;
	
  while (!CodeErreur && cour.noeud != NULL && cour.noeud->val != valeur){	
    while (!CodeErreur && cour.noeud != NULL && cour.noeud->val != valeur){	
      if (cour.noeud->fils != NULL){
	filsCour.noeud = cour.noeud->fils;
        CodeErreur = Enfiler(file, filsCour);
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
/* ParcoursFilsTrie     Recherche de l'emplacement d'une        	*/
/* 		      	valeur dans une liste de fils triée             */
/*                                                                      */
/* En entree: pere : pere de la liste des fils                   	*/
/*            valeur : valeur dont l'on souhaite connaître      	*/
/*        	       l'emplacement  				        */
/*                                                                      */
/*    HYP : les fils sont triés par ordre croissant                     */
/*                                                                      */
/* En sortie: 						        	*/
/*  - si le pere V a au moins un fils : retourne l'adresse du fils    	*/
/*    après lequel il faudrait		                                */ 
/*    insérer la valeur W				                */
/*  - si le pere V n'a pas de fils : retourne l'adresse de V    	*/
/* -------------------------------------------------------------------- */
maillon_t * ParcoursFilsTrie(maillon_t * pere, char valeur){

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
/* HYP : les fils d'un point sont triés par ordre croissant   		*/
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
    PereOuFrere = ParcoursFilsTrie(pere, W);
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
/* CopieArbre  Cree une copie d'un arbre avec des pointeurs sur pere   */
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
	
  /* Création de la racine si elle existe*/
  if(arbre1){
    arbre2 = CreerMaillon2(arbre1->val);
    arbre2->pere = NULL;
    arbre2->frere = NULL;
    /* Courant sur l'arbre a copier, prec sur le nouvel arbre */
    cour.noeud = arbre1;
    prec = &arbre2;
  }
  else{
    arbre2 = NULL;
    fin = 1;
  }
    
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
  LibererPile(pile);	
  return arbre2;
}

/* -------------------------------------------------------------------- */
/* IncrementerNbFilsPere       Incremente le nombre de fils             */
/*                                                                      */
/* En entree: pile : pile dans laquelle se trouve le nombre de fils     */
/*                                                                      */
/* En sortie: code erreur de la fonction Empiler                        */
/* -------------------------------------------------------------------- */
int IncrementerNbFilsPere(pile_t * pile){
  elem_t nbFils;
  int codeErreur;
  
  Depiler(pile, &nbFils);
  nbFils.fils++;
  codeErreur = Empiler(pile, nbFils);
  
  return codeErreur;
}

/* -------------------------------------------------------------------- */
/* AffichagePostfixe    Affichage post fixee d'un arbre                */
/*                                                                      */
/* En entree: arbre : l'arbre a afficher                                */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AffichagePostfixe(maillon_t * arbre){
  elem_t cour;
  elem_t nbFilsCour;

  pile_t * pile;
  int codeErreur = 0;

  cour.noeud = arbre ;
  pile = InitPile(TAILLE);
  
  

  while(cour.noeud != NULL && !codeErreur) {

    if (cour.noeud->fils != NULL){
      nbFilsCour.fils = 1;
      Empiler(pile, cour);
      codeErreur = Empiler(pile, nbFilsCour);
      cour.noeud = cour.noeud->fils; 
    }
    else{
      nbFilsCour.fils = 0 ;
      printf("%c[%d] ", cour.noeud->val, nbFilsCour.fils);
      if (cour.noeud->frere != NULL){
        if(!EstVide(pile)){
	  codeErreur = IncrementerNbFilsPere(pile);
        }

        cour.noeud = cour.noeud->frere ;
      }
      else{
        while(cour.noeud != NULL && cour.noeud->frere == NULL){
          if (!EstVide(pile)){
	    Depiler(pile,&nbFilsCour);
            Depiler(pile,&cour);
            printf("%c[%d] ", cour.noeud->val, nbFilsCour.fils);
          }
          else{
            cour.noeud = NULL;
          }
        }
        if(cour.noeud != NULL){
          cour.noeud = cour.noeud->frere ;
          if (!EstVide(pile)){
            codeErreur = IncrementerNbFilsPere(pile);
          }
        }
      }
    }
  }
  LibererPile(pile);
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
/* AffichagePostfixe2    Affichage postfixee de l'arbre avec lien pere */
/*                                                                      */
/* En entree:  arbre : arbre a afficher                                 */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AffichagePostfixe2(maillon2_t * arbre){
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
  printf("\n\n") ; 
}


/* -------------------------------------------------------------------- */
/* LibererArbre            Libere l'arbre                               */
/*                                                                      */
/* En entree: maillon_t : l'arbre a liberer                             */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void LibererArbre(maillon_t * arbre){
  elem_t cour, tmp;
  pile_t * pile;
  int codeErreur = 0;

  cour.noeud = arbre;
  pile = InitPile(1000);
     
  while (cour.noeud != NULL && !codeErreur){
	
    while (cour.noeud->fils != NULL){
      Empiler(pile, cour);
      cour.noeud = cour.noeud->fils;
    }
    tmp = cour;
    cour.noeud = cour.noeud->frere;
    free(tmp.noeud);
		
    while (cour.noeud == NULL && !EstVide(pile)){
      codeErreur = Depiler(pile, &cour);
      tmp=cour;
      cour.noeud = cour.noeud->frere;
      free(tmp.noeud);
    }
  }
  LibererPile(pile);
}
  
/* -------------------------------------------------------------------- */
/* LibererArbre2          Libere l'arbre a pointeur sur pere            */
/*                                                                      */
/* En entree: maillon2_t : l'arbre avec pointeur pere a liberer         */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void LibererArbre2(maillon2_t * arbre){
  maillon2_t * cour, * tmp;

  cour = arbre;
     
  while (cour != NULL){
	
    while (cour->fils != NULL){
      cour = cour->fils;
    }
    tmp = cour;
    cour = cour->frere;
		
    while (cour == NULL && tmp != NULL){
      cour = tmp->pere;
      free(tmp);
      tmp=cour;
      if(cour)
	cour = cour->frere;
    }
    free(tmp);
  }
}
