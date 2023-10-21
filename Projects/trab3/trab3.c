#include "enderaberto.h"



int main(void){
    FILE* arq = fopen("placasMercosul.txt","r");
    char string[10];
    char dados[7];
    for(int i=0; i<128; i++){
        if(fgets(string,10,arq)){
            for(int cont=0;cont<10;cont++) printf("%d, %c\n", cont, string[cont]);
            printf("%d , %s\n",i, string);
        }
    }
    return 0;
}