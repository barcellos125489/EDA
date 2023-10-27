#include "enderaberto.h"

#define LER 512

int main(void){
    Map* vetor[TAM];
    int colisoes=0;
    for(int i=0; i<TAM; i++){
        vetor[i]=NULL;
    }
    FILE* arq = fopen("placasMercosul.txt","r");
    if(arq ==NULL){
        printf("erro ao abrir o arquivo\n");
    }
    char string[8];
    for(int i=0; i<LER; i++){
        if(fscanf(arq, "%s\r\n", string) == 1){
            insere_hashtable(vetor,string,&colisoes);
            remove_hashtable(vetor, string);
        }    
    }
    for(int i=0; i<TAM; i++){
        if(vetor[i]!=NULL){
            printf("%s, %d, o prox eh %d\n",vetor[i]->dados, i, vetor[i]->proxima);
        }
    }
    printf("Ocorreram %d colisoes \n",colisoes);
    return 0;
}