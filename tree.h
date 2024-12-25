#include "treeNode.h"

#ifndef TREE_H
#define TREE_H

struct Tree {
  struct TreeNode *root;
};

void printTreeNodes(struct Tree*, struct TreeNode*);

void printTree(struct Tree*);

#endif
