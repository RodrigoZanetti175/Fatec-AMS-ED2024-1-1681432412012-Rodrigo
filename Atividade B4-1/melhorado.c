// ------------------------------------ //
// Bubble Sort Melhorado                //
//                                      //
// Autores: Rodrigo Zanetti e Vicente   //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Paradigma: Programação Modular       //
// Data: 14/10/2024                     //
// ------------------------------------ //
#include <stdio.h>

// Melhoria: Função trocar()
void trocar(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    //Melhoria: flag para verificar se houve trocas
    int troca = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
                troca = 1;
            }
        }
        //Melhoria: Se não houve trocas, o array já está ordenado
        if (!troca){
            break;
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