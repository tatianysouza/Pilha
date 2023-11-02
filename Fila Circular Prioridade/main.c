#include <stdio.h>
#include "fila.h"
#include <conio.h>

void main(){
    Fila *f;
    inicializar(&f);

    enfileirarComPrioridade(&f, 1);
    enfileirarComPrioridade(&f, 2);
    enfileirarComPrioridade(&f, 3);
    enfileirarComPrioridade(&f, 1);

    imprimir(&f);

    desenfileirar(&f);
    imprimir(&f);

    getch();
}