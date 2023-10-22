#include <stdio.h>
#include "matriz.h"

int buscar_elemento_vet1(int vet[], int linha, int coluna) {
    //usuário não considera o 0!
    linha = linha - 1;
    coluna = coluna -1;
    //formula: posicao =  linha * n + coluna
    int posicao = linha * 2 +coluna;
    return vet[posicao];
}

int buscar_elemento_vet2(int vet[], int linha, int coluna) {
    //usuário não considera o 0!
    linha = linha - 1;
    coluna = coluna -1;
    //formula: posicao =  linha * n + coluna
    int posicao = linha* 3 +coluna;
    return vet[posicao];
}

void zerar_matriz(int vet[]) {
    int l;
    for (l=0;l<6;l++){
        vet[l] = 0;
    }
}

void produto_Matriz(int vet1[], int vet2[], int m, int n){
    printf("Produto \n");
    // 3x2   *   2x3
    int l,c;

    for (l=1;l<=n;l++) {
        for (c=1; c<=m; c++)
        {
            int produto = 
            buscar_elemento_vet1(vet1, l,1 ) * buscar_elemento_vet2(vet2, 1,c) 
            + 
            buscar_elemento_vet1(vet1, l,2 ) * buscar_elemento_vet2(vet2, 2,c);
            +
            buscar_elemento_vet1(vet1, l,3 ) * buscar_elemento_vet2(vet2, 3, c);
            printf(" %d ", produto );
        }
        printf("\n");
        
    }
    printf("\n");

}

void imprimir(int vet1[],int max_linha,int max_coluna) {
    printf("Matriz:  %d x %d \n", max_linha, max_coluna);
    int l,c;
    for (l=0;l<max_linha;l++) {
        for (c=0;c<max_coluna;c++) {
            printf(" %d ", vet1[l* max_coluna +c]);
        }
        printf("\n");
    }
    printf("\n");
}