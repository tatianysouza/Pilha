#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Global;

void adicionarLinha(FILE *csvFile, const char *nome, int idade, const char *cidade) {
  fprintf(csvFile, "%s,%d,%s\n", nome, idade, cidade);
}

void pesquisarPorNome(FILE *csvFile, const char *nome) {
  char linha[256];
  fseek(csvFile, 0, SEEK_SET); // Volta para o início do arquivo

  while (fgets(linha, sizeof(linha), csvFile)) {
    if (strstr(linha, nome)) {
      printf("Linha encontrada: %s", linha);
      return;
    }
  }
  printf("Linha não encontrada\n");
}

void removerLinha(FILE *csvFile, const char *nome) {
  FILE *tempFile = tmpfile();
  char linha[256];
  fseek(csvFile, 0, SEEK_SET);

  while (fgets(linha, sizeof(linha), csvFile)) {
    if (!strstr(linha, nome)) {
      fputs(linha, tempFile);
    }
  }

  // Fecha o arquivo original antes de truncar
  fclose(csvFile);
  csvFile = fopen("arquivo.csv", "w+"); // Reabre no modo escrita

  fseek(tempFile, 0, SEEK_SET);

  while (fgets(linha, sizeof(linha), tempFile)) {
    fputs(linha, csvFile);
  }

  fclose(tempFile);
  printf("\nDados de %s excluídos com sucesso\n", nome);
}

int Usuario() {
  printf("\n1. Adicionar linha\n");
  printf("2. Pesquisar por nome\n");
  printf("3. Remover linha\n");
  printf("4. Sair\n");
  printf("Escolha uma opção: ");
  int opcao;
  scanf("%d", &opcao);
  return opcao;
}

int main() {
  const char *filename = "arquivo.csv";
  FILE *csvFile = fopen(filename, "w+");

  fprintf(csvFile, "Nome,Idade,Cidade\n");
  Global = Usuario();
  char nome[50], cidade[20];
  int idade;

  while (Global != 4) {
    if (Global == 1) {
      printf("\nDigite o nome: ");
      scanf(" %[^\n]s", nome);
      printf("Digite a idade: ");
      scanf("%d", &idade);
      printf("Digite a cidade: ");
      scanf(" %[^\n]s", cidade);
      adicionarLinha(csvFile, nome, idade, cidade);
      Global = Usuario();
    } 
    else if (Global == 2) {
      fseek(csvFile, 0, SEEK_SET);
      printf("Digite o nome para pesquisa: ");
      scanf(" %[^\n]s", nome);
      pesquisarPorNome(csvFile, nome);
      Global = Usuario();
    } 
    else if (Global == 3) {
      printf("Digite o nome para remoção: ");
      scanf(" %[^\n]s", nome);
      removerLinha(csvFile, nome);
      Global = Usuario();
    } 
    else {
      printf("Opção inválida.\n");
    }
  }
fclose(csvFile);
}