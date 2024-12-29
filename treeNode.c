#include <stdlib.h>
#include "treeNode.h"

TreeNode *newTreeNode(int val)
{
  TreeNode *node = malloc(sizeof(TreeNode *));

  node->val = val;
  node->rightChild = NULL;
  node->leftChild = NULL;

  return node;
}
