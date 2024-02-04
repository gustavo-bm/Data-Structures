/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>

void merge_sort(long int vetor[], long int aux[], int imin, int imax);
void merge(long int vetor[], long int aux[], int imin, int imid, int imax);
void retira_repetidos(long int vetor[], int max);
int retira_zeros(long int vetor[], int max);
int busca_binaria(long int vetor[], int max, int key);

int main()
{
    long int N, novo_max = 0;
    int num_dif_porcas, num_dif_parafusos;

    scanf("%ld", &N);
    long int porcas[N], parafusos[N], vetor_aux[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &porcas[i]);
    }

    merge_sort(porcas, vetor_aux, 0, N - 1);

    for (int j = 0; j < N; j++)
    {
        scanf("%ld", &parafusos[j]);
    }

    merge_sort(parafusos, vetor_aux, 0, N - 1);

    retira_repetidos(porcas, N);
    num_dif_porcas = retira_zeros(porcas, N);

    retira_repetidos(parafusos, N);
    num_dif_parafusos = retira_zeros(parafusos, N);

    for (int i = 0; i < num_dif_porcas; i++)
    {
        if (busca_binaria(parafusos, num_dif_parafusos, porcas[i]))
        {
            vetor_aux[novo_max] = porcas[i];
            novo_max++;
        }
    }

    for (int i = 0; i < novo_max; i++)
    {
        porcas[i] = vetor_aux[i];
        parafusos[i] = vetor_aux[i];
    }

    for (int i = 0; i < novo_max; i++)
    {
        printf("%ld - %ld\n", porcas[i], parafusos[i]);
    }

    return 0;
}

void merge_sort(long int vetor[], long int aux[], int imin, int imax)
{
    if (imax <= imin)
        return;

    int imid = imin + ((imax - imin) / 2);

    merge_sort(vetor, aux, imin, imid);
    merge_sort(vetor, aux, imid + 1, imax);

    merge(vetor, aux, imin, imid, imax);
}

void merge(long int vetor[], long int aux[], int imin, int imid, int imax)
{
    int i = imin, j = imid + 1;

    for (int k = imin; k <= imax; k++)
        aux[k] = vetor[k];

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

void retira_repetidos(long int vetor[], int max)
{
    int j;
    for (int i = 0; i < max; i++)
    {
        j = i + 1;

        while (vetor[i] == vetor[j])
        {
            vetor[j] = 0;
            j++;
        }
    }
}

int retira_zeros(long int vetor[], int max)
{
    int j = 0;

    for (int i = 0; i < max; i++)
    {
        while (vetor[i] == 0)
        {
            i++;
        }
        if (i < max)
        {
            vetor[j] = vetor[i];
            j++;
        }
    }

    return j;
}

int busca_binaria(long int vetor[], int max, int key)
{
    int imin = 0, imax = max - 1;

    while (imax >= imin)
    {
        int imid = imin + ((imax - imin) / 2);

        if (imid < 0)
        {
            break;
        }

        if (key > vetor[imid])
        {
            imin = imid + 1;
        }
        else if (key < vetor[imid])
        {
            imax = imid - 1;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}