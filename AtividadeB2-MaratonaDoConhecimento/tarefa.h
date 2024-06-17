#ifndef TAREFA_H_ 
#define TAREFA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "color.h"

char *transform_prazo(int prazo) {
  char *prazo_str = (char *)malloc(6); 
  if (prazo_str == NULL) {
    return NULL; 
  }
  if (prazo < 1 || prazo > 1231) {
    free(prazo_str); 
    return NULL; 
  }

  int mes = prazo / 100; 
  int dia = prazo % 100;
  sprintf(prazo_str, "%02d/%02d", dia, mes); 
  return prazo_str; 
}

TAREFA *criar() {
  TAREFA *novo = (TAREFA*)malloc(sizeof(TAREFA));
  novo->next = NULL;
  novo->prio = 0;
  novo->prazo = 9999;
  return novo;
}

TAREFA *addTarefa(TAREFA *tarefa, int id) {
  char titulo[50];
  char descri[100];
  int prazo;
  int status;
  int prio;
  int pessoa;
  int idP;

  TAREFA *novo = tarefa;

  printf("Digite o titulo da tarefa: \n");
  printf("R: ");
  scanf("%s", titulo);

  printf("Digite a descrição da tarefa: \n");
  printf("R: ");
  scanf("%s", descri);

  printf("Digite o prazo da tarefa (mes/dia - Exemplo: 0815): \n");
  printf("R: ");
  scanf("%d", &prazo);

  printf("Digite a prioridade da tarefa: \n");
  printf("1-Normal: \n");
  printf("2-Mediana: \n");
  printf("3-Urgente: \n");
  printf("R: ");
  scanf("%d", &prio);
  
  printf("Pra quem você deseja atribuir a tarefa? \n");
  printf("[1] Bruna\n");
  printf("[2] Carla\n");
  printf("[3] Joao\n");
  printf("R: ");
  scanf("%d", &idP);



  //INSERÇÃO DOS DADOS DA TAREFA NA LISTA ORDENANDA
  TAREFA *newTarefa = (TAREFA *)malloc(sizeof(TAREFA));
  newTarefa->id = id;
  newTarefa->idP = idP;
  strcpy(newTarefa->titulo, titulo);
  strcpy(newTarefa->descricao, descri);
  newTarefa->prazo = prazo;
  newTarefa->status = 1;
  newTarefa->prio = prio;
  newTarefa->next = NULL;

  // CHECAGEM DE ORDEM DAS TAREFAS ATRIBUIDAS
  if(prio >= novo->prio && prazo <= novo->prazo)
  {
    if(novo->id!=0)
      newTarefa->next = novo;
    novo = newTarefa;
    return novo;
  }
  while(novo->next != NULL && prio <= novo->next->prio && prazo >= novo->next->prazo)
    novo = novo->next;

  if(novo->next == NULL)
  {
    novo->next = newTarefa;
    return tarefa;
  }
  newTarefa->next = novo->next;
  novo->next = newTarefa;
  return tarefa;
}

// LISTAGEM DA TAREFA

int listTarefa(TAREFA *tarefa, int pessoa) {
  TAREFA *temp = tarefa;
  if (temp->id == 0) {
    printf("\nNão há tarefas cadastradas\n");
    return 0;
  }
  do {
    if (temp->idP == pessoa || pessoa == 0)
    {
      if(temp == NULL)
        break;
      switch(temp->prio){
        case 1: 
          printf(GREEN);printf("\nTarefa %d: %s", temp->id, temp->titulo);printf(RESET);
          break;
        case 2:
          printf(YELLOW);printf("\nTarefa %d: %s", temp->id, temp->titulo);printf(RESET);
          break;
        case 3:
          printf(RED);printf("\nTarefa %d: %s", temp->id, temp->titulo);printf(RESET);
          break;
      }
    printf("\nDescrição: %s", temp->descricao);
    char *prazo_str = transform_prazo(temp->prazo);
    printf("\nPrazo: %s", prazo_str); 
    printf("\nResponsável: ");
    switch(temp->idP)
      {
        case 1:
          printf("Bruna\n");
        break;
        case 2:
          printf("Carla\n");
        break;
        case 3:
          printf("Joao\n");
        break;
      }

    }
    temp = temp->next;
  } 
  while(temp != NULL);

  return 1;
}

// EDITAR AS INFORMAÇÕES DA TAREFA
void editTarefa(TAREFA *tarefa, int ID) {

  if(tarefa->id == 0)
  {
    printf("Não há tarefas cadastradas\n");
    return;
  }

  while(tarefa != NULL && tarefa->id != ID){
    tarefa = tarefa->next;
  }

  if(tarefa == NULL)
  {
    printf("Tarefa não encontrada");
    return;
  }
    int opc = -1;

      printf("O que deseja editar? \n 1 - Título \n 2 - Descrição \n 3 - Prazo\n");
      scanf("%d", &opc);

      switch (opc) {
      case 1:
        printf("Digite o novo título: \n");
        printf("R: ");
        scanf("%s", tarefa->titulo);
        break;
      case 2:
        printf("Digite a nova descrição: \n");
        printf("R: ");
        scanf("%s", tarefa->descricao);
        break;
      case 3:
        printf("Digite o novo prazo: \n");
        printf("R: ");
        scanf("%d", &tarefa->prazo);
        break;
      }

  return;
}

TAREFA * deleteTarefa(TAREFA *tarefa, int id) {
  TAREFA *temp = tarefa;
  TAREFA *ant;

  if (temp == NULL) {
    printf("Não existem mais tarefas");
    return tarefa;
  }

  if(temp->id == id)
  {
    if(temp->next == NULL){
      free(temp);
      tarefa = criar();
      tarefa->id = 0;
    }
    else{
      tarefa = temp->next;
      free(temp);
    }
    return tarefa;
  }

    while (temp->id != id) {
      ant = temp;
      temp = temp->next;
    }

    if(temp->id != id)
    {
      printf("Tarefa não encontrada");
      return tarefa;
    }

    ant->next = temp->next;

    free(temp);

    return tarefa;

}

#endif // TAREFA_H_