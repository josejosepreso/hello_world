#!/usr/bin/sh

source="node.c singlyLinkedList.c tree.c main.c"

gcc -o main $source && ./main
