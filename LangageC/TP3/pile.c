#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "pile.h"

Pile initPile (){
    return NULL;
}

bool pileVide (Pile p){
    if (p == NULL){
        return true;
    }
    return false;
}

bool push(Pile* p, int e) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        return false;
    }
    nouveau -> val = e;
    nouveau -> suivant = *p;
    *p = nouveau;
    return true;

}


int pop (Pile *p){
    int e = (*p) -> val;
    Noeud* temp = *p;   
    *p = (*p) -> suivant;
    free(temp);
    return e;
}


void viderPile (Pile* p){
    while (!pileVide(*p)){
        pop(p);
    }
}

void afficherPile (Pile p){
    while (!pileVide(p)){
        printf("%d\n", pop(&p));
    }
}

