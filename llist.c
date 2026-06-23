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
		list->size++;		
	} else {
		
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
		list->size++;

	}
}

void freenodes(List *list) {
	Node *current = list->head;
	Node *next_node;
	
	if (current)
	{	
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	} else {
		return;
	}
}



void* list_pop(List *list, int index) {
	
	Node *current = list->head;
	Node *next_node;
	Node *prev_node;
	void *data = current->data;
	
	if (current == NULL) return NULL;
	if (index+1 > (int)list->size || index < 0) return NULL;

	if (index == 0)
	{
		if (list->size == 1)
		{
			list->head = NULL;
			list->tail = NULL;
		}
		else
		{
			next_node = current->next;
			next_node->prev = NULL;
			list->head = next_node;
			
			
		}

		free(current);
		list->size--;
		return data;
		

	}
	else
	{
		if ((int)list->size == index+1)
		{	
			current = list->tail;
			data = current->data;
			prev_node = current->prev;
			prev_node->next = NULL;
			list->tail = prev_node;
			free(current);
			list->size--;
			return data;

			
		}
		else
		{	
			
			for (int i = 0; i <= index; i++)
			{
				if (i == index)
				{
					data = current->data;	
					next_node = current->next;
					prev_node = current->prev;
					prev_node->next = next_node;
					next_node->prev = prev_node;
					next_node = NULL;
					prev_node = NULL;
					list->size--;
					free(current);
					return data;
				}
				next_node = current->next;
				prev_node = current->prev;
				current = next_node;
				

			}
		}
	}
	return NULL;
}


void print_list(List *list) {

	Node *current = list->head;
	Node *next_node;

	if (current == NULL) return;
	printf("first= %d, last= %d, size= %d\n",
		 (int)(intptr_t)current->data,
		 (int)(intptr_t)list->tail->data, 
		 (int)list->size);
	while (current)
	{
		next_node = current->next;
		printf("%d\n",(int)(intptr_t)current->data);
		current = next_node;
	}
}
