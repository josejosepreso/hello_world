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

  if(newNode->val < current->val)
    return addNode(tree, newNode, current->leftChild, current);

  return addNode(tree, newNode, current->rightChild, current);
}

int add(BinaryTree *tree, TreeNode *node)
{
  if(isTreeEmpty(tree)) {
    tree->root = node;
    return 1;
  }

  TreeNode *root = tree->root;

  return addNode(tree, node, root, NULL);
}

void printTreeNodes(BinaryTree *tree, TreeNode *current, int depth)
{
  if(current == NULL)
    return;

  for(int i = 0; i < depth; i++)
    printf("\t");
  printf("%d\n", current->val);

  depth++;

  printTreeNodes(tree, current->rightChild, depth);
  printTreeNodes(tree, current->leftChild, depth);
}

void printTree(BinaryTree *tree)
{
  if(isTreeEmpty(tree))
    return;

  printTreeNodes(tree, tree->root, 0);
}

void amountOfNodes(BinaryTree *tree, TreeNode *current, int *x)
{
    if(current == NULL)
	return;

    *x += 1;

    amountOfNodes(tree, current->leftChild, x);
    amountOfNodes(tree, current->rightChild, x);
}

void printLevels(BinaryTree *tree)
{
    if(isTreeEmpty(tree))
	return;

    int number = 0;
    amountOfNodes(tree, tree->root, &number);

    TreeNode *nodes[number];
    int front = 0, rear = 0;
    nodes[rear++] = tree->root;

    int levelSize = rear - front;

    while(levelSize > 0) {
	TreeNode *current;

	for(int i = 0; i < levelSize; i++) {
	    current = nodes[front++];

	    printf("%d", current->val);

	    TreeNode *right = current->rightChild;
	    TreeNode *left = current->leftChild;

	    if(left != NULL)
		nodes[rear++] = left;
	    if(right != NULL)
		nodes[rear++] = right;

	    free(current);
	}

	levelSize = rear - front;

	printf("\n");
    }
}
