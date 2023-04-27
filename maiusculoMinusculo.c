#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main() {

    char C;
    
    fflush(stdin); //limpa o buffer do teclado

    printf("Digite um caracter: ");
    C = getchar(); //faz a leitura do caracter

    printf("Maiusculo: %c\n", toupper(C));
    printf("Minusculo: %c\n", tolower(C));

    return 0;
}