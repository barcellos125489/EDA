#include"grafo.h"

Viz* criaViz(Viz* head, int noj, float peso) {
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
    g->numno = nv;
    g->numaresta = na;
    g->vizinhos = (Viz **) malloc(sizeof(Viz *) * g->numno);
    for (i = 0; i < nv; i++) g->vizinhos[i] = NULL;
    return g;
}

void bfs(Grafo* grafo){ //sempre começa pelo vértice 1
    struct fila fila;
    fila.proximos = (int*) malloc(sizeof(int)*grafo->numno);
    fila.visitados = (int*) malloc(sizeof(int)*grafo->numno);

}