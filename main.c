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

  printf("%d\n", node->val);

  removeAt(list, 2);

  print(list);

  addAt(list, newNode(-100), 3);

  print(list);
  
  return 0;
}
