#ifndef STRUCTS_H_ 
#define STRUCTS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa {
  int id;
  char titulo[50];
  char descricao[100];
  int prazo;
  int status;
  int prio;
  int idP;
  struct Tarefa *next;
} TAREFA;

typedef struct fila{
  TAREFA *inicio;
  TAREFA *fim;
}FILA;

#endif // STRUCTS_H_
