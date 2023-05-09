#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Construir um programa em "C" que implementa uma agenda eletrônica. 
    O programa deve ter um menu com as seguintes opções:
    1 - Entrar um nome na agenda
    2 - Imprimir na tela os dados de uma das pessoas cadastradas (consulta por nome)
    3 - Imprimir na impressora a lista dos nomes que começam pela letra indicada    */

struct agendaEletronica { // Agenda Eletrônica que cadastra novos nomes
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

int main() {
    system("CLS");
    cadastro *LISTA = (cadastro *) malloc(sizeof(cadastro)); // Aloca dinâmicamente a lista
    iniciarAgenda(LISTA); 

    int op; // Armazena a operação escolhida no menu
    do {        
        printf("1. Entrar um novo nome na agenda\n");
        printf("2. Consultar um nome na agenda\n");
        printf("3. Filtrar nomes por letra\n");
        printf("0. Sair\n");
        printf("Opcao: ");
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
            case 3: {} // Fazer a busca de nomes por letra
            default: {} // Fazer a opção para a "nenhuma das acima"
        }

    } while(op != 0);

    return 0;
}

int vazia(cadastro *LISTA) { // Confere se a lista esta vazia
    if(LISTA->prox == NULL)
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
    cadastro *novo=(cadastro *) malloc(sizeof(cadastro)); 
    printf("Novo cadastro\n");

    fflush(stdin);
    printf("Digite o nome de cadastro: ");
    fgets(novo->nome, 25, stdin);
    if (novo->nome[strlen(novo->nome) -1] == '\n') { novo->nome[strlen(novo->nome) - 1] = '\0'; }

    printf("Agora digite o numero: ");
    scanf("%d", &novo->numero);

    printf("\n");
    return novo;    
}

void inserirCadastro(cadastro *LISTA) { // Insere um novo cadastro na agenda
    cadastro *novo = alocarCadastro();
    novo->prox = NULL;
 
    if(vazia(LISTA))
        LISTA->prox=novo;
    else{
        cadastro *tmp = LISTA->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
    tam++;
}

void consultarNomes(cadastro *LISTA) { // Consulta um nome na agenda
    system("CLS");
    char nome[25];

    fflush(stdin);
    printf("Digite o nome que deseja buscar: ");

    fgets(nome, 25, stdin);
    if (nome[strlen(nome) -1] == '\n') { nome[strlen(nome) - 1] = '\0'; }

    if(vazia(LISTA)) {
        printf("Lista vazia!\n");
    } else {        
        cadastro *tmp;
        tmp = LISTA->prox;

        int flag = 0;
        while(tmp != NULL) {
            if (strcmp(nome, tmp->nome) == 0) {
                printf("%s - %d\n", tmp->nome, tmp->numero);
                flag = 1;
            }
            tmp = tmp->prox;
        }

        if(flag == 0) { printf("Nome nao encontrado\n"); }
    } 
    system("pause");
}
