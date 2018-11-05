#pragma once

typedef struct ListaInt
{
	int valor;
	struct ListaInt *proximo;

} ListaInt;

int insertInt(ListaInt **lista, int valor);
int isValorContidoNaLista(ListaInt *lista, int valor);