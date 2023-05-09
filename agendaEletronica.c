#include <stdio.h>
#include <stdlib.h>

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

void iniciarAgenda(cadastro *LISTA);
cadastro *alocarCadastro();

int main() {
    cadastro *LISTA = (cadastro *) malloc(sizeof(cadastro)); // Aloca dinâmicamente a lista
    iniciarAgenda(LISTA); 

    int op; // Armazena a operação escolhida no menu
    do {        
        printf("1. Entrar um novo nome na agenda\n");
        printf("2. Consultar um nome na agenda\n");
        printf("3. Filtrar nomes por letra\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch(op) {
            case 1: {
                alocarCadastro; 
                break;
            }
            case 2: {} // Fazer a consulta de nomes na agenda
            case 3: {} // Fazer a busca de nomes por letra
            default: {} // Fazer a opção para a "nenhuma das acima"
        }

    } while(op != 0);

    return 0;
}

void iniciarAgenda(cadastro *LISTA) { // Inicializa a lista
    LISTA->prox = NULL;
    tam=0;
}

cadastro *alocarCadastro() { // Cadastra um novo nome na agenda
    cadastro *novo=(cadastro *) malloc(sizeof(cadastro)); 

    if(!novo) { // Checa se tem memória disponível para alocar
        printf("Sem memoria disponivel!\n");
        exit(1);
        
    } else { 
        printf("Novo cadastro\n");

        printf("Digite o nome de cadastro: ");
        fgets(novo->nome, 25, stdin);
        if (novo->nome[strlen(novo->nome) -1] == '\n') { novo->nome[strlen(novo->nome) - 1] = '\0'; }

        printf("Agora digite o numero: ");
        scanf("%d", &novo->numero);

        return novo;
    }
}