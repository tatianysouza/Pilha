#ifndef MATRIZ_H
#define MAREIZ_H

void dimensionar_matriz(int linha, int colunas);
void inserir_elemento(int vet[], int num, int linha, int coluna);
int buscar_elemento(int vet[], int linha, int coluna);
void soma_matriz(int vet1[], int vet2[], int vet3[]);
void imprimir_matriz(int vet[]);
void zerar_matriz(int vet[]);
void imprimir_transposta(int vet[]);
int matriz_identidade(int vet[], int n);
void multiplicar_matriz(int vet1[], int vet2[], int vet3[]);
int verificar_inversa(int vet1[], int vet2[]);
#endif