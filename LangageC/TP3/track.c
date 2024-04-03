#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "track.h"


Track* initTrack (char* artiste, char* titre, int duree) {
    // TODO
    Track* t = (Track*) malloc(sizeof(Track));
    if (t == NULL) {
        return NULL;
    }
    strcpy(t->artiste, artiste);
    strcpy(t->titre, titre);
    t->duree = duree;
    return t;
}

int compareTrack (Track* t1, Track* t2) {
    // TODO
    int cmp = strcmp(t1->artiste, t2->artiste);
    if (cmp != 0) {
        return cmp;
    }
    cmp = strcmp(t1->titre, t2->titre);
    if (cmp != 0) {
        return cmp;
    }
    return t1->duree - t2->duree;


}

void printTrack (Track *t) {
    printf("%s - %s - %d", t->artiste, t->titre, t->duree);
}

