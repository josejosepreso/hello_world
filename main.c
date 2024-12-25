#include "singlyLinkedList.h"
#include "node.h"
#include <stdio.h>

int main(void)
{
  SinglyLinkedList *list = newList();

  addLast(list, newNode(111));
  addLast(list, newNode(222));
  addLast(list, newNode(666));

  addFirst(list, newNode(4));

  addAt(list, newNode(13), 2);

  print(list);

  Node *node = getAt(list, 3);

  printf("%d", node->val);
  
  return 0;
}
