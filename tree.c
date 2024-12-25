#include <stddef.h>
#include <stdio.h>
#include "tree.h"
#include "treeNode.h"
#include "singlyLinkedList.h"
#include "node.h"

void printTreeNodes(struct Tree *tree, struct TreeNode *treeNode)
{
  if(treeNode->children == NULL)
    return;

  struct SinglyLinkedList *children = treeNode->children;
  struct Node *current = children->head;

  while(current != NULL) {
    printf("%d ", current->val);
    
    current = current->next;

    // printTreeNodes(tree, current);
  }
}

void printTree(struct Tree *tree)
{
  struct TreeNode *root = tree->root;

  printTreeNodes(tree, root);
}
