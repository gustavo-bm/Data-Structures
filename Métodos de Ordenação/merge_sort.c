#include <stdio.h>

void mergesort(int vetor[], int aux[], int imin, int imax);
void merge(int vetor[], int aux[], int imin, int imid, int imax);

int main() {
    int vetor[100], aux[100], imin, imax, n;

    // Solicita o tamanho da sequência ao usuário
    printf("Tamanho da sequencia: \n");
    scanf("%d", &n);

    // Lê os elementos da sequência
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Define os valores iniciais de imin e imax
    imax = n - 1;
    imin = 0;

    // Chama a função mergesort para ordenar o vetor
    mergesort(vetor, aux, imin, imax);

    // Imprime o vetor ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
}

void mergesort(int vetor[], int aux[], int imin, int imax) {
    if (imax <= imin)
        return;

    int imid = imin + ((imax - imin) / 2);

    // Chama recursivamente mergesort para as metades esquerda e direita
    mergesort(vetor, aux, imin, imid);
    mergesort(vetor, aux, imid + 1, imax);

    // Chama a função merge para combinar as duas metades ordenadas
    merge(vetor, aux, imin, imid, imax);
}


void merge(int vetor[], int aux[], int imin, int imid, int imax) {
    int i = imin, j = imid + 1;

    // Copia os elementos para o vetor auxiliar
    for (int k = imin; k <= imax; k++)
        aux[k] = vetor[k];

    // Combina as duas metades ordenadas no vetor original
    for (int k = imin; k <= imax; k++)
        if (i > imid)
            vetor[k] = aux[j++];
        else if (j > imax)
            vetor[k] = aux[i++];
        else if (aux[j] < aux[i])
            vetor[k] = aux[j++];
        else
            vetor[k] = aux[i++];
}


/*if (key < vetor[1])
    {
        return (-1);
    }

    int imax = max - 1, imin = 0;

    while (imax > imin)
    {
        int imid = imin + ((imax - imin) / 2);

        if (key < vetor[imid])
        {
            imax = imid - 1;
        }
        else if (key > vetor[imid])
        {
            if (imid == 0)
            {
                return (vetor[max]);
            }
            else
            {
                imin = imid + 1;
            }
        }
        else
        {
            return (vetor[imid]);
        }
    }

    if (key <= vetor[imax])
    {
        return (vetor[imax]);
    }
    else
    {
        return (vetor[imax + 1]);
    }*/