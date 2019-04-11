#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *ant;
    struct node *prox;
}Node;

typedef struct pilha{
    Node *pilha_inicio;
    Node *pilha_fim;
    int tamanho;
}Pilha;

void cria_pilha(Pilha *pilha){
    pilha->pilha_inicio=NULL;
    pilha->pilha_fim=NULL;
    int tamanho=0;
}

void empilha(Pilha *pilha, int valor){
    if(pilha->pilha_inicio==NULL){
        //aloca espaço na memoria
        pilha->pilha_inicio=malloc(sizeof(Node));

        //define valores no Nó
        pilha->pilha_inicio->valor=valor;
        pilha->pilha_inicio->ant=NULL;
        pilha->pilha_inicio->prox=NULL;

        //altera fim da lista
        pilha->pilha_fim=pilha->pilha_inicio;

        //aumenta tamanho da pilha
        pilha->tamanho++;
    }else{
        //aloca espaço na memoria para um novo Nó
        Node *novo= malloc(sizeof(Node));

        //Define os valores do Nó
        novo->valor=valor;
        novo->prox=NULL;
        novo->ant=pilha->pilha_fim;

        //Encadeando a lista
        pilha->pilha_fim->prox=novo;

        //alterar o ponteiro do fim da lista
        pilha->pilha_fim=novo;

        //incrementa o tamanho da pilha
        pilha->tamanho++;


    }

}

void desempilha(Pilha *pilha){
    if(pilha->pilha_inicio==NULL)
        printf("Pilha já esta vazia!!!");
    else if(pilha->pilha_inicio==pilha->pilha_fim){
        free(pilha->pilha_inicio);
        pilha->pilha_inicio=NULL;
        pilha->pilha_fim=NULL;
        pilha->tamanho=0;
    }
    else{
        Node *anterior=pilha->pilha_fim->ant;
        anterior->prox=NULL;

        free(pilha->pilha_fim);

        pilha->pilha_fim=anterior;

        pilha->tamanho--;
    }

}

void imprime(Pilha pilha){
    if(pilha.pilha_inicio==NULL)
        printf("Pilha Vazia!!!!");

    else{
        Node *atual=pilha.pilha_inicio;

        while(atual != NULL){
            printf("|%d|",atual->valor);
            atual=atual->prox;
        }
        printf("\n");
    }
}

int main() {
    Pilha pilha;
    cria_pilha(&pilha);
    empilha(&pilha,1);
    imprime(pilha);
    empilha(&pilha,2);
    imprime(pilha);
    empilha(&pilha,3);
    imprime(pilha);
    empilha(&pilha,4);
    imprime(pilha);
    empilha(&pilha,5);
    imprime(pilha);
    empilha(&pilha,6);
    imprime(pilha);
    empilha(&pilha,7);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    desempilha(&pilha);
    imprime(pilha);
    
    return 0;
}
