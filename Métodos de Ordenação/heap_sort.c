#include <stdio.h>

// Função para ajustar o heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como a raiz
    int left = 2 * i + 1; // Índice do filho da esquerda
    int right = 2 * i + 2; // Índice do filho da direita

    // Se o filho da esquerda é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho da direita é maior que a raiz
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != i) {
        // Troca a raiz com o maior
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Chama a recursão para ajustar o sub-heap afetado
        heapify(arr, n, largest);
    }
}

// Função principal que realiza o Heap Sort
void heapSort(int arr[], int n) {
    // Constrói um heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama a função heapify na subárvore reduzida
        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    // Obtem o número de elementos do vetor
    printf("Digite o numero de elementos do vetor: ");
    scanf("%d", &n);

    int arr[n];

    // Obtem os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Chama a função heapSort para ordenar o vetor
    heapSort(arr, n);

    // Imprime o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
