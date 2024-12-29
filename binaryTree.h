#include "treeNode.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BinaryTree {
  TreeNode *root;
} BinaryTree;

BinaryTree *newTree();

int add(BinaryTree *, TreeNode *);

void printTree(BinaryTree *);

#endif
