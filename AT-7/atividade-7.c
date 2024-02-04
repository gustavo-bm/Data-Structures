/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

int Busca_Binaria(int vetor[], int max, int key)
{
    int imin = 0, imax = max - 1, resultado = -1;

    while (imin <= imax)
    {
        int imid = (imin + imax) / 2;

        if (vetor[imid] <= key)
        {
            resultado = imid;
            imin = imid + 1;
        }
        else
        {
            imax = imid - 1;
        }
    }

    return resultado;
}

void merge(int vetor[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);

        merge(vetor, l, m, r);
    }
}

int main()
{
    int P, G;

    scanf("%d", &P);

    int pocoes[P];
    for (int i = 0; i < P; i++)
    {
        scanf("%d", &pocoes[i]);
    }

    scanf("%d", &G);

    int garrafas[G];
    for (int i = 0; i < G; i++)
    {
        scanf("%d", &garrafas[i]);
    }

    mergeSort(pocoes, 0, P - 1);

    for (int i = 0; i < G; i++)
    {
        int resultado = Busca_Binaria(pocoes, P, garrafas[i]);

        if (resultado != -1)
        {
            printf("%d\n", pocoes[resultado]);
        }
        else
        {
            printf("descartar\n");
        }
    }

    return 0;
}
