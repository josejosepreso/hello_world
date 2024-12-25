#include "singlyLinkedList.h"
#include "node.h"
#include <stddef.h>

#include <stdio.h>

int main(void)
{
  struct SinglyLinkedList list = { .head = NULL, .size = 0 };

  struct Node node1 = { .val = 111, .next = NULL };
  struct Node node2 = { .val = 222, .next = NULL };
  struct Node node3 = { .val = 666, .next = NULL };

  addLast(&list, &node1);
  addLast(&list, &node2);
  addLast(&list, &node3);

  struct Node node4 = { .val = 4, .next = NULL };

  addFirst(&list, &node4);

  struct Node node5 = { .val = 13, .next = NULL };

  addAt(&list, &node5, 2);

  // Print
  print(&list);

  struct Node *node = getAt(&list, 2);

  printf("%d", node->val);
  
  return 0;
}
