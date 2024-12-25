#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
  struct Node *node;
  struct SinglyLinkedList *children;
  int depth;
};

#endif
