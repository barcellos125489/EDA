#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 1031

typedef struct map{
    int chave;
    int proxima;
    char dados[8];
} Map;

unsigned int hashcalc(char * placa, int tentativa);

void insere_hashtable(Map** hashtable, char* string, int* colisoes);

void remove_hashtable(Map** hashtable, char* string);