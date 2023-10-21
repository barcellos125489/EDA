#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct map{
    int chave;
    char dados[7];
    struct map* proxima;
} Map;

int hash(char * placa, int tentativa);
