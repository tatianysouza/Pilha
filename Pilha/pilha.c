#include <stdio.h>
#include <string.h>
#include "pilha.h"

#define TAMANHO 100

int estaCheia(int topo){
  return topo == TAMANHO;
}

int estaVazia(int topo){
  return topo == 0;
}

char simbolo(char c){
  if (c == ')')
  {
    return '(';
  }
  else if (c == '}')
  {
    return '{';
  }
  else if (c == ']')
  {
    return '[';
  }
  else
  {
    return '\0';
  }
}

int verificar(char *pilha, char *expressao, int *topo){
  for (int i = 0; expressao[i] != '\0'; i++){
    if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '['){
      if (!estaCheia(*topo)){
        pilha[*topo] = expressao[i];
        (*topo)++;
      }
      else{
        return -1; // Erro: A pilha esta cheia.
      }
    }
    else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']'){
      if (!estaVazia(*topo)){
        char correspondente = simbolo(expressao[i]);
        if (pilha[*topo - 1] == correspondente)
        {
          (*topo)--;
        }
        else{
          return -2; // Erro: simbolos desbalanceados.
        }
      }
      else{
        return -2; // Erro: simbolos desbalanceados.
      }
    }
  }

  int resultado;
  if (estaVazia(*topo)){
    resultado = 0; // Símbolos balanceados
  }
  else{
    resultado = -2; // Erro: símbolos desbalanceados
  }

  return resultado;
}
