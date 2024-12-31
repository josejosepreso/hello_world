#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode {
    int val;
    struct TreeNode *rightChild;
    struct TreeNode *leftChild;
} TreeNode;

TreeNode *newTreeNode();

#endif
