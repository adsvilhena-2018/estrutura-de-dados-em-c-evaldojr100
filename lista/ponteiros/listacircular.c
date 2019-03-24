#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;

}Node;

typedef struct lista{
    Node *inicio;
    int tamanho;
}Lista;

void cria_lista(Lista *lista){
	lista->inicio=NULL;
	lista->tamanho=0;
}

void insere_lista_vazia(Lista *lista,int valor){
			lista->inicio = malloc(sizeof(Node));
			lista->inicio->prox = lista->inicio;
			lista->inicio->valor = valor;
			lista->tamanho++;
}

Node *retorna_ultimo(Lista *lista){
	Node *atual = lista->inicio;
	do{
		atual=atual->prox;
	}while(atual->prox!=lista->inicio);
	return atual;
}

void imprime(Lista lista){
	Node *atual=lista.inicio;
	do{
		printf("|%d|",atual->valor);
		atual=atual->prox;
	}while(atual !=lista.inicio);
	printf("\n");
}

void insere_fim(Lista *lista,int valor){
	if(lista->inicio == NULL){
		lista->inicio = malloc(sizeof(Node));
		lista->inicio->valor=valor;
		lista->inicio->prox=lista->inicio;
		lista->tamanho++;
	}else{
		Node *atual = lista->inicio;
		do{
			atual=atual->prox;
		}while(atual->prox != lista->inicio);

		Node *novo = malloc(sizeof(Node));
		novo->valor=valor;
		novo->prox=lista->inicio;
		atual->prox=novo;
		lista->tamanho++;
	}

}

void insere_inicio(Lista *lista,int valor){
	if(lista->inicio ==NULL){
		insere_lista_vazia(lista,valor);
	}else{
		Node *novo = malloc(sizeof(Node));
		Node *ultimo = retorna_ultimo(lista);
		novo->valor=valor;
		novo->prox=lista->inicio;
		lista->inicio=novo;
		ultimo->prox=novo;
		lista->tamanho++;
	}

}

void insere_posicao(Lista *lista, int pos, int valor){
	if(pos>lista->tamanho)
		printf("Não é possivel inserir nesta posição");
	else if(lista->inicio == NULL )
		insere_lista_vazia(lista,valor);
	else if(pos == 0)
		insere_inicio(lista,valor);
	else if(pos == lista->tamanho)
		insere_fim(lista,valor);
	else{
		Node *atual = lista->inicio;
		for(int i=0;i<pos-1;i++){
			atual=atual->prox;
		}
		Node *novo = malloc(sizeof(Node));
		novo->valor=valor;
		novo->prox=atual->prox;
		atual->prox=novo;
		lista->tamanho++;
	}
}

void remove_fim(Lista *lista){
	if(lista->inicio == NULL)
		printf("Lista Vazia");
	else{
		Node *atual=lista->inicio;
		Node *anterior=atual;
		do{
			anterior=atual;
			atual=atual->prox;
		}while(atual->prox !=lista->inicio);
		anterior->prox=lista->inicio;
		free(atual);
		lista->tamanho--;
	}
}

void remove_inicio(Lista *lista){
	if(lista->inicio==NULL)
		printf("Lista Vazia");
	else{
		Node *atual =lista->inicio;
		Node *ultimo = retorna_ultimo(lista);
		lista->inicio=lista->inicio->prox;
		free(atual);
		ultimo->prox=lista->inicio;
		lista->tamanho--;
	}
}

void remove_posicao(Lista *lista,int pos){
	if(lista->inicio == NULL)
		printf("A lista já está Vazia");
	else if(pos > lista->tamanho)
		printf("Não pode Excluir nesta Função");
	else if(pos==lista->tamanho)
		remove_fim(lista);
	else if(pos ==0)
		remove_inicio(lista);
	else{
		Node *atual =lista->inicio;
		Node *anterior = atual;
		for(int i=0;i<pos;i++){
			anterior=atual;
			atual=atual->prox;
		}
		anterior->prox=atual->prox;
		free(atual);
		lista->tamanho--;
	}
}

void encontra_remove(Lista *lista,int valor){
    int indice;
	Node *atual = lista->inicio;
	for ( int i = 0; i < lista->tamanho; ++ i) {
			if(atual->valor==valor){
				printf("Indice: %d\tValor: %d\n",i,atual->valor);
			}
	atual=atual->prox;
	}
	printf("Digite qual indice vc deseja remover:");
	scanf("%d",&indice);
	remove_posicao(lista,indice);

}
int main(void) {
	Lista lista;
	cria_lista(&lista);
	insere_fim(&lista,1);
	insere_fim(&lista,2);
	insere_fim(&lista,3);
	insere_inicio(&lista,4);
	insere_inicio(&lista,5);
	insere_posicao(&lista,2,6);
	imprime(lista);
	remove_fim(&lista);
	remove_inicio(&lista);
	remove_posicao(&lista,4);
	imprime(lista);
	insere_inicio(&lista,8);
	insere_fim(&lista,7);
	insere_fim(&lista,8);
	encontra_remove(&lista,8);



	imprime(lista);

}
