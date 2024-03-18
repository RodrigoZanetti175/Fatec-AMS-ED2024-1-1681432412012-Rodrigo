/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                       Data:17/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>

int sort(int *ptrNotas){
  int k;

  int it = 0;
  int j = 0;
  int temp;

  while(j<4){
    it++;
    if((ptrNotas[j]) > (ptrNotas[j+1])){
      temp = (ptrNotas[j]);
      (ptrNotas[j]) = (ptrNotas[j+1]);
      (ptrNotas[j+1]) = temp;
    }
    j++;
    int count=0;
    for(k = 0; k < 4; k++){
      if((ptrNotas[k]) <= (ptrNotas[k+1])){
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
  return 0;
}

int multiplicaElementos(*ptrNotas)
{
  int i;
  int input;
  
  
  for (i = 0; i < 5; i++){
    printf("Digite o número para multiplicar o %dº elemento do vetor (%d) \n", (i+1), ptrNotas[i]);
    scanf("%d", &input);

    (ptrNotas[i]) = (ptrNotas[i]) * input;
  }
  return 0; 
}

int main(void){
  int Notas[5];
  int i;
  int m;

  for(i = 0; i < 5; i++){
    printf("Insira um número");
    scanf("%d", &Notas[i]);
  }

  sort(&Notas);
  
  multiplicaElementos(&Notas);

  printf("[");
  for (m = 0; m < 5; m++){
    printf("%d ", Notas[m]);
  }
  printf("] \n");;

}