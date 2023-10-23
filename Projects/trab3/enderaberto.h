#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1031

typedef struct map{
    int chave;
    int proxima;
    char* dados;
} Map;

int hashcalc(char * placa, int tentativa);

void insere_hashtable(Map** hashtable, char* string);