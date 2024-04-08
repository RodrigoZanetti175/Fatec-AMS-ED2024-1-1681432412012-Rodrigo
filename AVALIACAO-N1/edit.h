#ifndef EDIT_H
#define EDIT_H

#include <stdbool.h>
#include "search.h"

bool ll_edit(Node *head, char *name, float price, int qtd) {
  Product *match = ll_search(head);
  if (match == NULL) 
    return false;

  strcpy(*match->name, name);
  match->price = price;
  
  return true;
}

bool restock(Node *head, int qtd) {
  Product *match = ll_search(head);
  if (match == NULL) 
    return false;
  
  match->qtd += qtd;
  return true;
}

int buy(Node *head, int qtd)
{
  Product *match = ll_search(head);

  if(match->qtd - qtd < 0)
    return 0;
  
  match->qtd -= qtd;
  return 1;
}
#endif /* EDIT_H */