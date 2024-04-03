#include <stdlib.h>
#include <stdio.h>

#include "playlist.h"


Playlist* initPlaylist() {
    Playlist* p = (Playlist*)malloc(sizeof(Playlist));
    if (p == NULL)
        return NULL;

    p->tete = p->queue = NULL;
    return p;
}

bool addTrack(Playlist* p, Track* t) {
    if (p == NULL || t == NULL)
        return false;

    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL)
        return false;

    nouveauNoeud->track = t;
    nouveauNoeud->svt = NULL;

    if (p->tete == NULL) {
        p->tete = p->queue = nouveauNoeud;
    } else {
        p->queue->svt = nouveauNoeud;
        p->queue = nouveauNoeud;
    }

    return true;
}

Playlist* destructiveMerge(Playlist* p1, Playlist* p2) {
    if (p1 == NULL || p2 == NULL)
        return NULL;

    Playlist* mergedList = initPlaylist();
    if (mergedList == NULL)
        return NULL;

    Noeud* bal1 = p1->tete;
    Noeud* bal2 = p2->tete;

    while (bal1 != NULL && bal2 != NULL) {
        int cmp = compareTrack(bal1->track, bal2->track);
        if (cmp < 0) {
            addTrack(mergedList, bal1->track);
            bal1 = bal1->svt;
        } else if (cmp > 0) {
            addTrack(mergedList, bal2->track);
            bal2 = bal2->svt;
        } else {
            addTrack(mergedList, bal1->track);
            bal1 = bal1->svt;
            bal2 = bal2->svt;
        }
    }

    while (bal1 != NULL) {
        addTrack(mergedList, bal1->track);
        bal1 = bal1->svt;
    }

    while (bal2 != NULL) {
        addTrack(mergedList, bal2->track);
        bal2 = bal2->svt;
    }

    p1->tete = p1->queue = NULL;
    p2->tete = p2->queue = NULL;

    return mergedList;
}





/** 
 * Affiche le contenu d'une playlist
 * PRE: p: pointeur non null vers la playtlist
 * POST: affiche le contenu de la playlist
 */
void printPlaylist (Playlist* p) {
    Noeud *bal = p->tete;
    int trackCnt = 0;
    while (bal != NULL) {
        printf("%d ", ++trackCnt);
        printTrack(bal->track);
        printf("\n");
        bal = bal->svt;
    }
    if (trackCnt == 0)
        printf("/\n");
}

