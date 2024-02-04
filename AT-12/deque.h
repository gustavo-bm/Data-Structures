/* Gustavo Bianchini Moraes - R.A.: 823415 - Disciplina: Estruturas de Dados*/

typedef struct DEQUE DEQUE;

DEQUE* inicializar_deque(int tamanho_deque);
void receberinstrucao(char operacao[7], int* num);
int insereI(DEQUE* pointer, int num, int m);
int insereF(DEQUE* pointer, int num, int m);
int cheia(DEQUE* pointer, int m);
int removeI(DEQUE* pointer, int* elem, int m);
int removeF(DEQUE* pointer, int* elem, int m);
int vazia(DEQUE* pointer);
void liberar(DEQUE* pointer);