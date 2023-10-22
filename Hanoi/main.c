#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    char letra;
    struct nodo* proximo;
} Nodo;

typedef struct {
    Nodo* topo;
} Pilha;

Pilha* CriarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p, char l) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        exit(1);
    }
    novo->letra = l;
    novo->proximo = p->topo;
    p->topo = novo;
}

char pop(Pilha* p) {
    if (p->topo == NULL) {
        exit(1);
    }
    Nodo* aux = p->topo;
    char resultado = aux->letra;
    p->topo = aux->proximo;
    free(aux);
    return resultado;
}

int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

void torreHanoi(int n, Pilha* origem, Pilha* auxiliar, Pilha* destino) {
    if (n == 1) {
        char disco = pop(origem);
        push(destino, disco);
        return;
    }
    torreHanoi(n - 1, origem, destino, auxiliar);
    char disco = pop(origem);
    push(destino, disco);
    torreHanoi(n - 1, auxiliar, origem, destino);
}

void main() {
    Pilha* pilhaA = CriarPilha();
    Pilha* pilhaB = CriarPilha();
    Pilha* pilhaC = CriarPilha();

    char l;
    push(pilhaA, 'c');
    push(pilhaA, 'b');
    push(pilhaA, 'a');    

    torreHanoi(3, pilhaA, pilhaB, pilhaC);

    printf("\nAs letras na pilha A sao: \n");
    while (!estaVazia(pilhaA)) {
        l = pop(pilhaA);
        printf("%c\n", l);
    }

    printf("\nAs letras na pilha B sao: \n");
    while (!estaVazia(pilhaB)) {
        l = pop(pilhaB);
        printf("%c\n", l);
    }

    printf("\nAs letras na pilha C sao: \n");
    while (!estaVazia(pilhaC)) {
        l = pop(pilhaC);
        printf("%c\n", l);
    }
}

