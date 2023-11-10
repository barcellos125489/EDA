#include <stdio.h>
#include <stdlib.h>
#define MIN 2
#define MAX 4

typedef struct pagina Pagina;
typedef struct node Node;
typedef struct arvore Arvore;
typedef struct no t_no;



Arvore* insere(Arvore* arv, int chave, void* info);
void ordena_pagina(Node** pg);
int comparador(const void* a, const void* b);
Pagina* cria_pagina_vazia(Arvore* arvore, Pagina* pai);
Arvore* cria_arvore(int ordem);
void inserir_na_arvore(struct arvore* arvore, int chave, void* info);
void dividir_pagina(Pagina* pai, int posicao, Pagina* cheia);
int encontrar_posicao(Pagina* pagina, int chave);
void inserir_na_pagina(Pagina* pagina, int posicao, struct node* novo_node);
Pagina* criar_pagina(int ordem);
imprime_intervalo(t_no* arv, int lim_inf, int lim_sup);

