#include <stdio.h>
#include <stdlib.h>
typedef struct tipo_lista{
    int vetor[100];
    int inicio;
    int fim;
}Tlista;

void insere(int item,int posicao,Tlista *lista){

    //printf("Fim da Lista: %d\n",lista.fim);

    //Realocando os valores, ou seja aumnetando uma posição no vetor
    for (int i = lista->fim; i >posicao ; --i) {
        lista->vetor[i]=lista->vetor[i-1];
    }

    //Setando o valor que deve ser inserido na posição desejada
    lista->vetor[posicao]=item;
    //aumentando o fim da lista para futuras alteraçoes
    lista->fim+=1;


    //printf("Fim da Lista: %d\n",lista.fim);
    //for (int i = 0; i <lista.fim ; ++i) {
    //    printf("|%d|",lista.vetor[i]);
    //}
}

void insere_fim(int item,Tlista *lista){
    lista->vetor[lista->fim]=item;
    lista->fim+=1;
}

void imprime_lista(Tlista *lista){
    for (int i = 0; i <lista->fim ; ++i) {
        printf("|%d|",lista->vetor[i]);
    }
    printf("\n");
}

void remover(int posicao,Tlista *lista){
    for (int i = posicao; i <lista->fim ; ++i) {
        lista->vetor[i]=lista->vetor[i+1];
    }
    lista->fim-=1;
}
void remover_item(int item,Tlista *lista) {
    int cont = 0;
    for (int i = 0; i < lista->fim; ++i) {
        if (lista->vetor[i] == item)
            cont += 1;
    }
    // Remover Item direto caso ocorra apenas uma ocorrencia do mesmo
    if (cont == 1) {
        for (int i = 0; i < lista->fim; ++i) {
            if (lista->vetor[i] == item) {
                remover(i, lista);
                break;
            }
        }
        //
    } else if (cont == 0) {
        printf("Não existe esse item na Lista");
    } else {
        for (int i = 0; i < lista->fim; ++i) {
            if (lista->vetor[i] == item)
                printf("Item: %d\t Posição:%d", lista->vetor[i], i);
            int pos;
            printf("\nDigite a posição que deseja apagar:");
            scanf("%d", &pos);
            remover(pos, lista);
        }


    }
}
int main() {
    Tlista lista1;
    lista1.fim=0;
    lista1.inicio=0;

    //Populando o vetor com pelo menos 5 valores começando em 0
    for (int i = 0; i <5 ; ++i) {
        lista1.vetor[i]=i;
        lista1.fim+=1;
    }

    imprime_lista(&lista1);
    insere(55,2,&lista1);
    imprime_lista(&lista1);
    remover(2,&lista1);
    imprime_lista(&lista1);



    int op,valor,pos;
   
    printf("--------------MENU--------------\n");
    printf("Digite 1 para incluir um item;\n");
    printf("Digite 2 para remover um item;\n");
    printf("Digite 3 para verificar se lista esta vazia;\n");
    printf("Digite 4 para imprimir a Lista.\n");
    scanf("%d",&op);
   
    if(op==1){
    printf("--------------INCLUIR--------------\n");
    printf("Digite 1 para incluir um item no fim da lista;\n");
    printf("Digite 2 para incluir um item em uma posição;\n");
    scanf("%d",&op);
   
    if(op==1){
    printf("Digite o valor que deseja Inserir:");
    scanf("%d",&valor);
    insere_fim(valor,&lista1);
   
    }else if(op==2){
    printf("Digite o valor que deseja Inserir:");
    scanf("%d",&valor);
    printf("Digite a posição que deseja inserir o numero %d :");
    scanf("%d",&pos);
    insere(valor,pos,&lista1);
   
    }
    }else if(op==2){
    printf("--------------Remover--------------\n");
        printf("Digite 1 para consultar um item na lista para remoção;\n");
        printf("Digite 2 para remover por posição;\n");
        scanf("%d",&op);
        if(op==1){
        printf("Digite o valor que deseja consultar:");
        scanf("%d",&valor);
        remover_item(valor,&lista1);
       
        }else if(op==2){
        printf("Digite a posição do numero que deseja Remover :");
        scanf("%d",&pos);
        if(pos>0 && pos<lista1.fim)
        remover(pos,&lista1);
        else
        printf("Posição Invalida?");
       
        }
    }else if(op==3){
   
    }else if(op==4){
   
    }else{
    printf("Opção Invalida!!!");
    }
   
}
