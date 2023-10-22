#include <stdio.h>
#include "matriz.h"

int max_linha = 0;
int max_coluna = 0;
int tamanho = 0;

void dimensionar_matriz(int linha, int colunas) {
  max_linha = linha;
  max_coluna = colunas;
  tamanho = linha * colunas;
}

void inserir_elemento(int vet[], int num, int linha, int coluna) {
  linha = linha - 1;
  coluna = coluna - 1;
  int posicao = linha * max_coluna + coluna;
  vet[posicao] = num;
}

int buscar_elemento(int vet[], int linha, int coluna) {
  linha = linha - 1;
  coluna = coluna - 1;
  int posicao = linha * max_coluna + coluna;
  return vet[posicao];
}

void soma_matriz(int vet1[], int vet2[], int vet3[]) {
  for (int i = 1; i <= max_linha; i++) {
    for (int j = 1; j <= max_coluna; j++) {
      int val1 = buscar_elemento(vet1, i, j);
      int val2 = buscar_elemento(vet2, i, j);
      int soma = val1 + val2;
      inserir_elemento(vet3, soma, i, j);
    }
  }
}

void imprimir_matriz(int vet[]) {
  int l, c, num;
  for (l = 1; l <= max_linha; l++) {
    for (c = 1; c <= max_coluna; c++) {
      num = buscar_elemento(vet, l, c);
      printf("  %d", num);
    }
    printf("\n");
  }

  printf("\n");
}

void zerar_matriz(int vet[]) {
  int l, c;
  for (l = 1; l <= max_linha; l++) {
    for (c = 1; c <= max_coluna; c++) {
      inserir_elemento(vet, 0, l, c);
    }
  }
}

void imprimir_transposta(int vet[]) {
  int l, c, num;
  for (c = 1; c <= max_coluna; c++) {
    for (l = 1; l <= max_linha; l++) {
      num = buscar_elemento(vet, l, c);
      printf("  %d", num);
    }
    printf("\n");
  }
  
  printf("\n");
}

int matriz_identidade(int vet[], int n) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      int num = buscar_elemento(vet, i, j);

      if (i == j && num != 1) {
        printf("A matriz nao eh identidade.\n");
        return 0;
      }

      if (i != j && num != 0) {
        printf("A matriz nao eh identidade.\n");
        return 0;
      }
    }
  }

  return 1;
}

void multiplicar_matriz(int vet1[], int vet2[], int vet3[]) {
  for (int i = 1; i <= max_linha; i++) {
    for (int j = 1; j <= max_coluna; j++) {
      int produto = 0;
      for (int k = 1; k <= max_coluna; k++) {
        produto += buscar_elemento(vet1, i, k) * buscar_elemento(vet2, k, j);
      }
      inserir_elemento(vet3, produto, i, j);
    }
  }
}

int verificar_inversa(int vet1[], int vet2[]) {
  int vetProduto[tamanho];
  multiplicar_matriz(vet1, vet2, vetProduto);

  printf("Produto das matrizes:\n");
  imprimir_matriz(vetProduto);

  return matriz_identidade(vetProduto, max_linha);
}