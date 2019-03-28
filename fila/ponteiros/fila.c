#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;
}Node;

typedef struct fila{
    Node *inicio;
    Node *fim;
    int tamanho;
}Fila;

void cria_fila(Fila *fila){
    fila->inicio=NULL;
    fila->tamanho=0;
    fila->fim=NULL;
}


void enfilera(Fila *fila,int valor){
    if(fila->inicio == NULL){
        fila->inicio=malloc(sizeof(Node));
        fila->fim=fila->inicio;
        fila->inicio->prox=NULL;
        fila->inicio->valor=valor;
    }else{
        Node *novo = malloc(sizeof(Node));
        novo->valor=valor;
        novo->prox=NULL;
        fila->fim->prox=novo;
        fila->fim=novo;
    }

}

void desinfilera(Fila *fila){
    if(fila->inicio==NULL)
        printf("\nFILA VAZIA\n");
    else{
        Node *atual=fila->inicio;
        fila->inicio=fila->inicio->prox;
        free(atual);
    }


}

void imprime(Fila fila){
    Node *atual = fila.inicio;
    printf("\nFILA: ");
    while(atual != NULL) {
        printf("|%d|",atual->valor);
        atual=atual->prox;

    }
    printf("\n");
}

int main() {
    Fila fila;
    cria_fila(&fila);
//    enfilera(&fila,1);
//    enfilera(&fila,2);
//    enfilera(&fila,3);
//    enfilera(&fila,4);
//    imprime(fila);
//    desinfilera(&fila);
//    imprime(fila);
//    desinfilera(&fila);

    int op,valor;
    do{
        printf("Digite 1 para enfileirar\nDigite 2 para desinfileirar\nDigite 3 para imprimir\nDigite 4 para sair\n\nOpção escolhida: ");
        scanf("%d",&op);

        switch(op){
            case 1:
                printf("Digite o valor para adicionar na fila: ");
                scanf("%d",&valor);
                enfilera(&fila,valor);
                imprime(fila);
            break;
            case 2:
                printf("Desinfileirando....\n");
                desinfilera(&fila);
                imprime(fila);
            break;
            case 3:
                imprime(fila);
            break;

            case 4:
            break;

            default:
                printf("Opção invalida tente Novamente!\n");
                op=0;
            break;
        }


    }while(op!=4);
    return 0;
}
