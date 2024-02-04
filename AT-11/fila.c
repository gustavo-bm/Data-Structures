/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdlib.h>
#include <stdlib.h>
#include "fila.h"

Fila *criar_fila()
{
    Fila *nova_fila = (Fila *)malloc(sizeof(Fila));
    if (nova_fila == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nova_fila->primeiro = NULL;
    nova_fila->ultimo = NULL;

    return nova_fila;
}

void enfileirar(Fila *fila, int valor)
{
    Node *novo_node = (Node *)malloc(sizeof(Node));

    if (novo_node == NULL)
    {
        exit(EXIT_FAILURE);
    }

    novo_node->dado = valor;
    novo_node->prox = NULL;

    if (fila->ultimo == NULL)
    {
        fila->primeiro = novo_node;
        fila->ultimo = novo_node;
    }
    else
    {
        fila->ultimo->prox = novo_node;
        fila->ultimo = novo_node;
    }
}

int desenfileirar(Fila *fila)
{
    if (vazia(fila))
    {
        exit(EXIT_FAILURE);
    }

    Node *aux = fila->primeiro;
    int valor = aux->dado;

    fila->primeiro = fila->primeiro->prox;

    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }

    free(aux);
    return valor;
}

int vazia(Fila *fila)
{
    return fila->primeiro == NULL;
}

void destruir_fila(Fila *fila)
{
    while (!vazia(fila))
    {
        desenfileirar(fila);
    }

    free(fila);
}

void inverter(Fila *fila)
{
    if (!vazia(fila))
    {
        int elemento = desenfileirar(fila);
        inverter(fila);
        enfileirar(fila, elemento);
    }
}