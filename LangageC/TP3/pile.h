#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct Noeud {
    int val;
    struct Noeud* suivant;
} Noeud;

typedef Noeud* Pile;


Pile initPile ();

bool pileVide (Pile p);
bool push (Pile* p, int e);
int pop (Pile* p);
void viderPile (Pile* p);
void afficherPile (Pile p);