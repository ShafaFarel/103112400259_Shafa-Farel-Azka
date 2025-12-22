#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)return P; 
        P = P->next;
    }
    return NULL;
}
void connectNode(Graph &G , infoGraph Start , infoGraph End) {
    adrNode pStart = findNode(G, Start);
    adrNode pEnd = findNode(G, End);
    
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}