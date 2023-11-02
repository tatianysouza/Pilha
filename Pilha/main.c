#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include <conio.h>
#define TAMANHO 100

void main(){
    char expressao[TAMANHO];
    printf("Digite a expressao pra verificar: ");
    scanf("%s", expressao);

    char pilha[TAMANHO];
    int topo = 0;

    int resultado = verificar(pilha, expressao, &topo);
    if(resultado == 0){
        printf("Simbolos balanceados\n");
    }else if(resultado == -1){
        printf("Erro: A pilha esta cheia.\n");
    }else{
        printf("Erro: simbolos desbalanceados.\n");
    }
    getch();
}
