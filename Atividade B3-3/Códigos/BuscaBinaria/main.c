// ------------------------------------ //
// Busca Binária                        //
//                                      //
// Autores: Rodrigo Zanetti             //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Paradigma: Programação Modular       //
// Data: 08/09/2024                     //
// ------------------------------------ //
#include <stdio.h>
#include <math.h>

int binary_search(int * arr, int target, int length)
{
    int left = 0; //t
    int right = length-1; //2t

    while(left<=right) //t(log n)
    {
        int middle = floor((right+left)/2); // 4t(log n)
        if(target == arr[middle]) //2t(log n)
            return middle; //t 
        if(target > arr[middle]) //2t(log n)
            left = middle+1; //2t(log n)
        else
            right = middle-1; //2t(log n)
    }
    return -1; //t
}

int main(void) {
  int array[] = {1,2,3,4,5,6}; //t
  int number = 7; //t
  printf("%d",binary_search(array,number,6)); //t + algoritmo
}