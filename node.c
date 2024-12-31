#include "node.h"
#include <stdlib.h>

Node *newNode(int val)
{
    Node *node = malloc(sizeof(Node *));

    node->val = val;
    node->next = NULL;

    return node;
}
