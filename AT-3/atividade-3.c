/* Aluno: Gustavo Bianchini MOraeS - R.A.: 823415 - Disciplina: Estruturas de Dados*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int alunos;
typedef int times;

struct alunos
{
    char nome[20];
    long int H;
    int time;
};

int main() {

    struct alunos aluno[10000];

    int N, T;

    scanf("%d", &N);
    scanf("%d", &T);

    /*leitura dos dados de entrada*/
    for (int i = 0; i < N; i++)
    {
        scanf("%s %ld", aluno[i].nome, &aluno[i].H);
    }

    /*Insertion Sort que ordena os alunos de maneira decrescente por halibilade*/
    int aux;
    char str_aux[10000];
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (aluno[j].H > aluno[i].H)
            {
                aux = aluno[i].H;
                aluno[i].H = aluno[j].H;
                aluno[j].H = aux;

                strcpy(str_aux, aluno[i].nome);
                strcpy(aluno[i].nome, aluno[j].nome);
                strcpy(aluno[j].nome, str_aux);
            }
        }
    }

    /*Separação em times*/
    for (int i = -1, j = -1; i < N; )
    {
        while (j < T)
        {
            j++;
            i++;

            if (i >= N || j == T)
            {
                break;
            } 
            else
            {
                aluno[i].time = j;
            }
        }
        j = 0;
    }

    /*ordenação em ordem alfabética dos integrantes de cada time*/
    for (int k = 0; k < T; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = i + T; j < N; j += T)
            {
                if (j < N && strcmp(aluno[i].nome, aluno[j].nome) > 0) 
                {
                    strcpy(str_aux, aluno[i].nome);
                    strcpy(aluno[i].nome, aluno[j].nome);
                    strcpy(aluno[j].nome, str_aux);
        
                    aux = aluno[j].H;
                    aluno[j].H = aluno[i].H;
                    aluno[i].H = aux;
                }
            }
        }
    }
    
    /*saída que fornece a lista dos times*/
    for (int i = 0; i < T; i++)
    {
        printf("Time %d\n", i + 1);
        for (int j = i; j < N; j += T)
        {
            if (j < N) 
            {
                printf("%s\n", aluno[j].nome);
            }
        }
        printf("\n");
    }
    
    return(0);
}

