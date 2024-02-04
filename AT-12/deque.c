/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

struct DEQUE
{
    int I, F, qtd;
    int *valores;
};

DEQUE *inicializar_deque(int tamanho_deque)
{
    DEQUE *pointer = (DEQUE *)malloc(sizeof(DEQUE));

    pointer->valores = malloc(tamanho_deque * sizeof(int));

    pointer->I = 0;
    pointer->F = 0;
    pointer->qtd = 0;

    return pointer;
}

void receberinstrucao(char operacao[7], int *num)
{
    scanf("%7s", operacao);

    if (operacao[0] == 'i')
    {
        scanf("%d", num);
    }
}

int insereI(DEQUE *pointer, int num, int m)
{
    if (cheia(pointer, m) == 1)
    {
        return 0;
    }

    pointer->I -= 1;

    if (pointer->I < 0)
    {
        pointer->I = m - 1;
    }

    pointer->valores[pointer->I] = num;
    pointer->qtd += 1;

    return 1;
}

int insereF(DEQUE *pointer, int num, int m)
{
    if (cheia(pointer, m) == 1)
    {
        return 0;
    }
    pointer->valores[pointer->F] = num;
    pointer->F = (pointer->F + 1) % m;
    pointer->qtd += 1;

    return 1;
}

int cheia(DEQUE *pointer, int m)
{
    if (pointer->qtd == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int removeI(DEQUE *pointer, int *val, int m)
{
    if (vazia(pointer) == 1)
    {
        return 0;
    }
    *val = pointer->valores[pointer->I];
    pointer->I = (pointer->I + 1) % m;
    pointer->qtd -= 1;
    return 1;
}

int removeF(DEQUE *pointer, int *val, int m)
{
    if (vazia(pointer) == 1)
    {
        return 0;
    }
    pointer->F -= 1;
    if (pointer->F < 0)
    {
        pointer->F = m - 1;
    }
    *val = pointer->valores[pointer->F];
    pointer->qtd -= 1;
    return 1;
}

int vazia(DEQUE *pointer)
{
    if (pointer->qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void liberar(DEQUE *deq)
{
    free(deq);
}
