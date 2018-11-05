#include <stdlib.h>
#include <stdio.h>
#include "Solver.h"
#include "Jogo.h"
#include "ListaInt.h"

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista, ListaInt **listaTravados)
{
	if (ManhattanDistance(mat) == 0)
		return 1;

	int i = 1;
	while (distanciaDaPeca(mat, i) == 0)
	{
		if (isValorContidoNaLista(*listaTravados, i) == 0)
			insertInt(listaTravados, i);
		i++;
	}

	movimento *opcoes = malloc(4 * sizeof(movimento));
	if (SeMatrizContidaNaListaRetornaZero(mat, *lista) == -1)
		insert(lista, mat);

	for (i = 0; i < 4; i++)
	{
		opcoes[i].dir = i;
		if (MovePecaNaMatriz(mat, i) == 0)
		{
			if (SeMatrizContidaNaListaRetornaZero(mat, *lista) == 0)
				opcoes[i].Manhattan = -1;
			else
				opcoes[i].Manhattan = ManhattanDistance(mat);

			DesfazMovePecaNaMatriz(mat, opcoes[i].dir);
		}
		else
			opcoes[i].Manhattan = -1;
	}

	selectSortManhattan(opcoes, 4);
	for (i = 0; i < 4; i++)
	{
		if (opcoes[i].Manhattan != -1)
		{
			MovePecaNaMatriz(mat, opcoes[i].dir);
			/*printMatriz(mat);*/
			if (melhorCaminho(mat, lista, listaTravados) == 1)
				return 1;

			/*removeMatrizDaLista(lista, mat);*/
			DesfazMovePecaNaMatriz(mat, opcoes[i].dir);
		}
	}

	free(opcoes);
	return 0;
}

void printMatriz(int mat[4][4]) 
{

	printf("\n[");
	for (int i = 0; i < 4; i++)
	{
		printf(" [");
		for (int j = 0; j < 4; j++)
		{
			printf("%i, ", mat[i][j]);
		}
		printf("], ");
	}
	printf("]");
}

int ManhattanDistance(int mat[4][4])
{
	int somaDist = 0;
	int valor = 1;

	while (valor < 16)
	{
		somaDist += distanciaDaPeca(mat, valor++);
	}
	return somaDist;
}

int distanciaDaPeca(int mat[4][4], int valor)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (mat[i][j] == valor)
				return abs(i - ((valor - 1) / 4)) + abs(j - ((valor - 1) % 4));

	return 0;
}

void selectSortManhattan(movimento vetor[], int size)
{
	if (size <= 1)
		return;

	int posMenor = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[posMenor].Manhattan > vetor[i].Manhattan)
			posMenor = i;
	}

	//swap(&(vetor[posMenor]), &(vetor[0]));
	movimento aux = vetor[posMenor];
	vetor[posMenor] = vetor[0];
	vetor[0] = aux;
	selectSortManhattan(&(vetor[1]), size - 1);

	return;
}

void swap(movimento *a, movimento *b)
{
	movimento aux = *a;
	*a = *b;
	*b = aux;

	return;
}