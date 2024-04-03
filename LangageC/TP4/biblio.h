#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include <stdbool.h>

// Définition de constantes

#define MAX_TITRE         128
#define MAX_AUTEUR        80
#define MAX_EDITEUR       50
#define MAX_LIGNE_LIVRE   MAX_TITRE+MAX_AUTEUR+MAX_EDITEUR+50

// Définition de types

enum Genre {BD, PO, TH, RO, RH, LF, LE, SC, IN, SF, SA, HI, GENRES_NUM};  // GENRES_NUM = nombre total de genres

struct Livre {
   char  titre[MAX_TITRE+1];
   char  auteur[MAX_AUTEUR+1];
   long  isbn;
   char  editeur[MAX_EDITEUR+1];
   int   an;
   enum Genre genre;   // type 'enum Genre' peut être directement défini dans 'struct Livre'
};


// Déclaration de fonctions

/* Lit les informations d'un livre à l'entrée standard
 * POST: l a été complété avec les informations lues sur stdin
 *       (à raison d'une information par ligne)
 * RES: renvoie vrai si l a été correctement saisi; faux sinon
 */
bool lireLivre (struct Livre* l);

/* Renvoie le genre littéraire correspondant à une chaîne de caractères
 * PRE: s: chaîne de caractères
 *      lesGenres: tableau de chaînes terminé par NULL 
 *                 [variable globale contenant les chaînes de caractères 
 *                  correspondant aux genres littéraires]
 * RES: renvoie le genre littéraire correspondant à s;
 *      -1 si aucun genre correspondant n'a été trouvé dans lesGenres
 */
enum Genre str2genre (char* s);

/* Renvoie la chaîne de caractères correspondant à un genre littéraire
 * PRE: g: genre littéraire
 *      lesGenres: tableau de chaînes terminé par NULL 
 *                 [variable globale contenant les chaînes de caractères 
 *                  correspondant aux genres littéraires]
 * RES: renvoie la chaîne de caractères définie dans lesGenres, 
 *      correspondant au genre g ; NULL si le genre n'est pas défini
 */
char* genre2str (enum Genre g);

/* Convertit un livre en chaîne de caractères
 * PRE: s: buffer de MAX_LIGNE_LIVRE caractères
 *      l: livre à convertir
 * RES: renvoie la chaîne s contenant les informations du livre l
 */
char* livre2str (char* s, struct Livre l);

/* Affiche le contenu d'un tableau de livres
 * PRE: bib: tableau de t livres
 * POST: affiche les informations des t livres de bib, 
 *       à raison d'un livre par ligne
 */
void afficherBib (const struct Livre* bib, int t);

/* Ajoute un livre à un tableau
 * PRE: bib: adresse d'un tableau de nbreL livres, de capacité physique taille
 *      l: livre à ajouter à bib
 * POST: le livre l a été ajouté à bib, nbreL incrémenté
 *       et taille (capacité physique) mise à jour
 * RES: renvoie vrai si bib, nbreL et taille ont bien été mis à jour;
 *      faux sinon
 */
bool ajouterLivre (struct Livre ** bib, struct Livre l, int* nbreL, int* taille);


/*************************************************************************************/


/// Bonus 3: qsort

// Une explicatoin sur la généricité en C est disponible sur 
//   https://youtu.be/xQBefPZw2jA
typedef int (*fctcmp)(const void *, const void*);

/* Compare l'année d'édition de deux livres
 * PRE: a,b: livres à comparer
 * RES: renvoie 0 si les livres a et b ont la même année d'édition;
 *      une valeur positive si l'année d'édition de a est postérieure à celle de b;
 *      une valeur négative si l'année d'édition de a est antérieure à celle de b
 */
int comparerLivre (const struct Livre* a, const struct Livre* b);



/*
* PRE: Un nom de fichier valide est fourni en argument sur la ligne de commande.
* POST: Tous les livres lus au clavier ont été ajoutés à la bibliothèque et la bibliothèque a été sauvegardée dans un fichier binaire portant le nom spécifié sur la ligne de commande.
* RES: Aucun résultat renvoyé, mais le programme exécute les actions décrites ci-dessus.
*/
void ecrireFichier(const char* nomFichier, struct Livre* bib, int nbreL);

/*
* PRE: Un nom de fichier valide est fourni en argument sur la ligne de commande.
* POST: Tous les livres contenus dans le fichier ont été lus et stockés dans la bibliothèque.
* RES: Aucun résultat renvoyé, mais la bibliothèque contenant les livres lus est mise à jour.
*/
bool lireFichier(struct Livre** bib,size_t taille_physique,size_t taille_logique, FILE* fichier);








#endif   // _BIBLIO_
