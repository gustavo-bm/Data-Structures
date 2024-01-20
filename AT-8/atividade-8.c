#include <stdio.h>

void swap(int vetor[], int a, int b);
void Insertion_Sort(int vetor[], int max);
void Retira_repetidos(int vetor[], int max);
void teste(int vetor[], int max);
int busca(int vetor[], int max, int key);

int main()
{
    int N, porcas[200000], parafusos[200000], novo_max = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &porcas[i]);
    }

    Insertion_Sort(porcas, N);

    for (int j = 0; j < N; j++)
    {
        scanf("%d", &parafusos[j]);
    }

    Insertion_Sort(parafusos, N);

    Retira_repetidos(porcas, N);
    teste(porcas, N);

    Retira_repetidos(parafusos, N);
    teste(parafusos, N);

    for (int i = 0; i < N; i++)
    {
        if (porcas[i] != 0)
        {
            if(busca(parafusos, N, porcas[i]))
            {
                porcas[novo_max] = porcas[i];
                parafusos[novo_max] = porcas[i];
                novo_max++;
            }
        }
    }

    for (int i = 0; i < novo_max; i++)
    {
        printf("%d - %d\n", porcas[i], parafusos[i]);
    }

    return 0;
}

void Insertion_Sort(int vetor[], int max)
{
    for (int k = 1; k < max; k++)
    {
        int l = k;

        while (l > 0 && vetor[l - 1] > vetor[l])
        {
            swap(vetor, l - 1, l);
            l--;
        }
    }
}

void swap(int vetor_aux[], int a, int b)
{
    int t = vetor_aux[a];
    vetor_aux[a] = vetor_aux[b];
    vetor_aux[b] = t;
}

void Retira_repetidos(int vetor[], int max)
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

void teste(int vetor[], int max)
{
    for (int j = 0; j < max; j++)
    {
        printf("%d ", vetor[j]);
    }

    printf("\n");
}

int busca(int vetor[], int max, int key){

    for (int i = 0; i < max; i++)
    {
        while (vetor[i] == 0)
        {
            i++;
        }

        if (vetor[i] > key)
        {
            return 0;
        }
        else if (vetor[i] == key)
        {
            return 1;
        }
    }

    return 0;
}