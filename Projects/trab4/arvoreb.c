#include "arvoreb.h"

struct node {
	int chave;
	void* info;
};

struct pagina {
	Pagina* pai;
	int num_chaves;
	Pagina* filho_esquerdo;
	Pagina** filho_direito;
	Node** nodes;
};

struct arvore {
	Pagina* raiz;
	int ordem;
};
struct no {
    int ndesc;
    int chave[MAX]; /* não inclui overflow da chave */
    t_no* ramo[MAX + 1];
};
Arvore* cria_arvore(int ordem)
{

	Arvore* nova = (Arvore*)malloc(sizeof(Arvore*));
	if (nova == NULL) return NULL;
	nova->raiz = NULL;
	nova->ordem = ordem;
	return nova;
}

Pagina* cria_pagina_vazia(Arvore* arvore, Pagina* pai)
{
	Pagina* pagina_nova = (Pagina*)malloc(sizeof(Pagina));
	if (pagina_nova == NULL) return NULL;
	pagina_nova->pai = pai;
	pagina_nova->num_chaves = 0;
	pagina_nova->nodes = (Node**)malloc(arvore->ordem * sizeof(Node*));
	if (pagina_nova->nodes == NULL) return NULL;
	pagina_nova->filho_direito = (Pagina**)malloc(arvore->ordem * sizeof(Pagina*));
	if (pagina_nova->filho_direito == NULL) return NULL;
	pagina_nova->filho_esquerdo = NULL;

	for (int i = 0; i < arvore->ordem; i++)
	{
		pagina_nova->nodes[i] = NULL;
		pagina_nova->filho_direito[i] = NULL;
	}
	return pagina_nova;
}

Pagina* criar_pagina(int ordem) {
    Pagina* nova_pagina = (Pagina*)malloc(sizeof(Pagina));
    if (nova_pagina == NULL) {
        // Tratamento de erro, como imprimir uma mensagem ou retornar NULL
        fprintf(stderr, "Erro: Falha na alocação de memória para a nova página.\n");
        return NULL;
    }

    nova_pagina->pai = NULL;
    nova_pagina->num_chaves = 0;
    nova_pagina->filho_direito = (Pagina**)malloc((ordem + 1) * sizeof(Pagina*));
    if (nova_pagina->filho_direito == NULL) {
        // Tratamento de erro
        fprintf(stderr, "Erro: Falha na alocação de memória para os filhos da página.\n");
        free(nova_pagina);
        return NULL;
    }

    nova_pagina->nodes = (struct node**)malloc(ordem * sizeof(struct node*));
    if (nova_pagina->nodes == NULL) {
        // Tratamento de erro
        fprintf(stderr, "Erro: Falha na alocação de memória para os nós da página.\n");
        free(nova_pagina->filho_direito);
        free(nova_pagina);
        return NULL;
    }

    for (int i = 0; i < ordem; i++) {
        nova_pagina->filho_direito[i] = NULL;
        nova_pagina->nodes[i] = NULL;
    }

    nova_pagina->filho_direito[ordem] = NULL;

    return nova_pagina;
}
int comparador(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void ordena_pagina(Node** pg)
{
	qsort(pg, MAX, sizeof(Node*), comparador);
}

// Função auxiliar para encontrar a posição da chave em uma página
int encontrar_posicao(Pagina* pagina, int chave) {
    int posicao = 0;
    while (posicao < pagina->num_chaves && chave > pagina->nodes[posicao]->chave) {
        posicao++;
    }
    return posicao;
}

// Função auxiliar para inserir uma chave em uma página
void inserir_na_pagina(Pagina* pagina, int posicao, struct node* novo_node) {
    for (int i = pagina->num_chaves; i > posicao; i--) {
        pagina->nodes[i] = pagina->nodes[i - 1];
        pagina->filho_direito[i + 1] = pagina->filho_direito[i];
    }

    pagina->nodes[posicao] = novo_node;
    pagina->filho_direito[posicao + 1] = pagina->filho_direito[posicao];
    pagina->num_chaves++;
}

// Função auxiliar para dividir uma página quando ela está cheia
void dividir_pagina(Pagina* pai, int posicao, Pagina* cheia) {
    int meio = cheia->num_chaves / 2;
    struct node* chave_promovida = cheia->nodes[meio];

    Pagina* nova_pagina = criar_pagina(cheia->num_chaves);

    nova_pagina->filho_esquerdo = cheia->filho_direito[meio + 1];
    cheia->filho_direito[meio + 1] = NULL;

    for (int i = meio + 1; i < cheia->num_chaves; i++) {
        nova_pagina->nodes[i - meio - 1] = cheia->nodes[i];
        nova_pagina->filho_direito[i - meio] = cheia->filho_direito[i + 1];
        cheia->nodes[i] = NULL;
        cheia->filho_direito[i + 1] = NULL;
    }

    cheia->num_chaves = meio;

    int posicao_pai = encontrar_posicao(pai, chave_promovida->chave);

    inserir_na_pagina(pai, posicao_pai, chave_promovida);
    pai->filho_direito[posicao_pai + 1] = nova_pagina;
    nova_pagina->pai = pai;
}

// Função principal de inserção
void inserir_na_arvore(struct arvore* arvore, int chave, void* info) {
    struct node* novo_node = (struct node*)malloc(sizeof(struct node));
    novo_node->chave = chave;
    novo_node->info = info;

    Pagina* raiz = arvore->raiz;

    if (raiz->num_chaves == arvore->ordem - 1) {
        // A raiz está cheia, precisamos criar uma nova raiz
        Pagina* nova_raiz = criar_pagina(arvore->ordem);
        nova_raiz->filho_esquerdo = raiz;
        arvore->raiz = nova_raiz;  // Atualiza a raiz da árvore

        dividir_pagina(nova_raiz, 0, raiz);
        int posicao = encontrar_posicao(nova_raiz, chave);
        if (posicao < nova_raiz->num_chaves && chave > nova_raiz->nodes[posicao]->chave) {
            posicao++;
        }
        inserir_na_pagina(nova_raiz, posicao, novo_node);
    }
    else {
        // A raiz não está cheia, podemos inserir diretamente nela
        int posicao = encontrar_posicao(raiz, chave);
        inserir_na_pagina(raiz, posicao, novo_node);
    }
}


void imprime_intervalo(t_no* arv, int lim_inf, int lim_sup) {
    if (arv == NULL) {
        return;
    }
    int i;
    for (i = 0; i < arv->ndesc; i++) {
        if (arv->chave[i] > lim_inf) {
            imprime_intervalo(arv->ramo[i], lim_inf, lim_sup);
            if (arv->chave[i] < lim_sup) {
                printf("(%d) ", arv->chave[i]);
            }
        }
    }

    imprime_intervalo(arv->ramo[i], lim_inf, lim_sup);
}

