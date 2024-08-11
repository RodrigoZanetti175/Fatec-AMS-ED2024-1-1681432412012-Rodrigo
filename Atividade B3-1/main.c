/*-----------------------------------------------------------*/
/*       FATEC-São Caetano do Sul Estrutura de Dados         */
/*                      Atividade B3-1                       */
/*       Objetivo: Calcular o tempo do insertion sort        */
/*                                                           */
/* Autor:Rodrigo Leite Zanetti                               */
/*                                        Data:11/08/2024    */
/*-----------------------------------------------------------*/

#include <stdio.h>

int * insertion_sort(int arr[], int n){
  for(int j = 1; j < n; j++){ // t + 3t(n)
    int key = arr[j]; // 2t(n)
    int i = j - 1; // 2t(n)
    while(i>=0 && arr[i] > key){ // 4t(n²) -> 3 lógicas + 1 acesso
      arr[i+1] = arr[i]; // 4t(n²) -> 2 acessos + 1 atribuição + 1 aritmética
      i -= 1; // 2t(n²) 
    }
    arr[i+1] = key; // 3t(n)
  }
  return arr; //t
}
/*
Complexidade de Tempo

Cálculo: t + 3t(n) + 2t(n) + 2t(n) + 4t(n²) + 4t(n²) + 2t(n²) + 3t(n) + t
Resultado: 10t(n²) + 10t(n) + 2t
*/

void print_array(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
}

int main(void) {
  int A[] = {10, 21, 5, 12, 6};
  print_array(insertion_sort(A, 5), 5);
  
}
