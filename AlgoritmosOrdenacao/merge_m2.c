#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<math.h>
#define TAM 10
void imprime(int comeco, int tamanho,int *vetor);
void preenche(int tamanho,int *vetor);
void mergeSort(int *V, int inicio, int fim);
void merge (int *V, int inicio, int meio, int fim);
int main(){
	int vetor[TAM],tamanho=TAM;
	preenche(tamanho,vetor);
	printf("Vetor sem ordenar:\n");
	imprime(0, tamanho-1,vetor);
	mergeSort(vetor,0,tamanho-1);
	printf("Vetor ordenado:\n");
	imprime(0, tamanho-1,vetor);
	return 0;
}
void imprime(int comeco, int tamanho,int *vetor){
	int i;
	printf("IMPRIMINDO\n");
	for(i=comeco;i<tamanho;i++){
		printf("%d-",vetor[i]);
	}
	printf("%d\n\n\n",vetor[i]);
}
void preenche(int tamanho,int *vetor){
	 int i;
	 srand(time(NULL));
     for (i = 0; i < TAM; i++)
     {
        vetor[i]=rand() % TAM;
     }
}
void mergeSort(int *V, int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio=floor((inicio+fim)/2);//floor � a uma fun��o da biblioteca math.h que arredonda para baixo o resultado da divis�o, isso serve para descobrir o meio do vetor
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);
		imprime(inicio, fim, V);
	}
}
void merge (int *V, int inicio, int meio, int fim){
	// recebe "duas" listas pre-ordernadas
	// V[inicio..meio] 	-> Lista 1
	// V[meio+1..fim]		-> Lista 2
	int aux, pDown;
	int i, j;
	// Se o fim da lista 1 for menor/igual que o começo da lista 2, retorna
	if(V[meio] <= V[meio+1]) return;
	// senao
	// pega o indice do começo da lista 2
	j = meio + 1;
	// vai do inicio da lista 1, procurando alguem menor que ele
	i = inicio;
	for(j=meio+1 ; j>=i ; j--){
		if(V[i] > V[j]){
			// quando achar, salva o atual
			aux = V[j];
			// e comeca a descer a lista
			pDown = j;
			// percorre pra baixo, copiando pra cima
			while(pDown < i){
				V[pDown] = V[pDown-1];
				pDown--;
			}
			V[pDown] = aux;
		}
	}
}
