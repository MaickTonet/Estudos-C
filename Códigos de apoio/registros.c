#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro { //Declara um registro, contendo três dados
    int codigo;
    char nome[30];
    float preco;
};

int main() {
    struct registro produto; //Inicializa o registro na função main

    printf("Digite o codigo do produto: ");
    scanf("%d", &produto.codigo); //Armazena a leitura do código no registro

    fflush(stdin); //Limpa o buffer do teclado

    printf("Digite o nome do produto: ");
    fgets(produto.nome, 30, stdin); //Armazena a leitura do nome no registro
    if (produto.nome[strlen(produto.nome) - 1] == '\n') { produto.nome[strlen(produto.nome) - 1] = '\0'; } //Remove o "enter" no final da string

    printf("Digite o preco do produto: ");
    scanf("%f", &produto.preco); //Armazena a leitura do preço no registro

    return 0;
}