#include <stdio.h>
#include <stddef.h>
#include "singlyLinkedList.h"
#include "node.h"

int isEmpty(struct SinglyLinkedList *list)
{
  if(list->head == NULL)
    return 1;

  return 0;
}

int addFirst(struct SinglyLinkedList *list, struct Node *node)
{
  list->size++;
  
  if(isEmpty(list)) {
    list->head = node;
    return 1;
  }
  
  struct Node *head = list->head;

  node->next = head;
  list->head = node;
  
  return 1;
}

int addLast(struct SinglyLinkedList *list, struct Node *node)
{
  if(isEmpty(list)) {
    return addFirst(list, node);
  }
  
  struct Node *current = list->head;

  while(current->next != NULL) {

    current = current->next;
  }

  current->next = node;

  list->size++;
  
  return 1;
}

int addAt(struct SinglyLinkedList *list, struct Node *node, int index)
{
  if(index == 0)
    return addFirst(list, node);

  if(index == list->size)
    return addLast(list, node);

  struct Node *current = list->head;

  for(int i = 0; i < index - 1; i++) {
    current = current->next;
  }

  struct Node *next = current->next;

  current->next = node;
  node->next = next;

  return 1;
}

struct Node *getFirst(struct SinglyLinkedList *list) {
  return list->head;
}

struct Node *getAt(struct SinglyLinkedList *list, int index)
{
  if(isEmpty(list) || index >= list->size)
    return NULL;

  if(index == 0)
    return getFirst(list);

  struct Node *current = getFirst(list);
  
  for(int i = 0; i < index; i++)
    current = current->next;

  return current;
  
  return 0;
}

void print(struct SinglyLinkedList *list)
{
  if(isEmpty(list))
    return;
  
  struct Node *current = list->head;

  printf("[");
  while(current != NULL) {
    printf("%d", current->val);

    if(current->next != NULL)
      printf(", ");
    
    current = current->next;
  }
  printf("]\n");
}
