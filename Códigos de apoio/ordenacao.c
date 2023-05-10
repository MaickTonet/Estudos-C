#include <stdio.h>

int main() {

    int a, b, c;

    printf("Digite os tres valores: ");
    scanf("%d%d%d", &a, &b, &c); //Faz a leitura dos três valores inteiros

    int aux; //Declara uma variável auxiliar que trocara os valores;

    if (a < b) {
        aux = a;
        a = b;
        b = aux;

    } else if (a < c) {
        aux = a;
        a = c;
        c = aux;

    } else if (b < c) {
        aux = b;
        b = c;
        c = aux;

    }

    printf("Valores ordenados: %d - %d - %d\n", a, b, c);

    return 0;
}