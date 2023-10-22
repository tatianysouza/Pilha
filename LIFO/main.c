#include <stdio.h>
#include "pilha.h"
#include <conio.h>

void main() {
    Pilha* p = CriarPilha();
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);
    while (n != 0) {
        Push(p, n);
        printf("Informe outro numero: ");
        scanf("%d", &n);
    }
    printf("Os numeros informados foram: \n");
    while (!EstaVazia(p)) {
        n = Pop(p);
        printf("%d\n", n);
    }

    getch();
}