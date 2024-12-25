#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "singlyLinkedList.h"
#include "node.h"

SinglyLinkedList *newList()
{
  SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList *));
  
  list->head = NULL;
  list->size = 0;

  return list;
}

int isEmpty(SinglyLinkedList *list)
{
  return list->head == NULL ? 1 : 0;
}

int addFirst(SinglyLinkedList *list, Node *node)
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

int addLast(SinglyLinkedList *list, Node *node)
{
  if(isEmpty(list))
    return addFirst(list, node);
  
  struct Node *current = list->head;

  while(current->next != NULL)
    current = current->next;

  current->next = node;

  list->size++;
  
  return 1;
}

int addAt(SinglyLinkedList *list, Node *node, int index)
{
  if(index == 0)
    return addFirst(list, node);

  if(index == list->size)
    return addLast(list, node);

  struct Node *current = list->head;

  for(int i = 0; i < index - 1; i++)
    current = current->next;

  struct Node *next = current->next;

  current->next = node;
  node->next = next;

  return 1;
}

Node *getFirst(SinglyLinkedList *list) {
  return list->head;
}

Node *getAt(SinglyLinkedList *list, int index)
{
  if(isEmpty(list) || index >= list->size)
    return NULL;

  if(index == 0)
    return getFirst(list);

  struct Node *current = getFirst(list);
  
  for(int i = 0; i < index; i++)
    current = current->next;

  return current;
}

void print(SinglyLinkedList *list)
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
