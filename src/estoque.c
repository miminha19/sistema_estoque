#include <stdio.h>
#include <string.h>
#include "estoque.h"

#define ARQUIVO "estoque.txt"

void adicionar_item(char nome[], int quantidade) {
    FILE *f = fopen(ARQUIVO, "a");
    fprintf(f, "%s %d\n", nome, quantidade);
    fclose(f);
}

void listar_estoque() {
    FILE *f = fopen(ARQUIVO, "r");
    char nome[50];
    int qtd;

    printf("\n--- ESTOQUE ---\n");

    while (fscanf(f, "%s %d", nome, &qtd) != EOF) {
        printf("Item: %s | Quantidade: %d\n", nome, qtd);
    }

    fclose(f);
}

void buscar_item(char nome_busca[]) {
    FILE *f = fopen(ARQUIVO, "r");
    char nome[50];
    int qtd;
    int encontrado = 0;

    while (fscanf(f, "%s %d", nome, &qtd) != EOF) {
        if (strcmp(nome, nome_busca) == 0) {
            printf("Encontrado: %s | Quantidade: %d\n", nome, qtd);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n");
    }

    fclose(f);
}

void remover_item(char nome_busca[], int quantidade) {
    FILE *f = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");

    char nome[50];
    int qtd;

    while (fscanf(f, "%s %d", nome, &qtd) != EOF) {
        if (strcmp(nome, nome_busca) == 0) {
            qtd -= quantidade;
            if (qtd < 0) qtd = 0;
        }
        fprintf(temp, "%s %d\n", nome, qtd);
    }

    fclose(f);
    fclose(temp);

    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);
}