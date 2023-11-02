#ifndef FILA_H
#define FILA_H

typedef struct nodo Nodo;
typedef struct fila Fila;
void inicializar(Fila *f);
int circularCheia(Fila *f);
int circularVazia(Fila *f);
void enfileirarComPrioridade(Fila *f, int prio);
void desenfileirar(Fila *f);
void imprimir(Fila *f);

#endif