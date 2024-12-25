#include "singlyLinkedList.h"
#include "node.h"
#include <stddef.h>

#include <stdio.h>

int main(void)
{
  SinglyLinkedList list = { .head = NULL, .size = 0 };

  addLast(&list, &(Node){ .val = 111, .next = NULL });
  addLast(&list, &(Node){ .val = 222, .next = NULL });
  addLast(&list, &(Node){ .val = 666, .next = NULL });

  addFirst(&list, &(Node){ .val = 4, .next = NULL });

  addAt(&list, &(Node){ .val = 13, .next = NULL }, 2);

  print(&list);

  Node *node = getAt(&list, 3);

  printf("%d", node->val);
  
  return 0;
}
