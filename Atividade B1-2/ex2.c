#include <stdio.h>

float descontar(float *ptr, float desconto)
{
  return *ptr - (*ptr * (desconto/100));
}

int main(){
    float produto;
    float desc;
  
    printf("Insira o valor do produto: ");
    scanf("%f", &produto);
  
    printf("Insira a porcentagem do desconto: ");
    scanf("%f", &desc);

    float resultado = descontar(&produto, desc);

    printf("Valor do produto sem desconto: %.2f \n", produto);
    printf("Valor descontado: %.2f \n", produto * (desc/100));
    printf("Valor do produto com desconto: %.2f \n", resultado);
    
}