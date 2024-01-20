/* Aluno: Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

void merge_sort(long int vetor[], long int aux[], long int imin, long int imax);
void merge(long int vetor[], long int aux[], long int imin, long int imid, long int imax);
long int Busca_Binaria(long int tam_emb[], long int garrafa, long int E);

int main()
{
    long int P, G, qtdes_pocoes[10000], tam_garrafas[10000];
    long int aux[10000];

    scanf("%ld", &P);

    for (int i = 0; i < P; i++)
    {
        scanf("%ld", &qtdes_pocoes[i]);
    }

    scanf("%ld", &G);

    for (int j = 0; j < G; j++)
    {
        scanf("%ld", &tam_garrafas[j]);
    }

    /* Merge Sort*/
    merge_sort(qtdes_pocoes, aux, 0, G--);

    for (int i = 0; i <= G; i++)
    {
        if (Busca_Binaria(qtdes_pocoes, tam_garrafas[i], G) < 0)
        {
            printf("descartar\n");
        }
        else
        {
            printf("%ld\n", Busca_Binaria(qtdes_pocoes, tam_garrafas[i], G));
        }
    }
    return (0);
}

void merge_sort(long int vetor[], long int aux[], long int imin, long int imax)
{
    if (imax <= imin)
        return;

    int imid = imin + ((imax - imin) / 2);

    // Chama recursivamente mergesort para as metades esquerda e direita
    merge_sort(vetor, aux, imin, imid);
    merge_sort(vetor, aux, imid + 1, imax);

    // Chama a função merge para combinar as duas metades ordenadas
    merge(vetor, aux, imin, imid, imax);
}

void merge(long int vetor[], long int aux[], long int imin, long int imid, long int imax)
{
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

long int Busca_Binaria(long int vetor[], long int key, long int max)
{
    long int imin = 1, imax = max;

    if (key < vetor[1])
    {
        return (-1);
    }

    while (imin < imax)
    {
        long int imid = imin + ((imax - imin) / 2);

        if (key < vetor[imid])
        {
            imax = imid - 1;
        }
        else if (key > vetor[imid])
        {
            if (imid == max)
            {
                return vetor[max];
            }
            else
            {
                imin = imid + 1;
            }
        }
        else
        {
            return vetor[imid];
        }
    }

    if (key > vetor[imax])
    {
        return (vetor[imax]);
    }
    else
    {
    }

    return 0;
}