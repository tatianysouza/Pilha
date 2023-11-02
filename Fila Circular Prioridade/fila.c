#include <stdio.h>
#include "fila.h"
int max = 5;
typedef struct nodo
{
    int prio;
    int valor;
} Nodo;

typedef struct fila
{
    int inicio;
    int fim;
    Nodo fila[5];
    int qtdd;
} Fila;

void inicializar(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->qtdd = 0;
}

int circularCheia(Fila *f)
{
    return (f->qtdd == max);
}

int circularVazia(Fila *f)
{
    return (f->qtdd == 0);
}

void enfileirarComPrioridade(Fila *f, int prio)
{
    if (circularCheia(f))
    {
        printf("Fila cheia\n");
    }
    else
    {
        int valor = f->qtdd + 1;

        int i = f->inicio;
        while (i != f->fim && f->fila[i].prio <= prio)
        {
            i = (i + 1) % max;
        }

        if (i == f->fim)
        {
            f->fila[f->fim].prio = prio;
            f->fila[f->fim].valor = valor;
        }
        else
        {
            for (int j = f->fim; j != i; j = (j - 1 + max) % max)
            {
                f->fila[j] = f->fila[(j - 1 + max) % max];
            }
            f->fila[i].prio = prio;
            f->fila[i].valor = valor;
        }

        f->fim = (f->fim + 1) % max;
        f->qtdd++;
        printf("Inserido com sucesso\n");
    }
}

void desenfileirar(Fila *f)
{
    if (circularVazia(f))
    {
        printf("Fila vazia\n");
    }
    else
    {
        f->inicio = (f->inicio + 1) % max;
        f->qtdd--;
        printf("Removido com sucesso\n");
    }
}

void imprimir(Fila *f)
{
    if (circularVazia(f))
    {
        printf("Fila vazia\n");
    }
    else
    {
        int i = f->inicio;
        int elementos_impressos = 0;

        while (elementos_impressos < f->qtdd)
        {
            printf("%d\n", f->fila[i].prio);
            i = (i + 1) % max;
            elementos_impressos++;
        }
    }
}
