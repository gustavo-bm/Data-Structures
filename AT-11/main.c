/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include "fila.h"

int main()
{
    int T, num;
    scanf("%d", &T);

    Fila *fila = criar_fila();

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &num);
        enfileirar(fila, num);
    }

    inverter(fila);

    for (int i = 0; i < T - 1; i++)
    {
        printf("%d ", desenfileirar(fila));
    }

    printf("%d\n", desenfileirar(fila));
   
    destruir_fila(fila);

    return 0;
}
