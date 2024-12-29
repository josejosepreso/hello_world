#!/usr/bin/sh

source="node.c singlyLinkedList.c treeNode.c binaryTree.c main.c"

gcc -o main $source && ./main
