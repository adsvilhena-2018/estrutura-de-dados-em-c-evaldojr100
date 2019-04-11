#include <stdio.h>
#include <stdlib.h>

int vetor[1000];
int fim=-1;

void empilha(int valor){
    vetor[fim+1]=valor;
    fim++;
}
void desempilha(){
    if(fim==-1)
        printf("Pilha Vazia");
    else{
        fim--;
    }
}
void imprime(){
    for (int i = 0; i <=fim ; ++i) {
        printf("|%d|",vetor[i]);
    }
    printf("\n");
}
int main() {
    empilha(1);
    empilha(2);
    empilha(3);
    empilha(4);
    empilha(5);
    imprime();
    desempilha();
    imprime();
    desempilha();
    imprime();
    
    return 0;
}
