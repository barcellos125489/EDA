#include "enderaberto.h"

#define TAM 1031

int main(void){
    Map* vetor[TAM];
    FILE* arq = fopen("placasMercosul.txt","r");
    char string[10];
    char dados[7];
    for(int i=0; i<512; i++){
        if(fgets(string,10,arq)){
            for(int cont=0;cont<7;cont++){
                dados[cont]=string[cont];
            } 
        }
        printf("%d\n", hashcalc(dados,0));

    }
    return 0;
}