/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#ifndef FILA_H
#define FILA_H

typedef struct Node
{
    int dado;
    struct Node *prox;
} Node;

typedef struct
{
    Node *primeiro;
    Node *ultimo;
} Fila;

Fila* criar_fila();
void enfileirar(Fila* fila, int valor);
int desenfileirar(Fila* fila);
int vazia(Fila* fila);
void destruir_fila(Fila* fila);
void inverter(Fila *fila);

#endif