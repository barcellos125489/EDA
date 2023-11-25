#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef struct viz{
    int noj;
    int nor;
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
typedef struct forest_node_t {
    void* value;
    struct forest_node_t* parent;
}forest_node;

Grafo* grafoCria(int nv, int na);
void bfs(Grafo* grafo);
Viz* criaViz(Viz* head, int noj, float peso, int nor);
forest_node** kruskal(Grafo* grafo);
forest_node* Find(forest_node* node);
void destroi_grafo(Grafo* grafo);
