#ifndef NODE_H

#define NODE_H

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node *newNode(int);

#endif
