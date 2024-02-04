#include <stdio.h>

void trocar(long int *a, long int *b);
int particionar(long int vetor[], int inicio, int fim);
void quickSort(long int vetor[], int inicio, int fim);
void imprimirvetor(long int vetor[], int tamanho);

// Exemplo de uso
int main() {
    long int N, tamanho;

    printf("Tamanho do vetor:\n");
    scanf("%ld", &N);
    
    long int vetor[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &vetor[i]);
    }
    
    tamanho = N;

    printf("Vetor original: ");
    imprimirvetor(vetor, tamanho);

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado: ");
    imprimirvetor(vetor, tamanho);

    return 0;
}

// Função para trocar dois elementos em um vetor
void trocar(long int *a, long int *b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar a posição correta do pivô no vetor
int particionar(long int vetor[], int inicio, int fim) {
    long int pivô = vetor[fim]; // Escolha do pivô (pode ser escolhido de diferentes maneiras)
    int i = (inicio - 1); // Índice do menor elemento

    // Percorre o vetor e move elementos menores que o pivô para a esquerda
    // e elementos maiores para a direita
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivô) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    // Troca o pivô com o elemento na posição correta
    trocar(&vetor[i + 1], &vetor[fim]);

    return (i + 1);
}

// Função principal do QuickSort
void quickSort(long int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra a posição do pivô e separa o vetor em dois
        int indicePivo = particionar(vetor, inicio, fim);

        // Recursivamente ordena as sub-listas à esquerda e à direita do pivô
        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}

// Função de utilidade para imprimir um vetor
void imprimirvetor(long int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%ld ", vetor[i]);
    printf("\n");
}
