/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha
{
    char *dados;
    int capacidade;
    int tamanho;
} pilha;

void inicializar_pilha(pilha *p, int capacidade);
void empilhar(pilha *p, int valor);
char desempilhar(pilha *p);
int pilha_vazia(pilha *p);
void destruir_pilha(pilha *p);

#endif