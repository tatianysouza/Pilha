#include <stdio.h>
#include <conio.h>
#include "matriz.h"

void main() {
    // matriz 3 por 2
    int vet1[3*2] = {1, 2, 3, 4, 5, 6};
    imprimir(vet1, 3, 2);
    // matriz 2 por 3
    int vet2[2*3] = {1, 4, 3, 2, 1, 2};
    imprimir(vet2, 2, 3);
    produto_Matriz(vet1, vet2, 3, 3) ;
    getch();
    }