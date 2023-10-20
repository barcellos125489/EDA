#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef Struct map{
    int chave;
    char dados[7];
    struct map* proxima;
} Map;

int hash(char * placa, int tentativa);
