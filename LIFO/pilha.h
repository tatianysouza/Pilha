#ifndef PILHA_H
#define PILHA_H

typedef struct nodo Nodo;
typedef struct pilha Pilha;

Pilha* CriarPilha();
void Push(Pilha* p, int n);
int Pop(Pilha* p);
int EstaVazia(Pilha* p);

#endif
