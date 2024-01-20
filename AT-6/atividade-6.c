/* Gustavo Bianchini MoraeS - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>

int marcas(int vetor[], int pol_int, int min, int max)
{

    if (max <= min)
        return 0;

    int mid = min + ((max - min) / 2);

    vetor[mid + 1] = pol_int - 1;

    marcas(vetor, pol_int - 1, min, mid);
    marcas(vetor, pol_int - 1, mid + 1, max);

    return 0;
}

int imprimir(int vetor[], int pol_int, int max, int j, int num)
{

    if (j > max)
        return 0;

    for (int i = 0; i < vetor[j]; i++)
    {
        printf("-");
    }

    if (vetor[j] == pol_int)
    {
        printf(" %d", num + 1);
        num++;
    }
    printf("\n");

    imprimir(vetor, pol_int, max, j + 1, num);

    return 0;
}

int main()
{
    int tam_regua, pol_int, max = 1;

    scanf("%d %d", &tam_regua, &pol_int);

    for (int i = 0; i < pol_int - 1; i++)
    {
        max *= 2;
    }

    int vetor[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        vetor[i] = pol_int;
    }

    marcas(vetor, pol_int, 0, max - 1);

    for (int i = 0; i < pol_int; i++)
    {
        printf("-");
    }
    printf(" 0\n");

    for (int i = 0; i < tam_regua; i++)
    {
        imprimir(vetor, pol_int, max, 1, i);
    }

    return 0;
}
