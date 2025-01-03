#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "singlyLinkedList.h"
#include "node.h"

SinglyLinkedList *newList()
{
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList *));
    
    list->head = NULL;
    list->size = 0;

    return list;
}

int isEmpty(SinglyLinkedList *list)
{
    return list->head == NULL ? 1 : 0;
}

int addFirst(SinglyLinkedList *list, Node *node)
{
    list->size += 1;
    
    if(isEmpty(list)) {
        list->head = node;
        return 1;
    }
    
    struct Node *head = list->head;

    node->next = head;
    list->head = node;
    
    return 1;
}

int addLast(SinglyLinkedList *list, Node *node)
{
    if(isEmpty(list))
        return addFirst(list, node);
    
    struct Node *current = list->head;

    while(current->next != NULL)
        current = current->next;

    current->next = node;

    list->size += 1;
    
    return 1;
}

int addAt(SinglyLinkedList *list, Node *node, int index)
{
    if(index < 0 || index > list->size)
        return -1;

    if(index == 0)
        return addFirst(list, node);

    if(index == list->size)
        return addLast(list, node);

    struct Node *current = list->head;

    for(int i = 0; i < index - 1; i++)
        current = current->next;

    struct Node *next = current->next;

    current->next = node;
    node->next = next;

    list->size += 1;

    return 1;
}

Node *getFirst(SinglyLinkedList *list) {
    return list->head;
}

Node *getAt(SinglyLinkedList *list, int index)
{
    if(isEmpty(list) || index >= list->size)
        return NULL;

    if(index == 0)
        return getFirst(list);

    struct Node *current = getFirst(list);
    
    for(int i = 0; i < index; i++)
        current = current->next;

    return current;
}

void removeFirst(SinglyLinkedList *list)
{
    if(isEmpty(list))
	return;

    Node *node = getFirst(list);

    list->head = NULL;

    if(list->size > 1)
	list->head = node->next;

    free(node);

    list->size -= 1;
}

void removeLast(SinglyLinkedList *list)
{
    if(isEmpty(list))
	return;

    if(list->size == 1) {
	removeFirst(list);
	return;
    }

    Node *current = getFirst(list);

    for(int i = 0; i < list->size - 2; i++)
	current = current->next;

    Node *node = current->next;
    free(node);

    current->next = NULL;

    list->size -= 1;
}

void removeAt(SinglyLinkedList *list, int index)
{
    if(index < 0 || index >= list->size)
        return;

    if(index == 0) {
	removeFirst(list);
	return;
    }

    if(index == list->size - 1) {
	removeLast(list);
	return;
    }

    Node *current = getFirst(list), *prev;

    for(int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    Node *next = current->next;

    prev->next = next;

    list->size -= 1;

    free(current);
}

void print(SinglyLinkedList *list)
{
    if(isEmpty(list)) {
	printf("[]\n");
        return;
    }
    
    struct Node *current = list->head;

    printf("[");
    while(current != NULL) {
        printf("%d", current->val);

        if(current->next != NULL)
            printf(", ");
        
        current = current->next;
    }
    printf("]\n");
}
