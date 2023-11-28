/* Aluno: Gustavo Bianchini MOraeS - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

void swap(int tam_emb[], int a, int b);
void Insertion_Sort(int tam_emb[], int E);
int Busca_Binaria(int tam_emb[], int garrafa, int E);

int main()
{
    int E, tam_emb[10000];
    int G, tam_garrafas[10000];

    scanf("%d ", &E);

    for (int i = 0; i < E; i++)
    {
        scanf("%d", &tam_emb[i]);
    }

    scanf("%d ", &G);

    for (int j = 0; j < G; j++)
    {
        scanf("%d", &tam_garrafas[j]);
    }

    /* Insertion Sort*/
    Insertion_Sort(tam_emb, E);

    for (int i = 0; i < G; i++)
    {
        if (Busca_Binaria(tam_emb, tam_garrafas[i], E) < 0)
        {
            printf("descartar\n");
        }
        else
        {
            printf("%d\n", Busca_Binaria(tam_emb, tam_garrafas[i], E));
        }
    }

    return (0);
}

void Insertion_Sort(int tam_emb[], int E)
{
    for (int k = 1; k < E; k++)
    {
        int l = k;

        while (l > 0 && tam_emb[l - 1] > tam_emb[l])
        {
            swap(tam_emb, l - 1, l);
            l--;
        }
    }
}

void swap(int tam_emb_aux[], int a, int b)
{
    int t = tam_emb_aux[a];
    tam_emb_aux[a] = tam_emb_aux[b];
    tam_emb_aux[b] = t;
}

int Busca_Binaria(int tam_emb[], int garrafa, int E)
{

    if (garrafa > tam_emb[E - 1])
    {
        return (-1);
    }

    int imax = E - 1, imin = 0;

    while (imax > imin)
    {
        int imid = imin + ((imax - imin) / 2);

        if (garrafa > tam_emb[imid])
        {
            imin = imid + 1;
        }
        else if (garrafa < tam_emb[imid])
        {
            if (imid == 0)
            {
                return (tam_emb[0]);
            }
            else
            {
                imax = imid - 1;
            }
        }
        else
        {
            return (tam_emb[imid]);
        }
    }

    if (garrafa <= tam_emb[imax])
    {
        return (tam_emb[imax]);
    }
    else
    {
        return (tam_emb[imax + 1]);
    }
}