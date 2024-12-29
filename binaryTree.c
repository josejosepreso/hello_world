#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "treeNode.h"

BinaryTree *newTree()
{
  BinaryTree *tree = malloc(sizeof(BinaryTree *));

  tree->root = NULL;

  return tree;
}

int isTreeEmpty(BinaryTree *tree)
{
  return tree->root == NULL ? 1 : 0;
}

TreeNode *getRoot(BinaryTree *tree)
{
  return tree->root;
}

int addNode(BinaryTree *tree, TreeNode *newNode, TreeNode *current, TreeNode *parentNode)
{
  if(current == NULL) {
    if(newNode->val == parentNode->val)
      return 0;

    if(newNode->val < parentNode->val) {
      parentNode->leftChild = newNode;
      return 1;
    }

    parentNode->rightChild = newNode;
    return 1;
  }

  newNode->depth++;

  if(newNode->val < current->val)
    return addNode(tree, newNode, current->leftChild, current);

  return addNode(tree, newNode, current->rightChild, current);
}

int add(BinaryTree *tree, TreeNode *node)
{
  if(isTreeEmpty(tree)) {
    node->depth = 0;
    tree->root = node;
    return 1;
  }

  TreeNode *root = tree->root;

  return addNode(tree, node, root, NULL);
}

void printTreeNodes(BinaryTree *tree, TreeNode *current)
{
  if(current == NULL)
    return;

  for(int i = 0; i < current->depth; i++)
    printf("\t");
  printf("%d\n", current->val);

  printTreeNodes(tree, current->rightChild);
  printTreeNodes(tree, current->leftChild);
}

void printTree(BinaryTree *tree)
{
  if(isTreeEmpty(tree))
    return;

  printTreeNodes(tree, tree->root);
}
