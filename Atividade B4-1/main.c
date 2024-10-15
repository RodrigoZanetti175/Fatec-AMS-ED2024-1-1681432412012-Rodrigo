// ------------------------------------ //
// Bubble Sort                          //
//                                      //
// Autores: Rodrigo Zanetti e Vicente   //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Paradigma: Programação Modular       //
// Data: 14/10/2024                     //
// ------------------------------------ //
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    int arr[tamanho];
    for(int i = 0; i < tamanho; i++){
      printf("Digite o valor %dº: ", i+1);
      scanf("%d", &arr[i]);
    }
    printf("Array original: \n");
    printArray(arr, tamanho);
    bubbleSort(arr, tamanho);
    printf("Array ordenado: \n");
    printArray(arr, tamanho);
    return 0;
}