#include <stdio.h>
#include <string.h>

#define MAX_ITENS 50
#define TAM_STRING 50

// Estrutura para armazenar os dados de cada item
struct Item {
    char nome[TAM_STRING];
    char tipo[TAM_STRING];
    int quantidade;
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar os itens
int cadastrarItens(struct Item mochila[]) {
    int n;
    printf("Quantos itens deseja cadastrar (máx %d)? ", MAX_ITENS);
    scanf("%d", &n);
    limparBuffer();

    for (int i = 0; i < n; i++) {
        printf("\n--- Item %d ---\n", i + 1);

        printf("Nome: ");
        fgets(mochila[i].nome, TAM_STRING, stdin);
        mochila[i].nome[strcspn(mochila[i].nome, "\n")] = '\0'; // remove o \n

        printf("Tipo: ");
        fgets(mochila[i].tipo, TAM_STRING, stdin);
        mochila[i].tipo[strcspn(mochila[i].tipo, "\n")] = '\0';

        printf("Quantidade: ");
        scanf("%d", &mochila[i].quantidade);
        limparBuffer();
    }

    return n;
}

// Função para exibir todos os itens
void exibirItens(struct Item mochila[], int n) {
    printf("\n--- Itens na mochila ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função de busca sequencial por nome
void buscarItemPorNome(struct Item mochila[], int n, char nomeBuscado[]) {
    int encontrado = 0; // flag que indica se o item foi achado

    for (int i = 0; i < n; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            printf("\n Item encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break; // interrompe o loop, pois o item já foi encontrado
        }
    }

    if (!encontrado) {
        printf("\n Item '%s' não encontrado na mochila.\n", nomeBuscado);
    }
}

// Função principal
int main() {
    struct Item mochila[MAX_ITENS];
    int n, opcao;
    char nomeBusca[TAM_STRING];

    n = cadastrarItens(mochila);

    do {
        printf("\n=== MENU ===\n");
        printf("1. Exibir Itens\n");
        printf("2. Buscar Item por Nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                exibirItens(mochila, n);
                break;

            case 2:
                printf("\nDigite o nome do item que deseja buscar: ");
                fgets(nomeBusca, TAM_STRING, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarItemPorNome(mochila, n, nomeBusca);
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
