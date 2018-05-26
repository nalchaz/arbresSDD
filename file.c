/* -------------------------------------------------------------------- */
/*                             file.c                                   */
/*                                                                      */
/*    Fonctions permettant d'utiliser la structure file_t               */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "file.h"

/* -------------------------------------------------------------------- */
/* InitFile             Initialise la file                              */
/*                                                                      */
/* En entree: taille : taille de la file a initialiser                  */
/*                                                                      */
/* En sortie: L'adresse file initialisee                                */
/*            NULL en cas d'erreur                                      */
/* -------------------------------------------------------------------- */

file_t * InitFile(int taille){
  file_t * file;

  file = (file_t *)malloc(sizeof(file_t));
  if(file){
    file->tableau = (elem_t *)malloc(taille*sizeof(elem_t));
    if(file->tableau){
      file->taille = taille ;
      file->NbElts = 0 ;
      file->deb = 0 ;
      file->fin = taille-1;
    }
    else{
      free(file);
    }
  }
  return file; 
}

/* -------------------------------------------------------------------- */
/* EstVidef             Test si la file est vide                        */
/*                                                                      */
/* En entree: file_t : la file a tester                                 */
/*                                                                      */
/* En sortie: 1 si la file est vide                                     */
/*            0 si elle n'est pas vide                                  */
/* -------------------------------------------------------------------- */
int EstVidef(file_t * file){
  return (file->NbElts == 0);
}

/* -------------------------------------------------------------------- */
/* EstPleinef             Test si la file est pleine                    */
/*                                                                      */
/* En entree: file_t : la file a tester                                 */
/*                                                                      */
/* En sortie: 1 si la file est pleine                                   */
/*            0 si elle n'est pas pleine                                */
/* -------------------------------------------------------------------- */
int EstPleinef(file_t * file){
  return (file->NbElts == file->taille);
}

/* -------------------------------------------------------------------- */
/* Enfiler             Permet d'enfiler un element                      */
/*                                                                      */
/* En entree: file_t : la file dans laquelle enfiler                    */
/*            elem : element a enfiler                                  */
/*                                                                      */
/* En sortie: 0 si pas de probleme                                      */
/*            1 en cas d'erreur                                         */
/* -------------------------------------------------------------------- */

int Enfiler(file_t * file, elem_t elem){
  int CodeErreur = 0;
  if(EstPleinef(file) != 1){ 
    file->fin = (file->fin +1) % (file->taille);
    file->NbElts++;
    file->tableau[file->fin] = elem; 
  }
  else{
    CodeErreur = 1;
  }
  return CodeErreur;
}

/* -------------------------------------------------------------------- */
/* Defiler             Permet de defiler un element                     */
/*                                                                      */
/* En entree: file_t : la file dans laquelle defiler                    */
/*            elem : adresse dans laquelle l'element defile sera insere */
/*                                                                      */
/* En sortie: 0 si pas de probleme                                      */
/*            1 en cas d'erreur                                         */
/* -------------------------------------------------------------------- */
int Defiler(file_t * file, elem_t * elem){
  int CodeErreur = 0;
  if(EstVidef(file) != 1){
    *elem = file->tableau[file->deb];
    file->deb = (file->deb + 1 ) % (file->taille);
    file->NbElts--;
  }
  else{
    CodeErreur = 1;
  }
  return CodeErreur;
}

/* -------------------------------------------------------------------- */
/* AfficherFile             Affiche la file                             */
/*                                                                      */
/* En entree: file_t : la file a afficher                               */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void AfficherFile(file_t * file){
  int i;
  
  printf("[TAILLE] : %d\t [NBELEM] : %d\n", file->taille, file->NbElts);
  for(i = file->deb; i != file->fin; i = (i+1) % file->taille){
    AfficherElem(file->tableau[i]);
  }
  AfficherElem(file->tableau[file->fin]);
}

/* -------------------------------------------------------------------- */
/* LibererFile             Libère la file                               */
/*                                                                      */
/* En entree: file_t : la file a liberer                                */
/*                                                                      */
/* En sortie: aucune                                                    */
/* -------------------------------------------------------------------- */
void LibererFile(file_t * file){
	free(file->tableau);
	free(file);
}
