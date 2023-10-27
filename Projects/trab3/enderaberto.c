#include "enderaberto.h"

void insere_hashtable(Map** vetor, char* string, int* colisoes ){
    Map* inserido = (Map*) malloc(sizeof(Map));
    inserido->chave = hashcalc(string,0);
    inserido->proxima = -1;
    strcpy(inserido->dados,string);
    //se conseguir colocar no lugar certo
    if(vetor[hashcalc(string,0)]==NULL){
        vetor[hashcalc(string,0)]=inserido;
        return;
    } 
    else if(vetor[hashcalc(string,0)]->chave == inserido->chave){
        //conflito primario
        colisoes[0]++;
        printf("\nOCORREU UM CONFLITO PRIMARIO COM VALOR %d sendo a string %s\n", inserido->chave, inserido->dados);
        int i=0;
        while(vetor[hashcalc(string,i)]){
            i++;
            colisoes[0]++;
        } 
        vetor[hashcalc(inserido->dados,i)]=inserido;
        Map* aux = vetor[inserido->chave];
        while(aux->proxima!=-1){
            aux = vetor[aux->proxima];
        }
        aux->proxima = hashcalc(inserido->dados,i);
        return;
    }
    else{
        //conflito secundario
        colisoes[0]++;
        printf("\nOCORREU UM CONFLITO SECUNDARIO COM O VALOR %d sendo a string %s\n",inserido->chave, inserido->dados);
        Map* errado = vetor[inserido->chave];
        vetor[inserido->chave]=inserido;
        int i = 0;
        while(vetor[hashcalc(errado->dados,i)]){
            i++;
            colisoes[0]++;
        }
        vetor[hashcalc(errado->dados,i)]=errado;
        Map* aux = vetor[errado->chave]; 
        while(aux->proxima!=inserido->chave){
            aux = vetor[aux->proxima];
        }
        aux->proxima=hashcalc(errado->dados,i);
        return;
    }
}

void remove_hashtable(Map** vetor, char* string){
    if(strcmp(vetor[hashcalc(string,0)]->dados, string)==0){
        Map* atual = vetor[hashcalc(string,0)];
        if(atual->proxima!=-1){
            int aux = atual->proxima;
            vetor[hashcalc(string,0)]=vetor[aux];
            vetor[aux]=NULL;
        }
        else{
            vetor[hashcalc(string,0)]=NULL;
        }
        free(atual);
        return;
    }    
    else{
        Map* ant, *atual;
        ant=vetor[hashcalc(string,0)];
        atual=vetor[ant->proxima];
        while(strcmp(atual->dados,string)!=0){
            ant=atual;
            atual=vetor[atual->proxima];
        }
        int aux=ant->proxima;
        ant->proxima=atual->proxima;
        vetor[aux]=NULL;
        free(atual);
    }
}

/*int hashcalc(char* placa, int tentativa){
    //utilizei o método de folding com uma multiplicação no final, para que seja possível ocupar mais posições do que com um simples folding
    unsigned int Hash=0;
    for(int i=0; i<7;i++){
        Hash+= placa[i];
    }
    Hash*=Hash;
    //VAPO
    Hash+=tentativa;
    Hash = Hash%1031;
    //Hash = (Hash & 0x1FF800)>>8;
    
    return Hash;
}*/

// peguei de um site http://www.cse.yorku.ca/~oz/hash.html
unsigned int hashcalc(char *placa, int tentativa) {
    unsigned int hash = 5381;
    int c;

    for (int i = 0; i < 7; i++) {
        c = *placa++;
        hash = ((c<<5)+c) + ((hash<<5)+hash);
    }
    hash*=257; //
    return (hash * (tentativa+1)) % 1031;
}

