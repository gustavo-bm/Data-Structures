#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 100

void BubbleSort (long long int vetor[]);
void swap(long long int vetor[], long long int a, long long int b); 

int main () {
    long long int vetor[MAXIMO];

	for (int i = 0; i < MAXIMO; i++)
    {
        vetor[i] = rand() % MAXIMO;
    }

    for (int i = 0; i < MAXIMO; i++)
    {
        printf("%lld ", vetor[i]);
    }
        printf("\n");


    BubbleSort (vetor);

    for (int i = 0; i < MAXIMO; i++)
    {
        printf("%lld ", vetor[i]);
    }
	    printf("\n");
}

void swap(long long int vetor[], long long int a, long long int b){ 
    long long int aux = vetor[a]; 
    vetor[a] = vetor[b]; 
    vetor[b] = aux;
    }

void BubbleSort (long long int vetor[]){
    int swapped;
    long long int i = 0, trocas = 0, acesso_ao_vetor = 0;

    do {
        swapped = 0;

        for( int j = MAXIMO - 1; j > i; j--)
        {
            if ( vetor[j-1] > vetor[j])
            {
                swap(vetor, j - 1, j);
                swapped = 1;
                trocas++;
                acesso_ao_vetor += 4;
            }

            acesso_ao_vetor += 2;
        }
        i++;
    } while( swapped && i < MAXIMO );

    }

