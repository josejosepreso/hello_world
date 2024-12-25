#ifndef SINGLYLINKEDLIST_H

#define SINGLYLINKEDLIST_H

struct SinglyLinkedList {
  struct Node *head;
  int size;
};

int isEmpty(struct SinglyLinkedList*);

int addFirst(struct SinglyLinkedList*, struct Node*);

int addLast(struct SinglyLinkedList*, struct Node*);

int addAt(struct SinglyLinkedList*, struct Node*, int);

struct Node *getAt(struct SinglyLinkedList*, int);

void print(struct SinglyLinkedList*);

#endif
