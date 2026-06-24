#include <stdio.h>
#include "estoque.h"

int main() {
    int opcao;
    char nome[50];
    int qtd;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Ver estoque\n");
        printf("2 - Adicionar item\n");
        printf("3 - Remover item\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listar_estoque();
                break;

            case 2:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Quantidade: ");
                scanf("%d", &qtd);
                adicionar_item(nome, qtd);
                break;

            case 3:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Quantidade: ");
                scanf("%d", &qtd);
                remover_item(nome, qtd);
                break;

            case 4:
                printf("Nome: ");
                scanf("%s", nome);
                buscar_item(nome);
                break;
        }

    } while(opcao != 0);

    return 0;
}