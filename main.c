#include <stdio.h>

int main() {
  int R[5];
  int i;
  int k;
  int m;
  int it = 0;
  int j = 0;
  int temp;

  for(i = 0; i < 5; i++){
    printf("Insira um número");
    scanf("%d", &R[i]);
  }
  while(j<4){
    it++;
    if(R[j] > R[j+1]){
      temp = R[j];
      R[j] = R[j+1];
      R[j+1] = temp;
    }
    j++;
    int count=0;
    for(k = 0; k < 4; k++){
      if(R[k] <= R[k+1]){
        count++;
      }
    }
    if(count == 4){
      break;
    }
    else if(it == 4){
      j = 0;
      it = 0;
    }
  }
  printf("[");
  for(m = 0; m < 5; m++){
    printf("%d ", R[m]);
  }
  printf("]");
}