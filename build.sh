#!/usr/bin/sh

source="singlyLinkedList.c tree.c main.c"

gcc -o main $source && ./main
