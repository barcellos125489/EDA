#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct map{
    int chave;
    char dados[7];
    int proxima;
} Map;

int hashcalc(char * placa, int tentativa);
