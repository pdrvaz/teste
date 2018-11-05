#include "ListaInt.h"
#include <stdlib.h>

int insertInt(ListaInt **lista, int valor)
{
	ListaInt *novo = malloc(sizeof(ListaInt));
	novo->proximo = NULL;
	novo->valor = valor;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaInt *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;

	iterador->proximo = novo;

	return 0;
}

int isValorContidoNaLista(ListaInt *lista,int valor)
{
	if (lista == NULL)
		return 0;

	int igual = -1;
	while (lista != NULL && igual == -1)
	{
		igual = 0;

		if (valor != lista->valor)
			igual = -1;

		lista = lista->proximo;
	}
	return igual;
}