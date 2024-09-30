struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
};
struct Livro biblioteca[100];
int num_livros = 0;
#include <stdio.h>
#include <string.h>

// Estrutura do livro
struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
};

// Vetor de livros
struct Livro biblioteca[100];
int num_livros = 0;

// Função para adicionar um livro
void adicionarLivro() {
    struct Livro livro;
    printf("Digite o título do livro: ");
    fgets(livro.titulo, 100, stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = 0; // Remover o '\n'

    printf("Digite o autor do livro: ");
    fgets(livro.autor, 50, stdin);
    livro.autor[strcspn(livro.autor, "\n")] = 0;

    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.ano_publicacao);

    biblioteca[num_livros] = livro;
    num_livros++;
}

// Função para buscar um livro por título
void buscarLivro() {
    char titulo[100];
    printf("Digite o título do livro para buscar: ");
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = 0;

    int i;
    for (i = 0; i < num_livros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de publicação: %d\n", biblioteca[i].ano_publicacao);
            return;
        }
    }
    printf("Livro não encontrado.\n");
}

// Função para listar todos os livros
void listarLivros() {
    for (int i = 0; i < num_livros; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Ano de publicação: %d\n", biblioteca[i].ano_publicacao);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro\n");
        printf("3. Listar livros\n");
        printf("4. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro();
                break;
            case 2:
                buscarLivro();
                break;
            case 3:
                listarLivros();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
