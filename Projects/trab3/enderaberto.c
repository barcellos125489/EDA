#include "enderaberto.h"

Map** conflito_primario(Map** vetor, Map* inserido){
    int i = inserido->chave+1;
    while(vetor[i]->dados){
        i++;
    }    
    vetor[i]=inserido;
    Map* auxiliar = vetor[inserido->chave]
    while(auxiliar->prox != NULL){
        auxiliar = auxiliar->proxima;
    }
    auxiliar->proxima=vetor[i];
    return vetor;
}

Map** conflito_secundario(Map** vetor, Map*inserido){
    //temos que pegar o errado, mudar ele de posição, colocar o certo na posição antiga do errado.
    int i= inserido->chave;
    Map* errado = vetor[i];
    vetor[i] = inserido;
    i++;
    while(vetor[i]->dados){
        i++;
    }
    vetor[i]=errado;
    Map* auxiliar=vetor[errado->chave];
    while(auxiliar->chave == errado->chave){
        auxiliar = auxiliar->proxima;
    }
    auxiliar->proxima = i;
    return vetor;
}
