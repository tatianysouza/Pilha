#include <stdlib.h>
#include "pilha.h"

struct nodo {
    int numero;
    Nodo* proximo;
};

struct pilha {
    Nodo* topo;
};

Pilha* CriarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void Push(Pilha* p, int n) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->numero = n;
    novo->proximo = p->topo;
    p->topo = novo;
}

int Pop(Pilha* p) {
    if (EstaVazia(p)) {
        return -1;
    }
    Nodo* aux = p->topo;
    int resultado = aux->numero;
    p->topo = aux->proximo;
    free(aux);
    return resultado;
}

int EstaVazia(Pilha* p) {
    return (p->topo == NULL);
}
