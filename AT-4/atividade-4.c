/* rena: Gustavo Bianchini MOraeS - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int P, I;
    float h;
}renas;

int main(){
    int num_renas, renas_treno;
    renas rena[66000];

    scanf("%d %d", &num_renas, &renas_treno);

    for (int i = 0; i < num_renas; i++)
    {
        scanf("%s %d %d %f", rena[i].nome, &rena[i].P, &rena[i].I, &rena[i].h);
    }

    int aux;
    char str_aux[100];
    for (int i = 0; i < num_renas; i++)
    {
        for (int j = i + 1; j < num_renas; j++)
        {
            if (rena[i].P < rena[j].P)
            {
                aux = rena[i].P;
                rena[i].P = rena[j].P;
                rena[j].P = aux;

                aux = rena[i].I;
                rena[i].I = rena[j].I;
                rena[j].I = aux;

                aux = rena[i].h;
                rena[i].h = rena[j].h;
                rena[j].h = aux;

                strcpy(str_aux, rena[i].nome);
                strcpy(rena[i].nome, rena[j].nome);
                strcpy(rena[j].nome, str_aux);

            } else if (rena[j].P == rena[i].P)
            {
                if (rena[i].I > rena[j].I)
                {
                    aux = rena[i].P;
                    rena[i].P = rena[j].P;
                    rena[j].P = aux;

                    aux = rena[i].I;
                    rena[i].I = rena[j].I;
                    rena[j].I = aux;

                    aux = rena[i].h;
                    rena[i].h = rena[j].h;
                    rena[j].h = aux;

                    strcpy(str_aux, rena[i].nome);
                    strcpy(rena[i].nome, rena[j].nome);
                    strcpy(rena[j].nome, str_aux);

                } else if (rena[i].I == rena[j].I)
                {
                    if (rena[i].h > rena[j].h) 
                    {
                        aux = rena[i].P;
                        rena[i].P = rena[j].P;
                        rena[j].P = aux;

                        aux = rena[i].I;
                        rena[i].I = rena[j].I;
                        rena[j].I = aux;

                        aux = rena[i].h;
                        rena[i].h = rena[j].h;
                        rena[j].h = aux;

                        strcpy(str_aux, rena[i].nome);
                        strcpy(rena[i].nome, rena[j].nome);
                        strcpy(rena[j].nome, str_aux);

                    } else if (rena[i].h == rena[j].h)
                    {
                        if (strcmp(rena[i].nome, rena[j].nome) > 0)
                        {
                            aux = rena[i].P;
                            rena[i].P = rena[j].P;
                            rena[j].P = aux;

                            aux = rena[i].I;
                            rena[i].I = rena[j].I;
                            rena[j].I = aux;

                            aux = rena[i].h;
                            rena[i].h = rena[j].h;
                            rena[j].h = aux;

                            strcpy(str_aux, rena[i].nome);
                            strcpy(rena[i].nome, rena[j].nome);
                            strcpy(rena[j].nome, str_aux);
                        }
                    }
                }
            }
        }
    }

    printf("CENARIO\n");

    for (int i = 0; i < renas_treno; i++)
    {
        printf("%d - %s\n", i + 1, rena[i].nome);
    }

    return(0);
}
