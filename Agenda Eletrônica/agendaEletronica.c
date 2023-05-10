#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct agendaEletronica {
    char nome[25];
    int numero;
    struct Nodo *prox;
};

int tam; // Tamanho da lista
typedef struct agendaEletronica cadastro; // Tipo de dado

int vazia(cadastro *LISTA);
void iniciarAgenda(cadastro *LISTA);
cadastro *alocarCadastro();
void inserirCadastro(cadastro *LISTA);
void consultarNomes(cadastro *LISTA);
void consultarLetra(cadastro *LISTA);

int main() {
    cadastro *LISTA = (cadastro *) malloc(sizeof(cadastro)); // Aloca dinâmicamente a lista
    iniciarAgenda(LISTA); // Inicializa a lista

    int op; // Armazena a operação escolhida no menu
    do {        
        printf("1. Entrar um novo nome na agenda\n2. Consultar um nome na agenda\n3. Filtrar nomes por letra\n0. Sair\nOpcao: "); // Menu
        scanf("%d", &op);

        switch(op) {
            case 1: { // Inserir novo cadastro na agenda
                inserirCadastro(LISTA);
                break;
            }
            case 2: { // Fazer a consulta de nomes na agenda
                consultarNomes(LISTA);
                break;
            } 
            case 3: { // Fazer a busca de nomes por letra
                consultarLetra(LISTA);
                break;
            }
            case 0: {
                system("CLS");
                printf("Fim do programa\n");
                break;
            } 
            default: {
                system("CLS");
                printf("Operacao invalida\n\n");                
            }
        }

    } while(op != 0);
    return 0;
}

int vazia(cadastro *LISTA) { // Confere se a lista esta vazia
    if (LISTA->prox == NULL) 
        return 1;
    else
        return 0;
}

void iniciarAgenda(cadastro *LISTA) { // Inicializa a lista
    LISTA->prox = NULL;
    tam=0;
}

cadastro *alocarCadastro() {  // Cadastra um novo nome na agenda
    system("CLS");

    cadastro *novo = (cadastro *) malloc(sizeof(cadastro)); 
    printf("Novo cadastro\n\n");

    fflush(stdin);
    printf("Digite o nome de cadastro: ");
    fgets(novo->nome, 25, stdin);
    if (novo->nome[strlen(novo->nome) -1] == '\n') { novo->nome[strlen(novo->nome) - 1] = '\0'; }

    printf("Agora digite o numero: ");
    scanf("%d", &novo->numero);

    system("CLS");
    printf("Cadastro alocado\n\n");
    return novo;    
}

void inserirCadastro(cadastro *LISTA) { // Insere um novo cadastro na agenda
    cadastro *novo = alocarCadastro();
    novo->prox = NULL;
 
    if (vazia(LISTA)) // Confere se a lista esta vazia
        LISTA->prox = novo;        
    else {
        cadastro *tmp = LISTA->prox;

        while(tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void consultarNomes(cadastro *LISTA) { // Consulta um nome na agenda
    system("CLS");

    if (vazia(LISTA)) // Confere se a lista esta vazia
        printf("Lista vazia!\n\n");
    else {        
        cadastro *tmp;
        char nome[25];   
        tmp = LISTA->prox;

        fflush(stdin); // Limpa o buffer do teclado
        printf("Digite o nome que deseja buscar: ");

        fgets(nome, 25, stdin);
        if (nome[strlen(nome) -1] == '\n') { nome[strlen(nome) - 1] = '\0'; }

        int flag = 0; // Confere se foi encontrado algum nome na busca
        while(tmp != NULL) {
            if (strcmp(nome, tmp->nome) == 0) { // Faz uma busca nos nomes da lista
                printf("%s - %d\n", tmp->nome, tmp->numero);
                flag = 1;
            }
            tmp = tmp->prox;
            printf("\n");
        }
        if(flag == 0) { printf("Nome nao encontrado\n"); }
    } 
}

void consultarLetra(cadastro *LISTA) { // Consulta todos os nomes que comecem com um caracter
    system("CLS");

    if (vazia(LISTA)) // Confere se a lista esta vazia
            printf("Lista vazia!\n\n");
    else {
        char c;
        cadastro *tmp;
        tmp = LISTA->prox;

        fflush(stdin); // Limpa o buffer do teclado
        printf("Digite a letra que deseja consultar: ");
        c = getchar(); // Armazena o caracter digitado

        c = toupper(c); // Faz o caracter ficar maiúsculo 
        int flag = 0; // Confere se foi encontrado algum nome na busca

            while(tmp != NULL) {
                if(c == toupper(tmp->nome[0])) { // Faz uma busca nos nomes da lista
                    printf("%s - %d\n", tmp->nome, tmp->numero);
                    flag = 1;
                }
                tmp = tmp->prox;
                printf("\n");
            }
        if(flag == 0) { printf("Nenhum resultado\n"); }
    }

}