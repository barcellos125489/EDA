#include "natacao.h"


Abb *cria_arvore(void){
    return NULL;
}

Abb* insere_no(Abb* arvore, int altura){
    if(arvore==NULL){
        arvore = (Abb*)malloc(sizeof(Abb));
        arvore->chave = altura;
        arvore->esq = arvore->dir = NULL;
    }
    else if(altura< arvore->chave){
        arvore->esq = insere_no(arvore->esq,altura);
        arvore->esq->pai = arvore; 
    }
    else{
        arvore->dir = insere_no(arvore->dir, altura);
        arvore->dir->pai = arvore;
    }
    return arvore;
}