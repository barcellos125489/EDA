#include"grafo.h"

Viz* criaViz(Viz* head, int noj, float peso, int nor) {
    /* insere vizinho no inicio da lista */
    Viz* no = (Viz*) malloc(sizeof(Viz));
    assert(no);
    no->noj = noj;
    no->nor = nor;
    no->peso = peso;
    no->prox = head;
    return no;
}

int presentenafila(Fila fila, int buscado, int sizefila){
    for(int i=0; i<sizefila;i++){
        if(fila.visitados[i]==buscado) return 0;
        if(fila.proximos[i]==buscado) return 0;
    }
    return 1;
}

int verificavazia(Fila fila){
    if(fila.proximos[0]==0) return 0;
    return 1; 
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

void add_visitado(int no, Fila fila, int sizefila){
    if(fila.proximos[0]==no){
        for(int i=0; i<sizefila-1;i++){
            fila.proximos[i]=fila.proximos[i+1];
        }
        fila.proximos[sizefila-1]=0;
        for(int i=0;i<sizefila; i++){
            if(fila.visitados[i]==0){
                fila.visitados[i]=no;
                break;
            }
        }
    }
    else{
        printf("Algo deu errado ao adicionar visitado %d\n", no);
    }
}

void add_proximo(Viz* no, Fila fila, int sizefila){
    for(int i=0; i<sizefila; i++){
        if(fila.proximos[i]==0 && presentenafila(fila,no->noj,sizefila)){
            fila.proximos[i]=no->noj;
            printf("Elemento %d adicionado à fila de proximos!\n", no->noj);
            break;
        }
    }
    
}

int comparador(const void *a, const void *b) {
    // Convertemos os ponteiros void para ponteiros de Viz
   Viz const* A = a;
   Viz const* B = b;
   if(A->peso>B->peso) return 1;
   if(A->peso<B->peso) return -1;
   return 0;
}

void add_ordenado(Viz* adicionado, Viz** destino, int tamanhodestino){
    for(int i=0; i<tamanhodestino; i++){
        if(destino[i]==adicionado){
            return;
        }
        if(destino[i]==NULL){
            destino[i]=adicionado;
            break;
        }
    }
    //qsort(destino,tamanhodestino,sizeof(Viz*),comparador);
    for(int i=0; i<tamanhodestino;i++){
        if(destino[i]==NULL){

        }
        else {
            for(int cont = 0; cont<tamanhodestino;cont++){
                if(destino[cont]==NULL){

                }
                else if(destino[i]->peso<destino[cont]->peso){
                    Viz* aux = destino[i];
                    destino[i]=destino[cont];
                    destino[cont]=aux;
                }
            }
        }
    }
}

void bfs(Grafo* grafo){ //sempre começa pelo vértice 1
    struct fila fila;
    fila.proximos = (int*) malloc(sizeof(int)*grafo->numno);
    fila.visitados = (int*) malloc(sizeof(int)*grafo->numno);
    for(int i=0; i<grafo->numno;i++){
        fila.proximos[i]=0;
        fila.visitados[i]=0;
    }
    Viz* atual = grafo->vizinhos[0];
    printf("Percorrendo 0\n");
    add_visitado(0,fila,grafo->numno);
    printf("Fila dos visitados: [");
    for(int i=0;i<grafo->numno;i++){
        printf("%d ",fila.visitados[i]);
    }
    printf("]\n");
    while(atual){
        add_proximo(atual,fila,grafo->numno);
        atual= atual->prox;
    }
    printf("Fila dos proximos: [");
    for(int i=0;i<grafo->numno;i++){
        printf("%d ",fila.proximos[i]);
    }
    printf("]\n");
    atual= grafo->vizinhos[fila.proximos[0]];
    while(verificavazia(fila)){
        printf("Percorrendo: %d\n", fila.proximos[0]);
        add_visitado(fila.proximos[0], fila, grafo->numno);
        printf("Fila dos visitados: [");
        for(int i=0;i<grafo->numno;i++){
            printf("%d ",fila.visitados[i]);
        }
        printf("]\n");
        while(atual){
            add_proximo(atual,fila,grafo->numno);
            atual= atual->prox;
        }
        printf("Fila dos proximos: [");
        for(int i=0;i<grafo->numno;i++){
            printf("%d ",fila.proximos[i]);
        }
        printf("]\n");
        atual= grafo->vizinhos[fila.proximos[0]];
    }
    
}

presentenafilabfs2(Fila fila,Viz* buscado, int tamanhofila ){
    for(int i=0;i<tamanhofila;i++){
        if(fila.visitados[i]==buscado->noj) return 0;
    }
    return 1;
}

void bfs2(Grafo* grafo,Viz** vetor){ //sempre começa pelo vértice 1
    struct fila fila;
    fila.proximos = (int*) malloc(sizeof(int)*grafo->numno);
    fila.visitados = (int*) malloc(sizeof(int)*grafo->numno);
    for(int i=0; i<grafo->numno;i++){
        fila.proximos[i]=0;
        fila.visitados[i]=0;
    }
    Viz* atual = grafo->vizinhos[0];
    add_visitado(0,fila,grafo->numno);
    while(atual){
        add_proximo(atual,fila,grafo->numno);
        if(presentenafilabfs2(fila,atual,grafo->numno)){
            add_ordenado(atual,vetor,grafo->numaresta);
        }
        atual= atual->prox;
    }
    atual= grafo->vizinhos[fila.proximos[0]];
    while(verificavazia(fila)){
        add_visitado(fila.proximos[0], fila, grafo->numno);
        while(atual){
            add_proximo(atual,fila,grafo->numno);
            if(presentenafilabfs2(fila,atual,grafo->numno)){
                add_ordenado(atual,vetor,grafo->numaresta);
            }
            atual= atual->prox;
        }
        atual= grafo->vizinhos[fila.proximos[0]];
    }
    
}

forest_node* MakeSet(void* value) {
    forest_node* node = malloc(sizeof(forest_node));
    node->value = value;
    node->parent = NULL;
    return node;
}

void Union(forest_node* node1, forest_node* node2) 
{
    node2->parent = node1;
    return;
}

forest_node* Find(forest_node* node) {
    forest_node* temp;
    forest_node* root = node;
    while (root-> parent != NULL) {
        root = root-> parent;
    }
    return root;
}

forest_node** kruskal(Grafo* grafo){
    //estamos nos baseando que o unico grafo recebi é o do enunciado
    forest_node** vetor_floresta = (forest_node**)malloc(sizeof(forest_node*) * grafo->numno);
    for (int i = 0; i < grafo->numno; i++)
    {
        vetor_floresta[i] = MakeSet(i);
    }
    Viz** arestas = (Viz**)malloc(sizeof(Viz*)*grafo->numaresta);
    for(int i=0;i<grafo->numaresta;i++){
        arestas[i]=NULL;
    }
    bfs2(grafo,arestas);
    for(int i=0;i<grafo->numaresta;i++){
        printf("aresta na posicao %d é %02f\n",i,arestas[i]->peso);
    }
    for(int i=0;i<grafo->numaresta;i++){
        if(Find(vetor_floresta[arestas[i]->noj])!=Find(vetor_floresta[arestas[i]->nor])){
            Union(Find(vetor_floresta[arestas[i]->noj]),Find(vetor_floresta[arestas[i]->nor]));
        }
    }
    return vetor_floresta;
}

void destroi_grafo(Grafo* grafo){
    Viz* aux, *atual;
    for(int i=0;i<grafo->numno;i++){
        atual=grafo->vizinhos[i];
        aux=atual->prox;
        while(atual){
            printf("%d\n",atual->noj);
            free(atual);
            printf("%d\n",atual->noj);
            atual=aux;
            if(aux){
                aux=aux->prox;
            }
        }
    }
    free(grafo->vizinhos);
    free(grafo);
}