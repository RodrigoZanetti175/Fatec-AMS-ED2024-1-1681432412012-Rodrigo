/*-----------------------------------------------------------*/
/*       FATEC-São Caetano do Sul Estrutura de Dados         */
/*                      Avaliação N2                         */
/*       Objetivo: Fazer Gerenciamento de tarefas            */
/*       Paradigma: Programação Modular                      */
/*                                                           */
/* Autores:Ágata, Breno, Enzo, Rodrigo Z, Vinicius e Vicente */
/*                                        Data:02/04/2024    */
/*-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "structs.h"
#include "tarefa.h"

int id = 1;

int main(void) {
  
  TAREFA *tarefa = criar();
  FILA *fila = criar_fila(); 

  int idp;
  int ids;
  int opt;

  char titulo[50];
  
  while (opt != 0) {
    printf("=======================================\n");
    printf("Menu - Gerenciador de Tarefas\n\n");
  
    printf("[1] Adicionar Tarefa\n");
    printf("[2] Listar Tarefas\n");
    printf("[3] Editar Tarefa\n");
    printf("[4] Excluir Tarefa\n");
    printf("[5] Concluir tarefa\n");
    printf("[6] Exibir tarefas concluídas\n");
    printf("[0] Sair\n\n");
    printf("R: ");
    scanf("%d", &opt);
    printf("---------------------------------------\n");
    
    switch (opt) {
    case 1:
      tarefa = addTarefa(tarefa, id);
      id++;
      break;

    case 2:
      printf("[0] Listar todas as tarefas\n");
      printf("[1] Listar por pessoa\n");
      printf("R: ");
      scanf("%d", &idp);
      if(idp>0)
      {
        printf("Digite o id da pessoa: \n");
        printf("[1] Bruna\n");
        printf("[2] Carla\n");
        printf("[3] Joao\n");
        printf("R: ");
        scanf("%d", &idp);
      } 
      // 0 -> lista todas as tarefas
      listTarefa(tarefa, idp);
      break;
      
    case 3:
      if(!listTarefa(tarefa, 0))
        break;
      printf("Insira o ID da tarefa que deseja editar:\n");
      printf("R: ");
      scanf("%d", &ids);
      editTarefa(tarefa, ids);
      break;

    case 4:

      if(!listTarefa(tarefa, 0))
        break;

      printf("Insira o ID da tarefa que deseja excluir: \n");
      printf("R: ");
      scanf("%d", &ids);
      
      tarefa = deleteTarefa(tarefa, ids);
      break;

    case 5:
      if(!listTarefa(tarefa, 0))
        break;
      printf("Insira o ID da tarefa que deseja concluir:\n");
      printf("R: ");
      scanf("%d", &ids);

      tarefa = concluirTarefa(tarefa, fila, ids);
      
      break;

    case 6:
      printf("[0] Listar todas as tarefas concluídas\n");
      printf("[1] Listar por pessoa\n");
      printf("R: ");
      scanf("%d", &idp);
      if(idp>0)
      {
        printf("Digite o id da pessoa: \n");
        printf("[1] Bruna\n");
        printf("[2] Carla\n");
        printf("[3] Joao\n");
        printf("R: ");
        scanf("%d", &idp);
      } 
      listarConcluidas(fila, idp);
      break;

    case 0:
      printf("Saindo...\n");
      opt = 0;
      exit(0);
      break;
    }    
  }
}