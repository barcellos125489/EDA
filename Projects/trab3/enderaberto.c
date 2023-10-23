#include "enderaberto.h"

void insere_hashtable(Map** vetor, char* string ){
    Map* inserido = (Map*) malloc(sizeof(Map));
    inserido->chave = hashcalc(string,0);
    inserido->proxima = -1;
    inserido->dados = string;
    //se nao conseguir colocar no lugar certo
    if(vetor[hashcalc(string,0)]==NULL){
        vetor[hashcalc(string,0)]=inserido;
    } 
    else if(vetor[hashcalc(string,0)]->chave == inserido->chave){
        //conflito primario
        printf("\nOCORREU UM CONFLITO PRIMARIO COM VALOR %d\n", inserido->chave);
        int i=0;
        while(vetor[hashcalc(string,i++)]);
        vetor[i]=inserido;
        Map* aux = vetor[inserido->chave];
        while(aux->proxima!=-1){
            aux = vetor[aux->proxima];
        }
        aux->proxima = i;
    }
    else{
        printf("\nOCORREU UM CONFLITO SECUNDARIO COM O VALOR %d\n",inserido->chave);
        Map* errado = vetor[inserido->chave];
        vetor[inserido->chave]=inserido;
        int i = 0;
        while(vetor[hashcalc(errado->dados,i++)]);
        vetor[hashcalc(errado->dados,i)]=errado;
        Map* aux = vetor[errado->chave]; 
        while(aux->proxima!=-1){
            aux = vetor[aux->proxima];
        }
        aux->proxima=hashcalc(errado->dados,i);
    }
}

int hashcalc(char* placa, int tentativa){
    //utilizei o método de folding com uma multiplicação no final, para que seja possível ocupar mais posições do que com um simples folding
    unsigned int Hash=0;
    for(int i=0; i<7;i++){
        Hash+= placa[i];
    }
    Hash+=tentativa;
    Hash*=Hash;
    //VAPO
    Hash = Hash%1031;
    //Hash = (Hash & 0x1FF800)>>8;
    return Hash;
}

