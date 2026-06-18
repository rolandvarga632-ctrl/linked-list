#ifndef LLIST_H
#define LLIST_H
#include<stddef.h>


typedef struct Node Node;
typedef struct List List;

struct Node {
	void *data;
	Node *next;
	Node *prev;
};

struct List {
	Node *head;
	Node *tail;
	size_t size;
};

void Init_Linked_List(List *list);
void list_push(List *list, void *a);
void freenodes(List *list);
//void print_list(List *list);
#endif
