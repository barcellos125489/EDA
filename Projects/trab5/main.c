#include "grafo.h"

int main(void){
    Grafo* grafo_principal= grafoCria(10,20);
    // vizinhos do vértice 1
    grafo_principal->vizinhos[0]= criaViz(grafo_principal->vizinhos[0],2,3);
    grafo_principal->vizinhos[0]= criaViz(grafo_principal->vizinhos[0],9,1);
    grafo_principal->vizinhos[0]= criaViz(grafo_principal->vizinhos[0],7,3);
    grafo_principal->vizinhos[0]= criaViz(grafo_principal->vizinhos[0],4,4);
    grafo_principal->vizinhos[0]= criaViz(grafo_principal->vizinhos[0],8,3);

    // vizinhos do vértice 2
    grafo_principal->vizinhos[1]= criaViz(grafo_principal->vizinhos[1],2,4);
    grafo_principal->vizinhos[1]= criaViz(grafo_principal->vizinhos[1],9,1);

    //vizinhos do vértice 3
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],0,3);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],8,4);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],5,1);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],3,1);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],7,2);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],9,4);
    grafo_principal->vizinhos[2]= criaViz(grafo_principal->vizinhos[2],1,4);

    //vizinhos do vértice 4
    grafo_principal->vizinhos[3]= criaViz(grafo_principal->vizinhos[3],2,1);
    grafo_principal->vizinhos[3]= criaViz(grafo_principal->vizinhos[3],4,2);
    grafo_principal->vizinhos[3]= criaViz(grafo_principal->vizinhos[3],6,2);

    //vizinhos do vértice 5
    grafo_principal->vizinhos[4]= criaViz(grafo_principal->vizinhos[4],7,4);
    grafo_principal->vizinhos[4]= criaViz(grafo_principal->vizinhos[4],0,4);
    grafo_principal->vizinhos[4]= criaViz(grafo_principal->vizinhos[4],3,2);
    grafo_principal->vizinhos[4]= criaViz(grafo_principal->vizinhos[4],6,2);

    //vizinhos do vértice 6
    grafo_principal->vizinhos[5]= criaViz(grafo_principal->vizinhos[5],2,1);
    grafo_principal->vizinhos[5]= criaViz(grafo_principal->vizinhos[5],6,3);

    //vizinhos do vértice 7
    grafo_principal->vizinhos[6]= criaViz(grafo_principal->vizinhos[6],5,3);
    grafo_principal->vizinhos[6]= criaViz(grafo_principal->vizinhos[6],3,2);
    grafo_principal->vizinhos[6]= criaViz(grafo_principal->vizinhos[6],4,2);

    //vizinhos do vértice 8
    grafo_principal->vizinhos[7]= criaViz(grafo_principal->vizinhos[7],9,2);
    grafo_principal->vizinhos[7]= criaViz(grafo_principal->vizinhos[7],2,2);
    grafo_principal->vizinhos[7]= criaViz(grafo_principal->vizinhos[7],0,3);
    grafo_principal->vizinhos[7]= criaViz(grafo_principal->vizinhos[7],8,1);
    grafo_principal->vizinhos[7]= criaViz(grafo_principal->vizinhos[7],4,4);

    //vizinhos do vértice 9
    grafo_principal->vizinhos[8]= criaViz(grafo_principal->vizinhos[8],0,3);
    grafo_principal->vizinhos[8]= criaViz(grafo_principal->vizinhos[8],2,4);
    grafo_principal->vizinhos[8]= criaViz(grafo_principal->vizinhos[8],9,4);
    grafo_principal->vizinhos[8]= criaViz(grafo_principal->vizinhos[8],7,1);

    //vizinhos do vértice 10
    grafo_principal->vizinhos[9]= criaViz(grafo_principal->vizinhos[9],1,1);
    grafo_principal->vizinhos[9]= criaViz(grafo_principal->vizinhos[9],2,4);
    grafo_principal->vizinhos[9]= criaViz(grafo_principal->vizinhos[9],0,1);
    grafo_principal->vizinhos[9]= criaViz(grafo_principal->vizinhos[9],8,4);
    grafo_principal->vizinhos[9]= criaViz(grafo_principal->vizinhos[9],7,2);


    return 0;
}