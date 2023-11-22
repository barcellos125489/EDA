#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

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

typedef struct fila{
    int* visitados;
    int* proximos;
}Fila;

Grafo* grafoCria(int nv, int na);
void bfs(Grafo* grafo);
Viz* criaViz(Viz* head, int noj, float peso);
