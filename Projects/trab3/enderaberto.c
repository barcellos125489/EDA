#include "enderaberto.h"

Map** conflito_primario(Map** vetor, Map* inserido){
    int i = inserido->chave+1;
    while(vetor[i]->dados){
        i++;
    }    
    vetor[i]=inserido;
    Map* auxiliar = vetor[inserido->chave];
    while(auxiliar->proxima != NULL){
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

int hash(char* placa, int tentativa){
    //utilizei o método de folding com uma multiplicação no final, para que seja possível ocupar mais posições do que com um simples folding
    int Hash=0;
    for(int i=0; i<7;i++){
        Hash+= placa[7];
    }
    Hash+=tentativa;
    Hash*=1.9;
    return Hash;
}

