/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include "deque.h"

int main()
{
    int M, N, valor, elem;
    char operacao[7];

    scanf("%d %d", &N, &M);

    DEQUE *pointer = inicializar_deque(M);

    for (int i = 0; i < N; i++)
    {
        receberinstrucao(operacao, &valor);

        if (operacao[0] == 'i')
        {
            if (operacao[6] == 'I')
            {
                if (insereI(pointer, valor, M) == 0)
                {
                    printf("cheia\n");
                }
            }
            else
            {
                if (insereF(pointer, valor, M) == 0)
                {
                    printf("cheia\n");
                }
            }
        }
        else
        {
            if (operacao[6] == 'I')
            {
                if (removeI(pointer, &elem, M) == 0)
                {
                    printf("vazia\n");
                }
                else
                {
                    printf("%d\n", elem);
                }
            }
            else
            {
                if (removeF(pointer, &elem, M) == 0)
                {
                    printf("vazia\n");
                }
                else
                {
                    printf("%d\n", elem);
                }
            }
        }
    }

    liberar(pointer);

    return 0;
}