#pragma once

int preencheMatriz(int mat[4][4]);
int shuffleArray(int *array, int size);
int inversion_Parity(int *vetor, int tamanho);
int validaJogo(int mat[4][4], int *array);
void ImprimeJogo(int mat[4][4]);
int MovePecaNaMatriz(int mat[4][4], int dir);
void DesfazMovePecaNaMatriz(int mat[4][4], int dir);