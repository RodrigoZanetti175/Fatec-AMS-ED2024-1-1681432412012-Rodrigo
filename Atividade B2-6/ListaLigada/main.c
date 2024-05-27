#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
  int num;
  struct node *next;
} Node;

Node * init(){
  Node *head = (Node *)malloc(sizeof(Node));
  head->next = NULL;
  return head;
}
Node * insert(Node *head, int num){
  Node *current = head;
  while(current->next != NULL && num >= current->next->num){
    current = current->next;
  }
  if(current->num == NULL)
  {
    current->num = num;
    return head;
  }
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->num = num;
  newNode->next = NULL;
  if(current->next == NULL)
  {
    current->next = newNode;
    return head;
  }
  newNode->next = current->next;
  current->next = newNode;
  return head;
}

void print(Node *head)
{
  
  while(head->next != NULL)
    {
      printf(" %d ", head->num);
      head = head->next;
    }
    printf(" %d ", head->num);
}

int main(void){
  clock_t start_time, end_time;
  start_time = clock();

  Node *head = init();
  head = insert(head, 10);
  head = insert(head, 25);
  head = insert(head, 40);
  head = insert(head, 80);
  head = insert(head, 30);
  
  print(head);
  
  
  end_time = clock();
  double runtime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("\nTempo de Execução: %f segundos\n", runtime);
  
}