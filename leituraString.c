#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char str[25];

    printf("Digite uma frase: ");
    fgets(str, 50, stdin); //Faz a leitura da string, delimitando o tamanho e selecionando a forma de leitura (teclado)

    if (str[strlen(str) -1] == '\n') { str[strlen(str) - 1] = '\0'; } //remove o "enter" no final da string
    printf("String: %s\n", str);

    return 0;
}