#include <stdlib.h>
#include <stdio.h>

typedef struct abb{
    int chave;
    struct abb *pai;
    struct abb *dir;
    struct abb *esq;
    } Abb;

Abb* cria_arvore(void);

Abb* insere_no(Abb* arvore, int altura);