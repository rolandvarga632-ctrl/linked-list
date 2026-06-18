#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void Init_Linked_List(List *list) {

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}


void list_push(List *list, void *a) {
	
	Node *node = malloc(sizeof(Node));
	node->data = a;
	node->next = NULL;


	if (!list->head && !list->tail)
	{
		node->prev = NULL;

		list->head = node;
		list->tail = node;
		list->size = 1;		
	} else {
		
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
		list->size+=1;

	}
}

void freenodes(List *list) {
	Node *current = list->head;
	Node *next_node;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

//void print_list(List *list) {
//
//	Node *current = list->head;
//	Node *next_node;
//	while (current)
//	{
//		next_node = current->next;
//		printf("%d\n",(int)(intptr_t)current->data);
//		current = next_node;
//	}
//}
