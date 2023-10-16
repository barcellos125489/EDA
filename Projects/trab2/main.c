#include "natacao.h"


int main (void){
    Abb* arvore;
    arvore= cria_arvore();
    arvore = insere_no(arvore, 120);
    arvore = insere_no(arvore, 112);
    arvore = insere_no(arvore, 137);
    arvore = insere_no(arvore, 95);
    arvore = insere_no(arvore, 115);
    arvore = insere_no(arvore, 107);
    arvore = insere_no(arvore, 118);
    arvore = insere_no(arvore, 125);
    arvore = insere_no(arvore, 150);
    printf("%d\n", arvore->esq->pai->chave);




    return 0;
}