#include <stdio.h>
#include "matriz.h"
#include <conio.h>

void main() {
  int tamanho =0;
  dimensionar_matriz(2, 2);

  int vet1[tamanho];
  int vet2[tamanho];
  int vet3[tamanho];

  zerar_matriz(vet1);
  zerar_matriz(vet2);
  zerar_matriz(vet3);


  inserir_elemento(vet1, 2, 1, 1);
  inserir_elemento(vet1, 1, 1, 2);
  inserir_elemento(vet1, 7, 2, 1);
  inserir_elemento(vet1, 4, 2, 2);
    
  inserir_elemento(vet2, 4, 1, 1); 
  inserir_elemento(vet2, -1, 1, 2);
  inserir_elemento(vet2, -7, 2, 1); 
  inserir_elemento(vet2, 2, 2, 2);

  printf("Matriz 1:\n");
  imprimir_matriz(vet1);
  printf("\n");

  printf("Matriz 2:\n");
  imprimir_matriz(vet2);
  printf("\n");

  // Calcular e imprimir a soma das matrizes
  soma_matriz(vet1, vet2, vet3);
  printf("Soma das matrizes:\n");
  imprimir_matriz(vet3);
  printf("\n");
  
  printf("Matriz transposta:\n");
  imprimir_transposta(vet3);
  printf("\n");

  int resultado = verificar_inversa(vet1, vet2);

  if (resultado == 1)
    printf("A matriz B eh a inversa da matriz A.\n");
  else
    printf("A matriz B nao eh a inversa da matriz A.\n");
  printf("\n");
  getch();
}
