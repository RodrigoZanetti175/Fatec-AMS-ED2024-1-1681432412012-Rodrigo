#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacote {
  int id;
  char *CidOrig[50];
  char *CidDest[50];
  char *Conteudo[50];
  int Status;
  struct pacote *next;
};

typedef struct pacote Pacote;

#endif /*TYPE_H*/