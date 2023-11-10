#include "arvoreb.h"

int main(void)
{
	Arvore*arvore = cria_arvore(MAX);


	inserir_na_arvore(arvore, 100, 0);
	inserir_na_arvore(arvore, 50, 0);
	inserir_na_arvore(arvore, 75, 0);
	inserir_na_arvore(arvore, 10, 0);
	inserir_na_arvore(arvore, 40, 0);
	inserir_na_arvore(arvore, 60, 0);
	inserir_na_arvore(arvore, 70, 0);
	inserir_na_arvore(arvore, 80, 0);
	inserir_na_arvore(arvore, 90, 0);
	inserir_na_arvore(arvore, 110, 0);
	inserir_na_arvore(arvore, 115, 0);
	inserir_na_arvore(arvore, 120, 0);
	inserir_na_arvore(arvore, 130, 0);
	inserir_na_arvore(arvore, 135, 0);
	inserir_na_arvore(arvore, 140, 0);
	inserir_na_arvore(arvore, 200, 0);
	inserir_na_arvore(arvore, 170, 0);
	inserir_na_arvore(arvore, 220, 0);
	inserir_na_arvore(arvore, 230, 0);
	inserir_na_arvore(arvore, 240, 0);
	inserir_na_arvore(arvore, 250, 0);


	imprime_intervalo(raiz, 2, 5);
	printf("\n");




	return 0;
}