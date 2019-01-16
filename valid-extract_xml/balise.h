/* balise.h : module de gestion de balises (style HTML ou XML)

Emmanuel Chieze, UQAM, INF3135, A12, TP2
*/

#ifndef BALISE_H
#	define BALISE_H
#include "chaine.h"

/* TypeBalise :
   definit les cinq types de balises gerees : balises de debut (<TEXT>), de fin (</TEXT>), balises de debut qui se terminent sans contenu (<TEXT/>),
   balises de commentaires et meta-commandes (<!...>) et balises de directives (<?...>)
*/
typedef enum {DEBUT, FIN, DEBUTFIN, COMMENTAIRES, DIRECTIVE} TypeBalise;

typedef struct balise * Balise;

/* baliseCree :
   cree une balise a partir du contenu textuel. Nom contient le contenu de la balise (excluant < et >).
   Pour les balises COMMENTAIRES et DIRECTIVE, ni le nom ni les attributs ne sont specifies (pointeur NULL).
   Pour les autres balises, le nom doit etre une chaine valide (pointeur non NULL)
*/
Balise baliseCree(Chaine nom);

/* baliseLitNom :
   renvoie le nom d'une balise valide de type DEBUT, FIN ou DEBUTFIN prealablement creee par baliseCree.

   balise doit etre une balise valide (pointeur non NULL) de type DEBUT, FIN ou DEBUTFIN.
*/
Chaine baliseLitNom(Balise balise);

/* baliseLitType :
   renvoie le type d'une balise valide prealablement creee par baliseCree

   balise doit etre une balise valide (pointeur non NULL)
*/
TypeBalise baliseLitType(Balise balise);

/* baliseLitAttributs :
   renvoie la liste des attributs d'une balise valide de type DEBUT, FIN ou DEBUTFIN prealablement creee par baliseCree.
   renvoie NULL s'il n'y a aucun attribut

   balise doit etre une balise valide (pointeur non NULL)
*/
Chaine baliseLitAttributs(Balise balise);

/* baliseSupprimme :
   supprimme l'ensemble du contenu d'une balise valide prealablement creee par baliseCree

   balise doit etre une balise valide (pointeur non NULL)
*/
void baliseSupprimme(Balise balise);
#endif /* BALISE_H */
