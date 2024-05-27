#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * insert(int *arr, int len, int n)
{
  int *arr2 = (int *)malloc((len + 1) * sizeof(int));

  for (int i = 0; i < len; i++)
    arr2[i] = arr[i];

  int i = 0;
  while (arr2[i] < n && i<len){
    i++;
  }
    
  for (int j = len; j > i; j--)
    arr2[j] = arr2[j - 1];

  arr2[i] = n;
  
  return arr2;
}

int main(void)
{
  clock_t start_time, end_time;

  start_time = clock();
  
  int arr[4] = {10, 25, 40, 80};
  int num = 30;
  int *array;

  array = insert(arr, 4, num);

  for (int i = 0; i < 5; i++)
    printf(" %d", array[i]);

  free(array); 
  
  end_time = clock();

  double runtime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  printf("\nTempo de Execução: %f segundos\n", runtime);
}