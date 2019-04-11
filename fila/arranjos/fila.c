#include <stdio.h>
#include <stdlib.h>

 int vetor[1000];
 int fim=-1;
 int inicio=-1;

void enfilera(int valor){
	if(fim==-1){
		vetor[fim+1]=valor;
		fim++;
		inicio++;
	}else{
		vetor[fim+1]=valor;
		fim++;
	}
}
void desenfileira(){
	if(inicio==-1 && fim==-1)
		printf("Fila Vazia");
	else if(inicio==fim){
		inicio=-1;
		fim=-1;
	}else{
		inicio++;
	}

}
void imprime(){
	if(inicio==-1 && fim==-1)
		printf("Fila Vazia!!!");
	else{
		for (int i = inicio; i <= fim; i++) {
				printf("|%d|",vetor[i]);
		}
	}
	printf("\n");
}
int main(void) {
	enfilera(1);
	enfilera(2);
	enfilera(3);
	enfilera(4);
	enfilera(5);
	imprime();
	desenfileira();
	imprime();
	desenfileira();
	imprime();
	desenfileira();
	imprime();
	desenfileira();
	imprime();
	desenfileira();
	imprime();
	return 0;
}
