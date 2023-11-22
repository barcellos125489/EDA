#include<stdlib.h>
#include<stdio.h>

typedef struct viz{
    int noj;
    float peso;
    struct viz* prox;
}Viz;



typedef struct grafo{
    int numno;
    int numaresta;
    Viz** vizinhos; //vizinhos[i] aponta para uma lista dos vizinhos do vértice i
}Grafo;

static Viz* criaViz(Viz* head, int noj, float peso) {
    /* insere vizinho no inicio da lista */
    Viz* no = (Viz*) malloc(sizeof(Viz));
    assert(no);
    no->noj = noj;
    no->peso = peso;
    no->prox = head;
    return no;
}

Grafo* grafoCria(int nv, int na) {
    int i;
    Grafo* g = (Grafo *) malloc(sizeof(Grafo));
    g->nv = nv;
    g->na = na;
    g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
    for (i = 0; i < nv; i++) g->viz[i] = NULL;
    return g;
}