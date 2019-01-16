/* fichierBalises.h : Module implementant la lecture sequentielle d'un fichier de balises (style HTML ou XML) (lecture element d'information par element d'information, ou un element d'information est soit une balise, soit un morceau de texte de taille maximale)

On suppose que les caracteres < et > ne servent qu'a specifier des balises, et qu'ils sont representes par &lt; et &gt; pour designer le caractere lui-meme.

Emmanuel Chieze, UQAM, INF3135, A12, TP2
*/

#ifndef FICHIERBALISES_H
#	define FICHIERBALISES_H
#include "chaine.h"
#include "balise.h"

/* TypeInfo :
   Exemple : 	Soit le passage :
		<TEXT lang="fr">toto</TEXT>
		Ce passage contient deux balises (<TEXT lang="fr">, balise de debut avec un attribut, et </TEXT>, balise de fin), et un bout de texte (toto).
*/
typedef enum {BALISE, TEXTE} TypeInfo;

typedef struct fichierBalises * fichierBalises;

struct info {
        TypeInfo type;
        union {
                Chaine texte;
                Balise balise;
        } contenu;
};

typedef struct info * Info;

/* fichierBalisesOuvre :
	ouvre un fichier texte qui sera interprete comme un fichier de balises. Renvoie NULL en cas d'impossibilite d'ouvrir le fichier.
*/
fichierBalises fichierBalisesOuvre(char * nom_fichier);

/* fichierBalisesFerme :
	ferme un fichier prealablement ouvert par fichierBalisesOuvre
*/
void fichierBalisesFerme(fichierBalises fichier);

/* fichierBalisesLit :
	renvoit le prochain element d'information, ou NULL si on est en fin de fichier (ou en cas de probleme quelconque de lecture).
	Dans l'exemple donne dans la presentation de TypeInfo, un premier appel a fichierBalisesLit renverrait la balise ouvrante, un second appel renverrait le texte "toto" et un troisieme appel renverrait la balise fermante
	Dans le cas d'une information de type textuel, cette information est de taille maximale. Deux appels successifs a fichierBalisesLit ne peuvent donc pas renvoyer deux elements de type textuel.
	En cas de presence d'une balise commentaire ou directive, cette balise est ignoree par fichierBaliseLit, qui renvoit alors l'element d'information suivent.
*/
Info fichierBalisesLit(fichierBalises fichier);
#endif /* FICHIERBALISES_H */
