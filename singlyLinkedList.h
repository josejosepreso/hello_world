#include "node.h"

#ifndef SINGLYLINKEDLIST_H

#define SINGLYLINKEDLIST_H

typedef struct SinglyLinkedList {
  Node *head;
  int size;
} SinglyLinkedList;

int isEmpty(SinglyLinkedList*);

int addFirst(SinglyLinkedList*, Node*);

int addLast(SinglyLinkedList*, Node*);

int addAt(SinglyLinkedList*, Node*, int);

Node *getAt(SinglyLinkedList*, int);

void print(SinglyLinkedList*);

#endif
