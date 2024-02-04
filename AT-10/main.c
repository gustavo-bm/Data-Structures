/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define MAX 1000001

int verificacao(const char *expressao)
{
    struct Pilha pilha;

    inicializar_pilha(&pilha, MAX);

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        char atual = expressao[i];

        if (atual == '(' || atual == '[' || atual == '{')
        {
            empilhar(&pilha, atual);
        }
        else
        {
            if (pilha_vazia(&pilha))
            {
                destruir_pilha(&pilha);
                return 0; // Expressão mal formada
            }

            char topo = desempilhar(&pilha);

            if ((topo == '(' && atual != ')') ||
                (topo == '[' && atual != ']') ||
                (topo == '{' && atual != '}'))
            {
                destruir_pilha(&pilha);
                return 0; 
            }
        }
    }

    int resultado = pilha_vazia(&pilha);
    destruir_pilha(&pilha);

    return resultado;
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--)
    {
        char expressao[MAX];
        scanf("%s", expressao);

        if (verificacao(expressao))
        {
            printf("S\n");
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}