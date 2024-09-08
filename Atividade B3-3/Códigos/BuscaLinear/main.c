// ------------------------------------ //
// Busca Linear                         //
//                                      //
// Autores: Rodrigo Zanetti             //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Paradigma: Programação Modular       //
// Data: 08/09/2024                     //
// ------------------------------------ //
#include <stdio.h>

int linear_search(int * arr, int target, int length){
    int i = 0 //t
    while(i <= length) //tn
    {
        if(arr[i] == target) //2tn
            return i; //t
        i++; //tn
    }
    return -1; //t
}

int main(void) {
  int array[] = {2,6,1,4,3,5}; //t
  int number = 7; //t
  printf("%d",linear_search(array,number,6)); //t + algoritmo
}