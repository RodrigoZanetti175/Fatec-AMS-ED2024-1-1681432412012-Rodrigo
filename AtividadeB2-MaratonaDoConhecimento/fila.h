#ifndef FILA_H_ 
#define FILA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"
#include "structs.h"
#include "color.h"

FILA *criar_fila(){
  FILA *fila = (FILA*)malloc(sizeof(FILA));
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void listarConcluidas(FILA *fila, int pessoa){

        if(fila->inicio == NULL){
        printf("Nenhuma tarefa foi concluida\n");
        }      
        else{
        TAREFA *temp = fila->inicio;
          printf("%d", fila->inicio->id);
          listTarefa(temp, pessoa);
        }
}

TAREFA * concluirTarefa(TAREFA* tarefa, FILA *fila, int id){

  TAREFA * temp = tarefa;

  TAREFA * tarefaConcluida = (TAREFA*) malloc(sizeof(TAREFA));

  tarefaConcluida -> id = temp -> id;
  tarefaConcluida -> idP = temp -> idP;
  strcpy(tarefaConcluida -> titulo, temp -> titulo);
  strcpy(tarefaConcluida -> descricao, temp -> descricao);
  tarefaConcluida -> prazo = temp -> prazo;
  tarefaConcluida -> status = temp -> status;
  tarefaConcluida -> prio = temp -> prio;
  tarefaConcluida -> next = NULL;

  if(fila->fim != NULL) 
    fila->fim->next = tarefaConcluida;
  else 
    fila->inicio = tarefaConcluida;

  fila->fim = tarefaConcluida;

  tarefa = deleteTarefa(tarefa, id);

  return tarefa;
} 

#endif // FILA_H_


