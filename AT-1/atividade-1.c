#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMO 1000

void BubbleSort (long long int vetor[]);

int main () {
    long long int vetor[MAXIMO];

  srand( (unsigned)time(NULL) );
  for (long long int i = 0; i < MAXIMO; i++)
    {
        vetor[i] = rand() % MAXIMO;
    }

    clock_t start, end;
  double cpu_time_used = 0;

  start = clock();
    BubbleSort (vetor);
  end = clock();

  cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;

  printf( "Tempo médio: %lf\n\n", cpu_time_used);	
}

void BubbleSort (long long int vetor[]){
    long long int num_comparacoes = 0, num_trocas = 0;
    long long int swapped;
    long long int i = 0;
    long long int aux;

    do {
        swapped = 0;

        for( int j = MAXIMO - 1; j > i; j--)
        {
            if ( vetor[j-1] > vetor[j])
            {
                aux = vetor[j-1]; 
                vetor[j-1] = vetor[j]; 
                vetor[j] = aux;
                swapped = 1;

                num_trocas++;
                num_comparacoes++;
            }
            num_comparacoes++;
        }
        i++;
        num_comparacoes++; /*while*/
    } while( swapped && i < MAXIMO );

        printf("Número de comparações: %lld\n", num_comparacoes);
        printf("Número de trocas: %lld\n", num_trocas);
}