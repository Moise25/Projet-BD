/* pile.h

   Module gérant une pile de pointeurs de type void *, implementee
   sous la forme d'une machine abstraite.

   Emmanuel Chieze, UQAM, INF3135, A12, TP2
*/

#ifndef PILE_H
#define PILE_H

typedef enum { PILE_OK, PILE_VIDE, PILE_PLEINE } PileStatut;

/* pileEmpiler : permet d'ajouter un element en haut de la pile.
  	Precondition : la pile n'est pas pleine. */
void pileEmpiler(void * x);

/* pileDepiler : permet de retirer l'element en haut de la pile,
	et de le recuperer.
	Precondition : la pile n'est pas vide. */
void * pileDepiler(void);

/* pileTaille : permet d'obtenir la taille de la pile.
	Precondition : Aucune.  */
unsigned pileTaille(void);

#endif
