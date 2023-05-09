#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;  
    struct Nodo *prox; 
}; 
typedef struct Nodo nodo; 
int tam; 

void inicia(nodo *LISTA); 
int vazia(nodo *LISTA);
nodo *aloca();
void insereInicio(nodo *LISTA);
void insereFim(nodo *LISTA);
void insere(nodo *LISTA);
void exibe(nodo *LISTA);
void mostra(nodo *LISTA);
nodo *retira(nodo *LISTA);
nodo *retiraInicio(nodo *LISTA);
nodo *retiraFim(nodo *LISTA);
void libera(nodo *LISTA);

int main(){
  
    nodo *LISTA = (nodo *) malloc(sizeof(nodo));
    if(!LISTA){  
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        inicia(LISTA);
    }

    int op; 
    do{
        printf("Escolha a opcao\n");        
        printf("1. Zerar lista\n");
        printf("2. Exibir lista\n");
        printf("3. Adicionar nodo no inicio\n");
        printf("4. Adicionar nodo no final\n");
        printf("5. Escolher onde inserir\n");
        printf("6. Retirar do inicio\n");
        printf("7. Retirar do fim\n");
        printf("8. Escolher de onde tirar\n");
        printf("9. Mostrar uma determinada posicao\n");
        printf("0. Sair\n");
        printf("Opcao: "); 
        scanf("%d", &op);
        nodo *tmp;
        switch(op){
        case 0: 
            libera(LISTA);
            break;
        case 1:
            libera(LISTA);
            inicia(LISTA);
            break;
        case 2:
            exibe(LISTA);
            break;
        case 3:
            insereInicio(LISTA);
            break;  
        case 4:
            insereFim(LISTA);
            break; 
        case 5:
            insere(LISTA);
            break;  
        case 6:
            tmp= retiraInicio(LISTA);
            printf("Retirado: %3d\n\n", tmp->info);
            break;
        case 7:
            tmp= retiraFim(LISTA);
            printf("Retirado: %3d\n\n", tmp->info);
            break;
        case 8:
            tmp= retira(LISTA);
            printf("Retirado: %3d\n\n", tmp->info);
            break;
        case 9:
            printf("Mostra uma posicao.\n");
            mostra(LISTA);
            break;
        default:
            printf("Opcao invalida\n\n");
        }      
        
    }while(op!=0); 
    return 0;   
}

// função para iniciar a lista
void inicia(nodo *LISTA){
    LISTA->prox = NULL;
    tam=0;
}

// função para verificar se a lista está vazia
int vazia(nodo *LISTA){
    if(LISTA->prox == NULL)
        return 1;
    else
        return 0;
}

// função para alocar nodos
nodo *aloca(){
    nodo *novo=(nodo *) malloc(sizeof(nodo)); 
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        printf("Novo elemento: "); scanf("%d", &novo->info); 
    return novo;
    }
}

//função para inserir um nodo no início
void insereInicio(nodo *LISTA){   
 nodo *novo=aloca(); 
 novo-> prox = LISTA-> prox; 
 LISTA-> prox = novo; 
 tam++; 
}

// função para inserir no final da lista
void insereFim(nodo *LISTA){
    nodo *novo=aloca();
    novo->prox = NULL;
 
    if(vazia(LISTA))
        LISTA->prox=novo;
    else{
        nodo *tmp = LISTA->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
    tam++;
}

// função para inserir em qualquer posição da lista existente
void insere(nodo *LISTA){
    int pos, cont;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);
 
    if((pos>0) && (pos <= tam)){
        if(pos==1){ 
            insereInicio(LISTA);
        }else{ 
            nodo *atual = LISTA->prox; 
            nodo *anterior = LISTA; 
            nodo *novo=aloca(); 
            for(cont=1 ; cont < pos ; cont++){ 
                anterior=atual;
                atual=atual->prox;
            }
            anterior->prox=novo;  
            novo->prox = atual;   
            tam++; 
        }
    } else {
         printf("Posição invalida\n\n");
    }
}

// função para mostrar a lista
void exibe(nodo *LISTA){
    system("CLS");
    if(vazia(LISTA)){
        printf("Lista vazia!\n\n");
    }else {
        nodo *tmp;
        tmp = LISTA->prox;
        printf("Lista:");
        while( tmp != NULL){
            printf("%5d", tmp->info);
            tmp = tmp->prox;
        }
        printf("\n        ");
        int cont;
        for(cont=0 ; cont < tam ; cont++)
            printf("  ^  ");
        printf("\nOrdem:");
        for(cont=0 ; cont < tam ; cont++)
            printf("%5d", cont+1);
     printf("\n\n");
    } 
}

// função para remover nodo do início da lista
nodo *retiraInicio(nodo *LISTA){
    if(LISTA->prox == NULL){
        printf("Lista ja esta vazia\n");
        return NULL;
    }else{
        nodo *tmp = LISTA->prox;
        LISTA->prox = tmp->prox;
        tam--;
        return tmp;
    }   
}

// função para retirar nodos do final da lista
nodo *retiraFim(nodo *LISTA){
    if(LISTA->prox == NULL){
        printf("Lista ja vazia\n\n");
        return NULL;
    }else{
        nodo *ultimo = LISTA->prox,*penultimo = LISTA;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        tam--;
        return ultimo;  
    }
}

// função para retirar nodos de qualquer posição existente
nodo *retira(nodo *LISTA){
    int op, cont;
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &op);
 
    if((op>0) && (op <= tam)){
        if(op==1){
            return retiraInicio(LISTA);
        }else{
            nodo *atual = LISTA->prox,
            *anterior=LISTA; 
            for(cont=1 ; cont < op ; cont++){
                anterior=atual;
                atual=atual->prox;
            }
            anterior->prox=atual->prox;
            tam--;
            return atual;
        }   
    }else{
        printf("Elemento invalido\n\n");
        return NULL;
    }
}

// função para mostrar o conteúdo de uma posição da lista
void mostra(nodo *LISTA){
    int posi, cont;
    printf("O conteudo de que posicao, [de 1 ate %d] voce deseja ver: ", tam);
    scanf("%d", &posi);
 
    if((posi>0) && (posi <= tam)){
        nodo *atual = LISTA->prox;
        for(cont=1 ; cont < posi ; cont++){
            atual=atual->prox;
        }
        printf("O valor da posicao %d = %d.\n", posi, atual->info );
    } else {
        printf("Posicao invalida informada.\n");
    }   
}

// função para liberar os nodos da lista
void libera(nodo *LISTA) {
    if(!vazia(LISTA)){
        nodo *proxNodo,*atual;
        atual = LISTA->prox;
        while(atual != NULL){
            proxNodo = atual->prox;
            free(atual);
            atual = proxNodo;
        }
    }
}

