#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;
    struct node *ant;
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
			lista->inicio->prox = NULL;
			lista->inicio->ant = NULL;
			lista->inicio->valor = valor;
			lista->tamanho++;
}

void imprime(Lista lista){
    Node *atual=lista.inicio;

        while(atual!= NULL) {
            printf("|%d|",atual->valor);
            atual=atual->prox;
        }
        printf("\n");

}
void imprime_reverso(Lista lista){
	Node *atual=lista.inicio;
	        while(atual->prox != NULL) {
	        	atual=atual->prox;
	        }
	        
	        while (atual !=NULL){
	        	printf("|%d|",atual->valor);
	        	atual=atual->ant;
	        }
	        printf("\n");
}
	        

void insere_inicio(Lista *lista,int valor){
	if(lista->inicio == NULL)
		insere_lista_vazia(lista,valor);
	else{
		Node *novo = malloc(sizeof(Node));
		novo->valor=valor;
		novo->prox=lista->inicio;
		novo->ant=NULL;
		lista->inicio->ant=novo;
		lista->inicio=novo;
		lista->tamanho++;
	}
}
void insere_fim(Lista *lista,int valor){

	if(lista->inicio== NULL){
		insere_lista_vazia(lista,valor);
	}else{
		Node *atual = lista->inicio;
		while(atual->prox != NULL){
			atual= atual->prox;
		}
		Node *novo = malloc(sizeof(Node));
		novo->valor = valor;
		novo->prox = NULL;
		novo->ant = atual;
		atual->prox=novo;
		lista->tamanho++;
	}

}
void insere_posicao(Lista *lista,int valor,int pos){
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
		// Populando o nó novo
		novo->valor=valor;
		novo->ant=atual;
		novo->prox=atual->prox;

		//ANDAR COM O ATUAL UMA VEZ PARA ALTERAR O ANTERIOR
		atual=atual->prox;
		atual->ant = novo;
		//VOLTANDO O ATUAL PARA ALTERAR O PROX O ATUAL
		atual=novo->ant;
		atual->prox=novo;




		lista->tamanho++;
	}
}
void remove_fim(Lista *lista){
	if(lista->inicio == NULL)
		printf("Lista Vazia");
	else{
		Node *atual =lista->inicio;
		while(atual->prox != NULL)
			atual=atual->prox;
		Node *anterior = atual->ant;
		anterior->prox=NULL;
		free(atual);
		lista->tamanho--;
	}

}
void remove_inicio(Lista *lista){
	if(lista->inicio== NULL)
		printf("Lista Vazia");
	else{
		Node *atual=lista->inicio;
		Node *proximo = atual->prox;
		proximo->ant=NULL;
		free(atual);
		lista->inicio=proximo;
		lista->tamanho--;
	}
}

void remove_posicao(Lista *lista,int pos){
	if(lista->inicio == NULL)
		printf("A lista já está Vazia");
	else if(pos > lista->tamanho)
		printf("Não pode Excluir nesta Função");
	else if(pos==lista->tamanho-1)
	    remove_fim(lista);
	else if(pos ==0)
		remove_inicio(lista);
	else{
		Node *atual = lista->inicio;
		for(int i=0;i<pos;i++)
			atual=atual->prox;
		Node *anterior = atual->ant;
		Node *proximo = atual->prox;
		anterior->prox=proximo;
		proximo->ant=anterior;
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
int main() {

    Lista lista;
    cria_lista(&lista);
    insere_fim(&lista,1);
    insere_fim(&lista,2);
    insere_inicio(&lista,5);
    imprime(lista);
    imprime_reverso(lista);
    insere_posicao(&lista,6,2);
    imprime(lista);
    remove_fim(&lista);
    imprime(lista);
    insere_fim(&lista,7);
    insere_fim(&lista,8);
    insere_fim(&lista,9);
    insere_fim(&lista,8);
    imprime(lista);
    remove_posicao(&lista,0);
    imprime(lista);
    encontra_remove(&lista,8);
    imprime(lista);
    imprime_reverso(lista);



    return 0;
}
