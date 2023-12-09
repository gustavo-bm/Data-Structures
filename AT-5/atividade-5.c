#include <stdio.h>

int soma(int valores[], int tamanho);
int maior(int valores[], int tamanho, int max);
int menor(int valores[], int tamanho, int max);
int crescente(int valores[], int tamanho);
int decrescente(int valores[], int tamanho);
int espelhada(int valores[], int i, int j);

int main(void) {
  int valores[1000], tamanho;

  scanf("%d", &tamanho);

  for (int i = 0; i < tamanho; i++){
    scanf("%d", &valores[i]);
  }

  printf("Soma: %d\n", soma(valores, tamanho));

  printf("Maior: %d\n", maior(valores, tamanho, valores[0]));

  printf("Menor: %d\n", menor(valores, tamanho, valores[0]));

  printf("Crescente: ");
  
  if(crescente(valores, tamanho)){
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  printf("Decrescente: ");

  if(decrescente(valores, tamanho)){
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  printf("Espelhada: ");

  if(espelhada(valores, 0, tamanho - 1)){
    printf("sim\n");
  } else {
    printf("nao\n");
  }
  return 0;
}

int soma(int valores[], int tamanho){
  if (tamanho <= 0){
    return 0;
  }
  
  return valores[tamanho - 1] + soma(valores, tamanho - 1);
}

int maior(int valores[], int tamanho, int max){
  if (tamanho <= 0){
    return max;
  }
  if (valores[tamanho - 1] > max){
    return maior(valores, tamanho - 1, valores[tamanho - 1]);
  } else {
    return maior(valores, tamanho - 1, max);
  }
}

int menor(int valores[], int tamanho, int min){
  if (tamanho <= 0){
    return min;
  }
  if (valores[tamanho - 1] < min){
    return menor(valores, tamanho - 1, valores[tamanho - 1]);
  } else {
    return menor(valores, tamanho - 1, min);
  }
}

int crescente(int valores[], int tamanho){
  if (tamanho <= 1){
    return 1;
  } else {
    return ((valores[tamanho - 1] > valores[tamanho - 2]) && crescente(valores, tamanho - 1));
  }
}

int decrescente(int valores[], int tamanho){
  if (tamanho <= 1){
    return 1;
  } else {
    return ((valores[tamanho - 1] < valores[tamanho - 2]) && decrescente(valores, tamanho - 1));
  }
}

int espelhada(int valores[], int i, int j){
  if (i >= j){
    return 1;
  } else {
    return ((valores[i] == valores[j]) && espelhada(valores, i + 1, j - 1));
  }
}