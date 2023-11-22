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

int presentenafila(int* vetor, int buscado, int sizefila){
    for(int i=0; i<sizefila;i++){
        if(vetor[i]==buscado) return 1;
    }
    return 0;
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

void add_visitado(Viz* no, Fila fila, int sizefila){
    if(fila.proximos[0]==no->noj){
        for(int i=0; i<sizefila-1;i++){
            fila.proximos[i]=fila.proximos[i+1];
        }
        fila.proximos[sizefila-1]=NULL;
        for(int i=0;i<sizefila; i++){
            if(fila.visitados[i]==NULL){
                fila.visitados[i]=no;
                break;
            }
        }
    }
    else{
        printf("Algo deu errado ao adicionar visitado %d\n", no->noj);
    }
}

void add_proximo(Viz* no, Fila fila, int sizefila){
    for(int i=0; i<sizefila; i++){
        if(fila.proximos[i]==NULL && presentenafila(fila.visitados,no->noj,sizefila)==0){
            fila.proximos[i]=no->noj;
            printf("Elemento %d adicionado à fila de proximos!\n", no->noj);
            break;
        }
    }
    
}

void bfs(Grafo* grafo){ //sempre começa pelo vértice 1
    struct fila fila;
    fila.proximos = (int*) malloc(sizeof(int)*grafo->numno);
    fila.visitados = (int*) malloc(sizeof(int)*grafo->numno);
    Viz* atual = grafo->vizinhos[0];
    add_visitado(atual,fila,grafo->numno);
    while(atual){
        add_proximo(atual,fila,grafo->numno);
        atual= atual->prox;
    }
    printf("Fila dos proximos: [")
    for(int i=0;i<grafo->numno;i++){
        printf("%d ",fila.proximos[i]);
    }
    printf("]\n");
    atual= grafo->vizinhos[fila.proximos[0]];
    add_visitado(atual, fila, grafo->numno);
    while(atual){
        add_proximo(atual,fila,grafo->numno);
        atual= atual->prox;
    }
}