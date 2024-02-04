/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

void inicializar_pilha(pilha *p, int capacidade)
{
    p->capacidade = capacidade;
    p->dados = (char *)malloc(capacidade * sizeof(char));
    p->tamanho = 0;
}

void empilhar(pilha *p, int valor)
{
    if (p->tamanho < p->capacidade)
    {
        p->dados[p->tamanho] = valor;
        p->tamanho++;
    }
}

char desempilhar(pilha *p)
{
    if (p->tamanho > 0)
    {
        p->tamanho--;

        return p->dados[p->tamanho];
    }

    return '\0';
}

int pilha_vazia(pilha *p)
{
    return (p->tamanho == 0);
}

void destruir_pilha(pilha *p)
{
    free(p->dados);
}
