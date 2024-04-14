// ----------------------------------- //
// Dado 14                             //
// Autores: Jorge e Rodrigo Z          //
// Instituição: Fatec Antonio Russo    //
// Professor: Carlos Veríssimo         //
// Data: 12/04/2024                    //
// ----------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

Pacote * Inserir(Pacote *pacote){
  Pacote *novo = (Pacote *)malloc(sizeof(Pacote));
  char CidOrig[50];
  char CidDest[50];
  char Conteudo[50];
  novo->id = (pacote->id)+2;
  
  printf("Digite a Cidade de Origem: ");
  scanf("%s" , CidOrig);
  strcpy(novo->CidOrig,CidOrig);
  
  printf("\nDigite a Cidade de Destino: ");
  scanf("%s" , CidDest);
  strcpy(novo->CidDest,CidDest);
  
  printf("\nDigite o Conteúdo: ");
  scanf("%s" , Conteudo);
  strcpy(novo->Conteudo,Conteudo);

  printf("\nDigite o Status: ");
  scanf("%i", &novo->Status);

  novo->next = pacote;

  return novo;
} 

Pacote * Pesquisar(Pacote *head){
  
  int id;

  
  printf("\nDigite o ID do pacote: ");
  
  scanf("%d", &id);
  
  for(Pacote *current = head; current != NULL; current = current->next){
    if(current->id == id)
    {
      
      return current;
    }
  }
  
  return NULL;
} 
void Rastrear(Pacote *head){
  Pacote *pacote;
  pacote = Pesquisar(head);
  
  char statusShow[50];
  
  if(pacote->Status == 99)
  {
    strcpy(statusShow, "Extraviado");
  }
  else{
    const char *translations[] = {"em processamento", "em transito", "em espera", "entregue"};
    strcpy(statusShow, translations[(pacote->Status)-1]);
    printf("%s", statusShow);
  }
  printf("\nConteúdo: %s", pacote->Conteudo);
  printf("\nStatus: %s", statusShow);
  printf("\n");
}
void Listar(Pacote *head){
  for(Pacote *current = head; current != NULL; current = current->next){
    char statusShow[50];
    if(current->Status == 99)
    {
      strcpy(statusShow, "Extraviado");
    }
    else{
      const char *translations[] = {"em processamento", "em transito", "em espera", "entregue"};
      strcpy(statusShow, translations[(current->Status)-1]);
    }
    printf("\nConteúdo: %s", current->Conteudo);
    printf("\nStatus: %s", statusShow);
    printf("\n");
  }
}
void Alterar(Pacote *head){
  Pacote *pacote;
  int status;
  pacote = Pesquisar(head);
  printf("\nDigite o novo status: ");
  scanf("%i", &status);
  if(status != 1 && status != 2 && status != 3 && status != 4 && status != 99){
    printf("\nStatus inválido");
  }
  else{
    pacote->Status = status;
  }
}

int main(void) {

  int input = 5;

  Pacote *pacote = (Pacote *)malloc(sizeof(Pacote));
  pacote->id = 0;

  while(input != 0){
    printf("1 - Cadastrar pacote\n");
    printf("2 - Alterar pacote\n");
    printf("3 - Rastrear pacote\n");
    printf("4 - Listar pacotes\n");
    printf("0 - Sair\n");
    scanf("%i", &input);
    switch(input){
    case 1:
        pacote = Inserir(pacote);
        break;
    case 2:
        Alterar(pacote);
        break;
    case 3:
        Rastrear(pacote);
        break;
    case 4:
        Listar(pacote);
        break;
    case 0:
        break;
    }
  }
  
}