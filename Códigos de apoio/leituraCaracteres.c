#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char C;
    fflush(stdin); //limpa o buffer do teclado

    printf("Digite o caracter: ");
    C = getchar(); // leitura do caratcter

    printf("Caracter: %c\n", C);

    return 0;
}